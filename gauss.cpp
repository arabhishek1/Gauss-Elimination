#include "gauss.h"
using namespace std;

int getNoOfEquations()		// to get the number of variables(col) and equations(rows)
{
	cout<<"Enter the number of variables:\t";
	int rows;
	cin>>rows;
	cout<<"Enter the number of equations:\t";
	int equations;
	cin>>equations;
	
	if(rows==equations)
	{
		return rows;		//if it is not a singular matrix return the rows or equations	
	}
	else
	{
		cout<<"This is a singular matrix\n";
		exit(EXIT_FAILURE);
	}
}



void gaussElimination(Matrix& A,Vector& b,int n)
{
	Matrix Aug(n,n+1);
	append(Aug,A,b,n);
	for(int i=0; i<n-1; ++i)
	{
		int pivotrow = findPivotRow(Aug,i,n);
		Vector::swap(Aug[i],Aug[pivotrow]);
		checkifsingular(Aug[i][i]);
		for(int j=i+1;j<n;j++)
		{
			eleminateRow(Aug,j,i,n);
		}	
	}
		checkifsingular(Aug[n-1][n-1]);
		
	update(Aug,A,b,n);
}

void checkifsingular(double number)
{
	if(fabs(number)<=0.000001)
	{
		cerr<<"The given system is singular"<<endl;
		exit(EXIT_FAILURE);
	}
}

void append( Matrix& Aug, Matrix& A, Vector& b, int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			Aug[i][j]=A[i][j];
		}
		Aug[i][n]=b[i];
	}
}

void update(Matrix& Aug, Matrix& A, Vector& b,int n)
{
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;j++)
		{
			A[i][j]=Aug[i][j];
		}
		b[i]=Aug[i][n];
	}
} 

int findPivotRow(Matrix& Aug, int i, int n)
{
	int pivotrow=i;
	for(int j=i+1;j<n;j++)
	{
		if( fabs(Aug[j][i]) > fabs(Aug[pivotrow][i]) )
		{
			pivotrow=j;
		}
	}
	return pivotrow;
}	



void eleminateRow(Matrix& Aug,int j,int i,int n)
{
	double temp = Aug[j][i]/Aug[i][i];
	for(int k=i;k<n+1;k++)
	{
		Aug[j][k] -= Aug[i][k]*temp;
	}
}





