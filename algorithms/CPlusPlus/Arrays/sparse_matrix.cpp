/*Description :c++ solution to check if a given matrix is sparse matrix.
If the count of zeroes present in the mmatrix is more than half the elements of the matrix, 
it is flagged as a sparse matrix.
Also the tuple form of the matrix(if the said matrix is sparse) is displayed.*/


#include<iostream>
using namespace std;

int compactMatrix(int sparseMatrix[4][5])
{
	int size = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 5; j++)
			if (sparseMatrix[i][j] != 0)
				size++;

	/* number of columns in compactMatrix (size) must be
	   equal to number of non - zero elements in sparseMatrix */
	int compactMatrix[size][3];

	// Making of new matrix
	int k = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 5; j++)
			if (sparseMatrix[i][j] != 0)
			{
				compactMatrix[k][0] = i;
				compactMatrix[k][1] = j;
				compactMatrix[k][2] = sparseMatrix[i][j];
				k++;
			}
  cout<<"The tuple form is:"<<endl;
	for (int i=0; i<size; i++)
	{
		for (int j=0; j<3; j++)
			cout <<" "<< compactMatrix[i][j];

		cout <<"\n";
	}
	return 0;
}

int main () {
   int sparseMatrix[4][5] =
	{
		{0 , 0 , 3 , 0 , 4 },
		{0 , 0 , 5 , 7 , 0 },
		{0 , 0 , 0 , 0 , 0 },
		{0 , 2 , 6 , 0 , 0 }
	};
   int i, j, count = 0;
   int row = 4, col = 5;
   for (i = 0; i < row; ++i) {
      for (j = 0; j < col; ++j){
         if (sparseMatrix[i][j] == 0)
         count++;
      }
   }
   cout<<"The matrix is:"<<endl;
   for (i = 0; i < row; ++i) {
      for (j = 0; j < col; ++j) {
         cout<<sparseMatrix[i][j]<<" ";
      }
      cout<<endl;
   }
   cout<<"The number of zeros in the matrix are "<< count <<endl;
   if (count > ((row * col)/ 2))
      {
         cout<<"This is a sparse matrix"<<endl;
         compactMatrix(sparseMatrix);
      }
   else
   cout<<"This is not a sparse matrix"<<endl;
   return 0;
}




/*output
The matrix is:
0 0 3 0 4 
0 0 5 7 0 
0 0 0 0 0 
0 2 6 0 0 
The number of zeros in the matrix are 14
This is a sparse matrix
The tuple form is:
 0 2 3
 0 4 4
 1 2 5
 1 3 7
 3 1 2
 3 2 6
*/