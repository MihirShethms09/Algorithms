#include<iostream>
using namespace std;
#define max 7
void djikstra(int m[][max],int w[],int visit[],int start,int end)
{
	int index=start;
	int cost=0;
	int i,j,min;
	w[index]=0;
	while(visit[end]!=1)
	{
		visit[index]=1;
	//	cout<<char(index+97)<<" ";
		for(i=0;i<max;i++)
		{
			if(m[index][i]>0 && m[index][i]+w[index]<w[i] && visit[i]==0)
			{
				w[i]=m[index][i]+w[index];
			}
		}
		min=9999;
		for(j=0;j<max;j++)
			if(w[j]<min && visit[j]==0)
			{
				min=w[j];
				index=j;
			}
	//	cost+=min;
	}
	cout<<"\nMinimum cost from "<<start<<" to "<<end<<" is "<<w[end];
}
int main()
{
	int m[max][max];
	int w[max]={9999,9999,9999,9999,9999,9999,9999};
	int visit[max]={0};
	cout<<"Enter the adjacency matrix: "<<endl;
	for(int i=0;i<max;i++)
	{
		for(int j=0;j<max;j++)
			cin>>m[i][j];
	}
	djikstra(m,w,visit,6,0);
	return 0;
}
