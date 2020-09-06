#include<iostream>
#include<stack>
#include<array>
using namespace std;
#define n 5
bool detect_cycle(int a[][n])
{
	int temp,flag=0,dummy=0;
	array<int,n> visit;
	stack<int> st;
	for(int i=0;i<n;i++)
	{
		st.push(i);
		visit.fill(0);
		visit[i]=1;
		while(!st.empty())
		{
			temp=st.top();
			dummy=0;
			for(int j=0;j<n;j++)
			{
				if(a[temp][j]==1 && visit[j]==0)
				{
					dummy=1;
					st.push(j);
					visit[j]=1;
					break;
				}
				if(j==i && visit[j]==1 && a[temp][j]==1)
				{
					flag=1;
					break;
				}
			}
			if(dummy==0)
				st.pop();
		}
		if(flag==1)
			break;
	}
	if(flag==1)
		return true;
	else
		return false;
}
int main()
{
	int a[n][n];
	cout<<"Enter the adjacency matrix: "<<endl;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>a[i][j];

	bool ans=detect_cycle(a);
	if(ans)
		cout<<"There is a cycle in graph";
	else
		cout<<"There is no cycle in graph";
	return 0;
}
