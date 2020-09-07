#include<iostream>
using namespace std;
int main()
{
	int n;
	cout<<"Enter the no of matrices you want to enter: ";
	cin>>n;
	int a[n][2];
	for(int i=0;i<n;i++)
	{
		cout<<"Enter the order of matrix "<<i+1<<" ";
		cin>>a[i][0]>>a[i][1];
	}
	int m[n][n];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			if(j<=i)
				m[i][j]=0;
			else
				m[i][j]=9999;
		}
	
	int k,l,index;	
	for(int c=n-1;c>0;c--)		
		for(k=0,l=n-c;l<n;k++,l++)
		{
			index=k;
			while(index<l)
			{
				if(m[k][index]+m[index+1][l]+a[k][0]*a[index+1][0]*a[l][1]<m[k][l])
					m[k][l]=m[k][index]+m[index+1][l]+a[k][0]*a[index+1][0]*a[l][1];
				index++;
			}
		}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<m[i][j]<<"           ";
		cout<<endl;
	}
	return 0;
}
