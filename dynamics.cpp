#include "dynamics.h"


dynamics::dynamics()
{
}


dynamics::~dynamics()
{
}



mat dynamics::rotationMatrix__X( double &theta) // UNTESTED 
{
	mat R(3, 3);
	R(1, 1) = 1; 

	R(2, 2) = std::cos(theta);
	R(2, 3) = - std::sin(theta);
	R(3, 2) = std::sin(theta);
	R(3, 3) = std::cos(theta);

	return R;
}

mat dynamics::rotationMatrix__Y(double &theta) // UNTESTED 
{
	mat R(3, 3);
	R(2, 2) = 1;

	R(1, 1) = std::cos(theta);
	R(1, 3) = std::sin(theta);
	R(3, 1) = - std::sin(theta);
	R(3, 3) = std::cos(theta);

	return R;
}

mat dynamics::rotationMatrix__Z(double &theta) // UNTESTED 
{
	mat R(3, 3);
	R(3, 3) = 1;

	R(1, 1) = std::cos(theta);
	R(1, 2) = -std::sin(theta);
	R(2, 1) = std::sin(theta);
	R(2, 2) = std::cos(theta);

	return R;
}


mat dynamics::eulerAngle__XYZ(double &theta)
{
	return rotationMatrix__X(theta) * rotationMatrix__Y(theta) * rotationMatrix__Z(theta); 
}

mat dynamics::eulerAngle__ZYX(double &theta)
{
	return rotationMatrix__Z(theta) * rotationMatrix__Y(theta) * rotationMatrix__X(theta);
}

mat dynamics::getAlphaBetaGamma_R(mat & R)
{
	mat angles(3,1);

	// BETA
	angles(2,1) = std::atan2(-R(3, 1), std::sqrt(R(1, 1) * R(1, 1) + R(2, 1) * R(2, 1)));
	if (cos(angles(2, 1)))
	{
		error(" AlphaBetaGamma_R -> Singularity");
	}

	return angles * 0;  // NOT IMPLEMENTED ; 
}

mat dynamics::inverse_rotationMatrix(mat &rot)
{
	la_pack la;
	return la.tranpose(rot);
}


mat dynamics::rotationMatrix_3D_Frame_B2A(mat &A, mat &B)
{
	mat R(3, 3); la_pack la; 
	for (int j = 1; j <= 3; j++)
	{
		for (int i = 1; i <= 3; i++)
		{
			mat colB = B.returnCol(j);
			mat colA = A.returnCol(i);
			R(i, j) = la.innerProduct(colB, colA);
		}
	}
	return R; 
}



mat dynamics::transform(mat &transMatrix, mat &vector)
{
	if (!transMatrix.isSquare() || !vector.isColVector())
	{
		error("transform -> !transMatrix.isSquare() || !vector.isColVector ");

		return vector * 0;
	}
	else
	{
		return transMatrix * vector;
	}
}


/*

Just used for conceptual understanding . 
Creates a 3 D column vector and stores the input in them 
*/
mat dynamics::point_3D(double x, double y, double z)
{
	mat R(3, 1);
	R(1, 1) = x; R(2, 1) = y; R(3, 1) = z; 
	return R; 
}


mat dynamics::getVector(mat & point1, mat & point2)
{
	return point2 - point1; 
}


mat dynamics::getOrthoXYZ_frame()
{
	mat cartesian(3, 3);
	 
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			if (i == j)
				cartesian(i, j) = 1;
			else
				cartesian(i, j) = 0;// REDUNDANT , USED FOR CLARITY
		}
	}
	return cartesian;
}


mat dynamics :: getFrame_3D(mat & axis1 , mat &axis2 , mat &axis3 )
{
	mat R(3, 3);

	for (int j = 1; j <= 3; j++)
	{
		for (int i = 1; i <= 3; i++) // Goes throught the Columns First 
		{
			switch (j)
			{
			case 1:
				R(i, j) = axis1(i, 1); break;
			case 2:
				R(i, j) = axis2(i, 1); break;
			case 3:
				R(i, j) = axis3(i, 1); break;
			default:
				error("-> getFrame_3D ");
				break;
			}
		}
	}
	return R; 
}





mat dynamics::componentOfVectorInFrame(mat &frame, mat &vec)
{
	mat R(3, 1); la_pack la;
		for (int i = 1; i <= 3; i++)
		{
			mat frameAxis = frame.returnCol(i);
			R(i, 1) = la.innerProduct(vec, frameAxis);
		}

	return R;
}




mat dynamics::generalTransfrom(mat & rotB2A, mat & pB, mat & pBorgA)
{
	return (rotB2A * pB) + pBorgA;
}



mat dynamics::homogenousTransformMatrix(mat & rotB2A,  mat& pBorgA)
{
	mat T(4, 4);
	mat R(3, 3);
	for (int j = 1; j <= 4; j++)
	{
		for (int i = 1; i <= 4; i++)
		{
			if (i <= 3 && j <= 3)
			{ 
				T(i, j) = rotB2A(i, j);
			}
			else if ( j == 4 && i <= 3)
			{
				T(i, j) = pBorgA(i, 1);
			}
			else if ( j == 4 && i == 4)
			{
				T(i, j) = 1; 
			}
			else
			{
				T(i, j) = 0; 
			}
		
		}
	}

	return T;
}


mat dynamics::inverse_homogeneousTransformMatrix(mat & T)
{
	mat rotB2A(3, 3), pBorg2A(3, 1); 

	for (int j = 1; j <= 4; j++)
	{
		for (int i = 1; i <= 4; i++)
		{
			if (i <= 3 && j <= 3)
			{
				rotB2A(i, j) = T(i,j);
			}
			else if (j == 4 && i <= 3)
			{
				pBorg2A(i, 1) = T(i, j);
			}
		}
	}
	mat rotA2B = la.tranpose(rotB2A);
	mat pAorg2B = (rotA2B * pBorg2A) * -1 ;
	
	return homogenousTransformMatrix(rotA2B , pAorg2B ); 
}



/*
	Appends 1 at the end of the col vector 
*/
mat dynamics::get_homogenousTransformPoint(mat & P)
{
	
	mat R(P.numRows() + 1, 1);
	for (int i = 1; i <= P.numRows(); i++)
		R(i, 1) = P(i, 1);

	R(P.numRows() + 1, 1) = 1; 
	return R; 
}


/*
	Get Orientation from homogenous Transform Matrix  
*/
mat dynamics::getOrientation_T(mat & T)
{
	mat R(3, 3);
	for (int j = 1; j <= 3; j++)
	{
		for (int i = 1; i <= 3; i++)
		{
			R(i, j) = T(i, j);
		}

	}
	return R;
}


mat dynamics::getPosition_T(mat & T)
{
	mat P(3, 1);
	for (int i = 1; i <= 4; i++)
	{
		P(i, 1) = T(i, 4);
	}
	return P;

}

/*
	Input 
	Homogenous Form T block matrix , containing Rotation Matrix and Point

	Homogenous Point

*/
mat dynamics::homogenousTransform( mat & T , mat & vec)
{
	return T *  vec; 
}













