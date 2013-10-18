#include"Vector.h"
#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

Vector::Vector( int n )		//constructor
{
	try
	{
		if(n<=0)
		{
			throw(n);
		}

		this->n = n;
		this->q = new double[n];

		if( q == 0 )
		{
			throw( q );
		}

		for(int i=0 ; i<n ; ++i)
		{
			this->q[i] = 0;
		}

	}
	catch(int n)
	{
		cout<<"n = "<<n<<endl;
		cout<<"Could not construct the Vector"<<endl;	
		cout<<"Invalid entry column size <=0!!"<<endl;
		exit(EXIT_FAILURE);
	}
	catch(double *q)
	{
		cout<<"Memory insuffiecient in heap. Could not allocate memory for the vector in the heap."<<endl;
		exit(EXIT_FAILURE);
	}
}





Vector::Vector( const Vector& A)	//copy constructor
{
	try
	{
		this->n = A.n;
		this->q = new double[n];
	
		if(q==0)
			throw (q);

		for(int i=0 ; i < A.n ; ++i)
		{
			this->q[i] = A.q[i];
		}
	}
	catch(double* q)
	{
		cout<<"Memory insuffiecient in heap. Could not allocate memory for the vector in the heap."<<endl;
		exit(EXIT_FAILURE);
	}

}


Vector::~Vector()
{
	delete []q;	
}	


//Overloading Operators
double& Vector::operator [](int i)
{ 
	checkBounds( i , n);
	return q[i];
}

const double& Vector::operator [](int i) const
{
	checkBounds( i , n); 	
	return q[i];
}

void checkBounds(int i , int n)
{
	try
	{
		if( i<0 )
		{
			char *p = new char[50];
			strcpy(p,"Vector referenced below bounds.");
			throw (p);
		}
		if( i >= n)
		{
			char *p = new char[50];
			strcpy(p,"Vector refenced above bounds.");
			throw (p);
		}
	}
	catch(char *S)
	{
		cout<<"Vector indexed out of bounds. "<<S<<endl;
		cout<<"Program Aborted."<<endl;
		exit(EXIT_FAILURE);
	}
}


Vector& Vector::operator =(const Vector& A) 
{
	try
	{
		if( this->n != A.n )
		{
			throw (A.n);
		}	
		return *this;
	}
	catch(int j)
	{
		cout<<"Assignment of 2 vectors of unequal length."<<endl;
		if(this->n > j)
			cout<<"Assigning a small vector to a big one."<<endl;
		else
			cout<<"Assigning a big vector to a small one."<<endl;
		exit(EXIT_FAILURE);
	}

}


bool Vector::operator ==( const Vector& A) const
{
	if(this->n != A.n)
		return false;

	bool equal = true;

	for(int i=0 ; i < A.n && equal ; ++i )
	{
		if ( ( (*this)[i] - A[i] ) > 0.000001 && ( (*this)[i] - A[i] ) < -0.000001 )
		{
			equal = false; 
		}
	}

	return equal;
}



	//Extract‭ion and insertion operator overloading
ostream& operator<<( ostream& out , const Vector& A)
{
	for( int i=0 ; i<A.n ; ++i )
	{
		if(fabs(A[i]) < 0.000001)
			out<<0<<endl;
		else
			out<<A[i]<<endl;
	}
	return out;
}


istream& operator>>( istream& in , Vector& A )
{
	for(int i=0 ; i<A.n ; ++i )
	{
		in >> A[i];
	}
	return in;
}

//Other functions that enhance the power of the vector class
void Vector::swap(Vector& A , Vector& B)
{
	double *temp = A.q;
	A.q = B.q;
	B.q = temp;
}
