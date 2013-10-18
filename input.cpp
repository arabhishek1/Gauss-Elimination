#include<iostream>
#include"Matrix.h"
#include<cstdlib>
#include<fstream>	//Inorder to open a file

using namespace std;

void getTheEquations( Matrix& A , Vector& b , int num)
{
	//I have to take the equations from a file named equations.txt
	//To input a file take a file name
	char filename[50];
	cout << "Please enter the file in which the matrix is present : ";
	cin >> filename;
	ifstream file( filename );
	//file.open(filename);
	
	//Check if the file is open
	if( !file.is_open())
	{
		exit(EXIT_FAILURE);
	}
	int i,j;
	for( i=0 ; i<num && file.good() ; ++i)
	{
		for( j=0 ; j<num && file.good(); ++j)
		{
			file >> A[i][j];
		}
		file >> b[i];
	}
	if( i<num || j<num)
	{
		cerr << "The file does not contain the all the equations fully" << endl;
		exit(EXIT_FAILURE);
	}
	//close the file
	file.close();
}


