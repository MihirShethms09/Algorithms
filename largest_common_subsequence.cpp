#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s1,s2;
	cout<<"Enter the first string: ";
	cin>>s1;
	cout<<"Enter the second string: ";
	cin>>s2;
	int n1,n2;
	n1=s1.size();
	n2=s2.size();
	
	int a[n1+1][n2+1];
	for(int i=0;i<n1+1;i++)
		a[i][0]=0;
	for(int i=0;i<n2+1;i++)
		a[0][i]=0;
	
	for(int i=0;i<n1;i++)
	{
		for(int j=0;j<n2;j++)
		{
			if(s1[i]==s2[j])
				a[i+1][j+1]=a[i][j]+1;
			else
			{
				if(a[i][j+1]>a[i+1][j])
					a[i+1][j+1]=a[i][j+1];
				else
					a[i+1][j+1]=a[i+1][j];
			}
		}
	}
	
	cout<<endl;
	cout<<a[n1][n2];
	return 0;
}
