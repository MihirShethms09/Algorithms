#include<iostream>
using namespace std;
#define max 5
//function to implement breadth first search
void bfs(int m[][max],int visited[],int begin)
{
	int q[max];
	int rear=-1,front=-1;
	q[++rear]=begin;
	visited[begin]=1;
	int i;
	while(front!=rear)
	{
		begin=q[++front];
		for(i=0;i<max;i++)
			if(m[begin][i]==1 && visited[i]==0)
			{
				q[++rear]=i;
				visited[i]=1;
			}
	}
	rear++;
	cout<<"The order of bfs traversal is ";
	for(int j=0;j<rear;j++)
	{
		cout<<(char)(q[j]+65)<<" ";
	}
}
int main()
{
	int m[max][max],i,j;
	int visited[max]={0};
	cout<<"enter the adjacency matrix: "<<endl;
	for(i=0;i<max;i++)
		for(j=0;j<max;j++)
			cin>>m[i][j];
	bfs(m,visited,1);//here third argument is the starting vertex
	return 0;
}
