

// Used for testing Puropose. Project will be converted to a static lib later 


#include "testSuite.h"

// TESTING la_pack
int main(){


	//stringSet A = { "GG" }; stringSet B = { "GG", "GB" }; 
	//stringSet S = { "BB", "GG", "GB", "BG" }; 
	//S.print();
	//probability<std::string> P; 
	//std::cout <<  P.conditionalProbability(A, B,S);

	//probability<int> dice; 
	//std::cout << dice.getProbability({ 1 }, dice.DIE);
	


	//testSuite test; 
	//std::cout << "Pass Fail : " << test.runTestSuite() << endl;

	testSuite test;
	std::cout << "TEST : " << test.runTestSuite() << std::endl;

	return 0;
}


/*

TESTING setMath
setMath < string > outcome;
outcome.insert("head"); outcome.insert("tail");


setMath <string> outcome2;
outcome2.insert("meow");
outcome2.insert("head");

setMath <string> newOut = outcome.getUnion(outcome2);
newOut.print();

setMath <string> newOut2 = outcome.getIntersection(outcome2);
newOut2.print();

setMath <int > num({ 1, 2, 3, 4, 5, 6, 7 });
num.print();

//outcomes = { "head", "tail" };

*/




/*
int main(){

la_pack la;
analysis cl;


//std::cout << cl.intergalSimple(calculus::identity,0,1) << std::endl;
//std::cout << cl.intergalSimple([](double x) { return x*x; }, 0, 1) << std::endl;

/*
std::cout << cl.derivativeAverage([](double x) { return x*x*x - x - std::sin(x)*x ; }, 89) << std::endl;
std::cout << cl.derivativeForward([](double x) { return x*x*x + 100 - x - std::sin(x)*x; }, 89) << std::endl;
std::cout << cl.derivativeBacward([](double x) { return x*x*x - x - std::sin(x)*x; }, 89) << std::endl;
std::cout << cl.derivativeCenter([](double x) { return x*x*x - x - std::sin(x)*x; }, 89) << std::endl;
std::cout << cl.rootNewtonSingle([](double x) { return x*x-2; }) << std::endl;
cl.rootQuadratic(1, 0, -2).print();
std::cout << cl.eulerODE_1([](double x, double y) { return 3 *x  - 1000* y*y; }, 0.002,0,0);
//std::cout << cl.intergalSimple([](double x) { return x*x*x - x - std::sin(x)*x; }, 0, 100) << std::endl;
std::cout << cl.integralSimpson([](double x) { return x*x*x - x - std::sin(x)*x; }, 0, 100) << std::endl;
//std::cout << cl.integralSimpsonMultiSegment([](double x) { return x*x*x - x - std::sin(x)*x; }, 0, 100,10000) << std::endl;
//

std::cout << "ROOTS" << std::endl;

std::cout << cl.rootBisection([](double x) { return x*x*x - x + 1 - std::sin(x)*x; }) << endl;
//std::cout << cl.rootSecant([](double x) { return x*x*x  - x + 1 - std::sin(x)*x;; }) << endl;
std::cout << cl.rootNewtonSingle([](double x) { return x*x*x - x + 1 - std::sin(x)*x; }) << endl;
//std::cout << cl.fourthDerivative_unsafe([](double x) { return x*x*x*x*x*x; }, 2) << endl;
//std::cout << cl.fourthDerivative_unsafe([](double x) { return x*x*x*x*x*x; }, 2) << endl;

//cl.eulerODE_1_range([](double x, double y) { return x*x*x - x + 1 - sin(x)*x; }, 0.002, 0).print();

std::cout << cl.eulerODE_1([](double x, double y) { return x*x*x - x + 1 - sin(x)*x; }, 20, 0, 5) << endl;
std::cout << cl.heunODE_1([](double x, double y) { return x*x*x - x + 1 - sin(x)*x; }, 20, 0, 5) << endl;
std::cout << cl.rungekuttaODE([](double x, double y) { return x*x*x - x + 1 - sin(x)*x; }, 20, 0, 5) << endl;
std::cout << cl.dormandPrinceODE([](double x, double y) { return x*x*x - x + 1 - sin(x)*x; }, 20, 0, 5) << endl;
std::cout << cl.dormandPrinceODE_adapt([](double x, double y) { return x*x*x - x + 1 - sin(x)*x; }, 20, 0, 5) << endl;*/
/*
return 0;
}

*/



/*



// TESTING THE GRADIENT
analysis cl;
std::cout << cl.derivativeAverage(fn.testFN , 89) << std::endl;
matrix<double> N(5, 1);
N(1, 1) = 10;
N(2, 1) = 121;
N(3, 1) = 11;
N(4, 1) = 911;
N(5, 1) = 10;
std::cout << "IT WORKS" << std::endl;
matrix<double> N2(3, 1); N2(1, 1) = 1; N2(2, 1) = 2; N2(3, 1) = 3;
cl.gradient_3D(fn.testFn_3D, 1 , 2, 3 ).print();
//std::cout << cl.dim_5_Fn(N) << std::endl;
cl.gradient_ND(fn.testFn_3_N, N2).print();
cl.gradient_ND(fn.testFn_5_N, N).print();
//std::cout << cl.differentiate_WrapperGrad(cl.dim_5_Fn,N,0) << std::endl;

vectorFn_1 R2 = cl.get_func_2D_paramT(fn.testFN, fn.testFN_2);
std::cout << R2(1, 1)(1) << std::endl;
std::cout << R2(1, 1)(100) << std::endl;
std::cout << R2(2, 1)(12) << std::endl;
std::cout << R2(2, 1)(10) << std::endl ;

vectorFn_3 R3_3 = cl.get_func_3D_param3(fn.testFn_3D, fn.testFn_3D_2 , fn.testFn_3D_3);
std::cout << R3_3(1, 1)(1,1,1) << std::endl;
std::cout << R3_3(1, 1)(100,40,50) << std::endl;
std::cout << R3_3(2, 1)(12,49,12) << std::endl;
std::cout << R3_3(3, 1)(10,20,30) << std::endl;

vectorFn_N R3_N = cl.get_func_3D_paramN(fn.testFn_3_N, fn.testFn_3_N, fn.testFn_3_N);
std::cout << R3_N(1, 1)(N2) << std::endl;
std::cout << R3_N(1, 1)(N2) << std::endl;
std::cout << R3_N(2, 1)(N2) << std::endl;
std::cout << R3_N(3, 1)(N2) << std::endl;


vectorFn_N R5_N = cl.get_func_3D_paramN(fn.testFn_5_N, fn.testFn_5_N, fn.testFn_5_N);
std::cout << cl.divergence_ND(N, fn.testFn_5_N, fn.testFn_5_N, fn.testFn_5_N, fn.testFn_5_N, fn.testFn_5_N) << std::endl;
std::cout << cl.divergence_ND(N2, fn.testFn_3_N, fn.testFn_3_N, fn.testFn_3_N) << std::endl;
std::cout << cl.divergence_3D(R3_N, N2) << endl;
matDouble N3(2, 1); N3(1, 1) = 1; N3(2, 1) = 1.57;
std::cout << cl.divergence_ND(N3, fn.FN__N_2x_y, fn.FN__N_cos_y)<< endl;
N3(1, 1) = 1; N3(2, 1) = 1.57 ;
std::cout << cl.divergence_ND(N3, fn.FN__N_100x_y, fn.FN__N_cos_y) << endl;
std::cout << cl.divergence_ND(N3, fn.FN__N_2x2_y2, fn.FN__N_cos_y) << endl;

cl.curl_3D(R3_N, N2).print();





/*


matrix<double> E(5, 5); E.randFill();
matrix<double> E2(5, 1); E2.randFill();



std::cout << la.sum(E2) << endl << la.sum(E) << endl;

la.solverGussianElem(E, E2).print();
la.leastSquareSolver(E, E2).print();
la.jacobiSolver(E, E2).print();
//la.solverLU(E, E2).print();
la.gaussSidelSolver(E, E2).print();


matrix<double> A(4, 4);
A(1, 1) = 10;
A(1, 2) = -1;
A(1, 3) = 2;
A(1, 4) = 0;
A(2, 1) = -1;
A(2, 2) = 11;
A(2, 3) = -1;
A(2, 4) = 3;
A(3, 1) = 2;
A(3, 2) = -1;
A(3, 3) = 10;
A(3, 4) = -1;
A(4, 1) = 0;
A(4, 2) = 3;
A(4, 3) = -1;
A(4, 4) = 8;
matrix<double> B(4, 1);
B(1, 1) = 6;
B(2, 1) = 25;
B(3, 1) = -11;
B(4, 1) = 15;


la.solverGussianElem(A, B).print();
la.leastSquareSolver(A, B).print();
la.jacobiSolver(A, B).print();
la.solverLU(A, B).print();
la.gaussSidelSolver(A, B).print();
//la.LUDecomposePartialPivot(E).print();


matrix<double> LU = la.LUDecomposePartialPivot(E);
LU.print();

matrix<double> L = la.getL_from_LU(LU);
L.print();
matrix<double> U = la.getU_from_LU(LU);
U.print();

matrix<double> A2(3, 3);

A2(1, 1) = 8;
A2(1, 2) = 2;
A2(1, 3) = 9;

A2(2, 1) = 4;
A2(2, 2) = 9;
A2(2, 3) = 4;

A2(3, 1) = 6;
A2(3, 2) = 7;
A2(3, 3) = 9;

matrix<double> ALU = la.LUDecomposePartialPivot(A2);
la.getL_from_LU(ALU).print();
la.getU_from_LU(ALU).print();

A2.print();
//matrix<double> A3 = L*U;
//A3.print();

matrix<double> QW(4, 4);
QW.symetricRandFill();
QW.print();
cout << la.isPositiveDefinite(QW);


matrix<double> K(3, 3);
K(1, 1) = 25;
K(1, 2) = 15;
K(1, 3) = -5;

K(2, 1) = 15;
K(2, 2) = 18;
K(2, 3) = 0;

K(3, 1) = -5;
K(3, 2) = 0;
K(3, 3) = 11;

K.print();
la.choleskyFactorize(K).print();



matrix <double> D(6, 2);
matrix <double> Y(6, 1);

for (int i = 1; i <= 6; i++)
D(i, 1) = 1;

D(1, 2) = 0;
D(2, 2) = 1;
D(3, 2) = 2;
D(4, 2) = 3;
D(5, 2) = 4;
D(6, 2) = 5;


Y(1, 1) = 3;
Y(2, 1) = 5;
Y(3, 1) = 7;
Y(4, 1) = 8;
Y(5, 1) = 9;
Y(6, 1) = 11;


matrix<double> MODEL = la.leastSquareSolver(D, Y);
MODEL.print();
matrix<double> OUTPUT = D*MODEL;
OUTPUT.print();
la.getResidue(Y, OUTPUT).print();



D(1, 2) = 6;
D(2, 2) = 7;
D(3, 2) = 8;
D(4, 2) = 9;
D(5, 2) = 10;
D(6, 2) = 11;

OUTPUT = D*MODEL;
OUTPUT.print();

A2.print();

matrix<double> QR = la.QRFactorizeRow(A2,false);
/*la.getQ_from_QR(QR).print();
la.getR_from_QR(QR).print();

la.QRFactorizeCol(A2, true).print();

std::cout << la.normForbenius(A);

A2.print();
la.eigenPower(A2).print();
la.eigenPower(A2,true).print();*/

//la.eigenHotellingDeflation(A2).print();


//la.eigenPowerInverse(A2, true).print();



//la.eigenQR(A2).print();


//la.LUDecomposePartialPivot(A2).print();


//la.QRFactorizeCol(A2, true).print();

//la.choleskyFactorize(A2).print();


/*

//matrix<double> E3(500, 1); E3.randFill();
//E2.print();
//la.mapMatrixDouble(E3,  &(calculus::testFN)).print();


matrix<double> E(10, 5); E.randFill();
matrix<double> E2(1, 3); E2.randFill();
la.gaussianElemPartialPivot(E, E2).print();
la.LUDecomposePartialPivot(E).print();
la.gramSchmidtOrtho(E, false).print();
la.gramSchmidtOrtho(E, true).print();

matrix<double> A(3, 3);
A(1, 1) = 1; A(1, 2) = 1; A(1, 3) = 1;
A(2, 1) = 1; A(2, 2) = 0; A(2, 3) = 1;
A(3, 1) = 0; A(3, 2) = 1; A(3, 3) = 1;


la.inversePenrose(A).print();
la.inverseGuassJordan(A).print();



la.inversePenrose(E).print();
la.inverseGuassJordan(E).print();
matrix<double> A(10, 10);
A.randFill();

matrix<double> B(10, 10);
B.randFill();

matrix<double> C = A + B;
C.print();

matrix<double> D = A - B;
D.print();


matrix<double> E = D;
E.print();
matrix<double> A(10, 10);
A.randFill();

matrix<double> B(10, 10);
B.randFill();

matrix<double> C = A + B;
C.print();




matrix<double> A(2, 2);

A(1, 1) = 2;
A(2, 2) = 2;
A(1, 2) = 1;
A(2, 1) = 1;

A.print();
matrix<double> B = A* la.tranpose(A);
B.print();
std::cout << la.isSymetric(A);







matrix<double> B2(1, 3);
B2(1, 1) = 1; B2(1, 2) = 1; B2(1, 3) = 0;
std::cout << la.normEuclidean(B2);
A.print();
la.gramSchmidtOrtho(A, false).print();
la.gramSchmidtOrtho(A, true).print();
*/
	//std::cout << la.determinat(E) << std::endl ;


	

	//matrix <double> ANS = K*K*K*K*K*K*K*K;//*K*K*K*K*K*K*K*K*K*K*K*K*K*K*K*K*K*K*K*K*K;//la.inverseDC(K);
	//ANS.print();

	//std::cout << sizeof(char*);

	//matrix <double> test  = la.joinCol(E,LA);
	//test.print();

//	matrix<double> LA2(200,1);
	//matrix<double> LA1(200,200);
	//matrix<double> E2(10,10);

	//LA2.randFill(); //LA2.print();
	//LA1.randFill(); //LA1.print();

//	matrix<double> Q = LA1*LA1;
	//Q.print();
	//E2.randFill();
	//la.projectionOn(LA1,LA2).print();
	/*
	matrix<double> TRI = la.getTriDiagonal(10,1,2,-2);
	TRI.print();
	la.tranpose(TRI).print();
	std::cout << la.isSymetric(TRI);
	matrix<double> SYM = la.getIdentity(5);
	std::cout << la.isSymetric(SYM);	



	matrix <double> GE2 = la.gaussianElem(E2,LA2);
	//GE2.print();
	 matrix <double> X = la.backSubstitution(GE2);
	 X.print();

	la.inverseGuassJordan(E2).print(); // correct
	E2.print();
	la.swapRow(E2,1,10).print();
	la.swapCol(E2,1,10).print();

	 //la.LUDecompose(E2).print();
	
	 // la.getIdentity(5).print();

	//E2.print();
	//matrix<double> ABS = la.spliceCopyCols(E2,2,3);
	//ABS.print();



}
*/