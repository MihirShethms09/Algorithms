#include<iostream>
using namespace std;
#define max 9
int pos=-1;
int stack[max-1];
void push(int value)
{
	stack[++pos]=value;
}
int pop()
{
	return stack[pos--];
}
void dfs(int m[][max],int visited[],int begin)
{
	int temp;
	push(begin);
	visited[begin]=1;
	while(pos>=0)
	{
		temp=pop();
		for(int j=0;j<max;j++)
			if(m[temp][j]==1 && visited[j]==0)
			{
				push(j);
				visited[j]=1;
			}
		cout<<(char)(temp+65)<<" ";
	}
}
int main()
{
	int m[max][max],i,j;
	int visited[max]={0};
	cout<<"Enter adjacency matrix "<<endl;
	for(i=0;i<max;i++)
		for(j=0;j<max;j++)
			cin>>m[i][j];
	dfs(m,visited,7);
	return 0;
}
