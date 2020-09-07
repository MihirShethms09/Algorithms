#include<iostream>
using namespace std;
void matrix_multiplication(int a[2][2],int b[2][2])
{
	int mul[2][2];
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			for(int k=0;k<2;k++)
			{
				mul[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
			cout<<mul[i][j]<<" ";
		cout<<endl;
	}
}
int main()
{
	int a[][2]={1,2,3,4};
	int b[][2]={2,3,4,1};
	matrix_multiplication(a,b);
	return 0;
}
