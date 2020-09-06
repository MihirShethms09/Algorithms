#include<iostream>
using namespace std;
int main()
{
	int n;
	cout<<"Enter the no of jobs you want to enter ";
	cin>>n;
	int job[n],profit[n],dead[n],max=0;
	int temp1,temp2,temp3;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter job no "<<i+1<<" ";
		cin>>job[i];
		cout<<"Enter the profit ";
		cin>>profit[i];
		cout<<"Enter its deadline ";
		cin>>dead[i];
		if(dead[i]>max)
			max=dead[i];
	}
	int slot[max];
	for(int i=0;i<max;i++)
		slot[i]=9999;
	
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-1-i;j++)
		{
			if(profit[j+1]>profit[j])
			{
				temp1=profit[j];
				profit[j]=profit[j+1];
				profit[j+1]=temp1;
				
				temp2=job[j];
				job[j]=job[j+1];
				job[j+1]=temp2;
				
				temp3=dead[j];
				dead[j]=dead[j+1];
				dead[j+1]=temp3;
			}
		}
	}
	int sum=0,temp,index;
	for(int i=0;i<n;i++)
	{
		index=job[i];
		temp=dead[i];
		for(int j=temp-1;j>=0;j--)
		{
			if(slot[j]==9999)
			{
				slot[j]=index;
				sum+=profit[i];
				break;
			}
		}
	}
	cout<<"The jobs executed are ";
	for(int i=0;i<max;i++)
		cout<<slot[i]<<" ";
	
	cout<<"The total profit obtained is "<<sum;
	return 0;
}
