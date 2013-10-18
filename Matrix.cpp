#include"Matrix.h"
#include<cassert>

Matrix::Matrix(int m , int n)
{
	try
	{
		if(m<=0)
			throw (m);
		this->rows = m;
		this->columns = n;

		p = new Vector*[m];

		if(p == 0)
			throw p;
	
		for(int i=0 ; i<m ; ++i)
		{
			p[i] = new Vector(n);
		}
	}
	catch(Vector **p)
	{
		cout<<"Memory insuffiecient in heap. Could not allocate memory for the Array of Vector* in the heap."<<endl;
		exit(EXIT_FAILURE);	
	}
	catch(int m)
	{
		cout<<"Invalid number of rows entered."<<endl;
		cout<<"Could not create the matrix with rows = "<<m<<endl<<"Program Aborted."<<endl;
		exit(EXIT_FAILURE);
	}
}

Matrix::Matrix(const Matrix& A)
{
	try
	{
		rows = A.rows;
		columns = A.columns;	

		p = new Vector*[rows];

		if(p==0)
			throw p;

		for(int i=0 ; i<rows ; ++i)
		{
			//create a new vector and copy the corresponding vector from A.
			p[i] = new Vector(columns);
			*p[i] = *A.p[i];
		}
	}
	catch(Vector **p)
	{
		cout<<"Memory insuffiecient in heap. Could not allocate memory for the Array of Vector* in the heap."<<endl;
		exit(EXIT_FAILURE);
	}
}

Matrix::~Matrix()
{
	for(int i=0 ; i<rows ; ++i)
	{
		delete p[i];
	}
	delete []p;
}

Vector& Matrix::operator[](int i)
{
	try
	{
		if(i<0 || i>=this->rows)
			throw (i);
		return *(this->p[i]);
	}
	catch(int i)
	{
		cout<<"Indexing out of bounds : "<<i<<"  row : "<<this->rows<<endl;
		exit(EXIT_FAILURE);
	}
}

const Vector& Matrix::operator[](int i) const
{
	try	
	{
		if(i<0 || i>=this->rows)
			throw (i);
		return *(this->p[i]);
	}
	catch(int i)
	{
		cout<<"Indexing out of bounds : "<<i<<"  row : "<<this->rows<<endl;
		exit(EXIT_FAILURE);
	}
}

ostream& operator<<(ostream& out ,const Matrix& A)
{
	for(int i=0 ; i<A.rows ; ++i)
	{
		for(int j=0 ; j<A.columns ; ++j)
		{
			if(fabs(A[i][j]) < 0.000001)
				out << 0 <<'\t';
			else
				out<<A[i][j]<<'\t';
		}
		out<<endl;
	}
	return out;
}

istream& operator>>(istream& in , Matrix& A)
{
	for(int i=0 ; i<A.rows ; ++i)
	{
		in>>A[i];
	}
	return in;
}

Vector Matrix::operator*(const Vector& V) const
{
	const Matrix& A = (*this);
	assert(A.columns == V.get_n());
	Vector Ans(A.rows);

	for(int i=0 ; i<A.rows ; ++i)
	{
		int temp = 0;
		for( int k=0 ; k < A.columns ; ++k)
		{
			temp += A[i][k]*V[k];
		}
		Ans[i] = temp;
	}
	return Ans;
}


void Matrix::backSubstitution(Matrix& U , Vector& b, Vector& solVector)
{
    for(int i=U.rows-1; i>=0; --i)
    {
        double temp=0;
        for(int j=U.rows-1; j>=i; --j)
        {
            if(i!=j)
            temp+=U[i][j]*solVector[j];

        }
        double subValue=b[i]-temp;
        solVector[i]=(subValue/U[i][i]);
    }
}

void Matrix::displayAugmentedMatrix( Matrix& A , Vector& b)
{
	for( int i=0 ; i<A.rows ; ++i)
	{
		for( int j=0 ; j < A.rows ; ++j)
		{
			if( A[i][j] < 0.000001 && A[i][j] > -0.000001 )
				cout << 0 << "  ";
			else
				cout << A[i][j] << "  ";
		}
		cout << ":  " << b[i] << endl;
	}
}
