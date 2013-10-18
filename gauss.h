#ifndef GAUSS
#define GAUSS

#include "Matrix.h" 
#include<cmath>
#include<cstdlib>

void getTheEquations( Matrix& A , Vector& b , int num);
void gaussElimination(Matrix& A, Vector& b,int n);// to convert A to the uppertriangular matrix U
int getNoOfEquations();


void eleminateRow(Matrix& Aug,int j,int i,int n);

int findPivotRow(Matrix& Aug, int i, int n);
void update(Matrix& Aug, Matrix& A, Vector& b,int n);
void append( Matrix& Aug, Matrix& A, Vector& b, int n);
void checkifsingular(double number);

#endif
