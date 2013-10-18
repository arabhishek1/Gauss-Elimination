#include"Matrix.h"
#include"gauss.h"
#include<iostream>
using namespace std;

int main()
{
	int num = getNoOfEquations();
	Matrix A(num , num);
	Matrix Unchanged_A(A);
	Vector b(num);
	Vector Unchanged_b(b);
	cout << "Getting the equations" << endl;
	getTheEquations( A , b, num);
	
	cout << "doing the guass elimination" << endl;
	gaussElimination(A, b, num);

	cout<<"The simplified augmented matrix : \n";
//	Matrix::displayAugmentedMatrix(A,b);

	Vector solVector(num);
	Matrix::backSubstitution(A , b, solVector);
	cout << "The solution vector : \n";
//	cout << solVector << endl;

	if( Unchanged_A * solVector == Unchanged_b)	//checking Ax=b.
	cout << "The solution is correct\n";
	else
	cout << "The solution is wrong\n";

	return 0;
}

