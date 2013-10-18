#ifndef MATRIX
#define MATRIX

#include"Vector.h"
#include<iostream>
using namespace std;

class Matrix
{
	private:
		int rows,columns;	//gives the dimention of the matrix
		Vector **p;
	public:
		Matrix(int m , int n);
		Matrix(const Matrix& A);
		~Matrix();

	//Overloading of operators
	Vector& operator[](int i);
	const Vector& operator[](int i) const;
	Vector operator*(const Vector& V) const;

	//overloading of the extraction and the insertion operator.
	friend istream& operator>>(istream& in , Matrix& A);
	friend ostream& operator<<(ostream& out ,const Matrix& A);

	static void displayAugmentedMatrix( Matrix& A , Vector& b);
	static void backSubstitution(Matrix& U , Vector& b, Vector& solMatrix);
};

#endif
