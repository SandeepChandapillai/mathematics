#pragma once

#include "matrix.h"
#include "la_pack.h"
#include "common.h"


// VECTOR ==> COLUMN VECTOR 


//BEGIN APRIL 30 th

/*
To Do 
	Axis Angle 
	Euler Parameters
	Denevit Hartenberg Parameters



*/

class dynamics
{
public:
	dynamics();
	~dynamics();
	static void error(const char* p){ std::string str = "dynamics -> Error: "; std::cout << str << p << std::endl; }



	/*

	Give the rotation matrix for 3D 


	theta - Angle by which to turn in radians

	*/
	mat rotationMatrix__X(double &theta);
	mat rotationMatrix__Y(double &theta);
	mat rotationMatrix__Z(double &theta);


	mat eulerAngle__XYZ(double &theta);
	mat dynamics::eulerAngle__ZYX(double &theta);

	/*
	Returns a column vector containint Alpha Beta Gamma 
	*/
	mat dynamics::getAlphaBetaGamma_R(mat & R);


	mat inverse_rotationMatrix(mat &rot);
	/*
	Gives the Rotation from Vector B to vector A 
	
	More General than using theta . 
	
	*/
	mat dynamics::rotationMatrix_3D_Frame_B2A(mat &A, mat &B);

	/*

	Just used for conceptual understanding .
	Creates a 3 D column vector and stores the input in them
	*/
	mat dynamics::point_3D(double x, double y, double z);


	/*
		Pass in two points. 

		Pass in using the point_3D function. 
	
	
	*/
	mat dynamics::getVector(mat &point1, mat &point2);

	/*
	Returns a matrix with X Y Z vectors 

	Represented as Column Vector
	
	
	*/
	mat dynamics::getOrthoXYZ_frame();
	
	/*
	Create a frame.
	Input :
	Column Vectors representing axises 

	Output:
	3x3 Matrix representing frame;
	*/
	mat dynamics::getFrame_3D(mat &axis1, mat &axis2, mat &axis3);





	/*
	 Multiples vector by given vector and then returns new vector 
	
	// USED FOR CONCEPTUAL UNDERSTANDING
	*/
	mat dynamics::transform(mat &transMatrix, mat &vector);



	/*
	Gives components of given vector in the given frame 
	
	input Frame Matrix , Vector 
	*/
	mat dynamics::componentOfVectorInFrame(mat &frame, mat &vec);


	mat dynamics::generalTransfrom(mat & rotB2A, mat & pB, mat & pBorgA);


	mat dynamics::homogenousTransformMatrix(mat & rotB2A,  mat& pBorgA);


	mat dynamics::inverse_homogeneousTransformMatrix(mat & T);

	/*
	Appends 1 at the end of the col vector
	*/
	mat dynamics::get_homogenousTransformPoint(mat & P);


	/*
	Input
	Homogenous Form T block matrix , containing Rotation Matrix and Point

	Homogenous Point

	*/
	mat dynamics::homogenousTransform(mat & T, mat & vec);



	/*
	Get Orientation from homogenous Transform Matrix


	*/
	mat dynamics::getOrientation_T(mat & T);
	/*
	Get Positon From Homogenoeus Transformation Matrxi
	*/
	mat dynamics::getPosition_T(mat & T);

private:
	la_pack la;

};

