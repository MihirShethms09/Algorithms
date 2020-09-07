#include<bits/stdc++.h>
using namespace std;
struct node{
	int weight;
	int value;
	float factor;
	struct node *next;
};
struct node *start=NULL;
struct node *insert(struct node *start)
{
	struct node *ptr;
	ptr=(struct node *)malloc(sizeof(struct node));
	cout<<"Enter the weight ";
	cin>>ptr->weight;
	cout<<"Enter the value ";
	cin>>ptr->value;
	ptr->factor=(float)(ptr->value)/(float)(ptr->weight);
	if(start==NULL)
	{
		ptr->next=NULL;
		start=ptr;
	}
	else
	{
		ptr->next=start;
		start=ptr;
	}
	return start;
}
int main()
{
	int n,capacity;
	cout<<"Enter the capacity of bag: ";
	cin>>capacity;
	cout<<"Enter the total no of weights: ";
	cin>>n;
	int i=0;
	while(i<n)
	{
		start=insert(start);
		i++;
	}
	struct node *temp=start;
	cout<<endl;
	float a[n];
	int v[n],w[n];
	int j=0;
	float temp1;
	int temp2;
	int temp3;
	temp=start;
	while(temp!=NULL)
	{
		a[j]=temp->factor;
		v[j]=temp->value;
		w[j]=temp->weight;
		j++;
		temp=temp->next;
	}
	for(int k=0;k<n;k++)
	{
		for(int l=0;l<n-k-1;l++)
		{
			if(a[l]<a[l+1])
			{
				temp1=a[l];
				a[l]=a[l+1];
				a[l+1]=temp1;
				
				temp2=v[l];
				v[l]=v[l+1];
				v[l+1]=temp2;
				
				temp3=w[l];
				w[l]=w[l+1];
				w[l+1]=temp3;
			}
		}
	}
	j=0;
	temp=start;
	while(temp!=NULL)
	{
		temp->factor=a[j];
		temp->value=v[j];
		temp->weight=w[j];
		j++;
		temp=temp->next;
	}
	
	cout<<endl;
	temp=start;
	float sum=0;
	float num1;
	float ratio;
	int count=capacity;
	cout<<"weights to be included"<<endl;
	while(count>0)
	{
		if(temp->weight>count)
		{
			num1=(temp->weight)-count;
			cout<<count<<" of "<<temp->weight<<endl;
			ratio=num1/(temp->weight);
			sum+=(1-ratio)*(float)(temp->value);
			count=0;
		}
		else
		{
			sum+=temp->value;
			count-=temp->weight;
			cout<<temp->weight<<" ";
			temp=temp->next;
		}
	}
	cout<<"Total value is "<<sum;
	return 0;
}
