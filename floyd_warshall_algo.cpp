#include<iostream>
#include<vector>
using namespace std;
#define max 5
int main()
{
	vector<int> v[max],m[max];
	int temp;
	cout<<"Enter the adjacency matrix"<<endl;
	for(int i=0;i<max;i++)
		for(int j=0;j<max;j++)
			{cin>>temp;v[i].push_back(temp);}
	for(int i=0;i<max;i++)	
		for(int j=0;j<max;j++)
		{
			if(v[i][j]==0 && i!=j)
				m[i].push_back(9999);
			else
				m[i].push_back(v[i][j]);
		}
		cout<<endl;
	for(int i=0;i<max;i++)
	{
		for(int j=0;j<max;j++)
		{
			for(int k=0;k<v[j].size();k++)
				if(k!=j && k!=i && j!=i)
					if(m[k][j]>m[k][i]+m[i][j])
						m[k][j]=m[k][i]+m[i][j];
		}
	}
	cout<<"The weighted path matrix is"<<endl;
	for(int i=0;i<max;i++)
	{
		for(int j=0;j<m[i].size();j++)
			{cout<<m[i][j]<<" ";}
		cout<<endl;
	}
	return 0;
}
