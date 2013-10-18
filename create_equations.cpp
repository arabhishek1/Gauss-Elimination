#include<iostream>
#include<fstream>	//Inorder to open a file
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
	char filename[50];
	cout << "Please enter the file in which the equations are to be created : ";
	cin >> filename;
	ofstream file( filename );

	printf("Enter the number of variables in the system of equations : ");
	int vars;
	scanf("%d",&vars);
	printf("Enter the number of equations in the system of equations : ");
	int eqs;
	scanf("%d",&eqs);


	if( !file.is_open())
	{
		cout << "Error in opening the file.. File is not present."<<endl;
		exit(EXIT_FAILURE);
	}

	srand(time(0));

	for( int i=0 ; i<eqs ; ++i)
	{	
		for( int j=0 ; j< vars+1 ; ++j)
		{
			double num;
			num = rand()%101;
			num = num + (double)rand()/RAND_MAX;
			file << num << '\t';
		}
		file << endl;
	}


	//close the file
	file.close();
	return 0;
}
