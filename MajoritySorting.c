#include<stdio.h>

void mergesort(int [],int,int);
void merge(int [],int,int);
void main()
{
	int a[10]={4,5,6,4,9,4,4,8,4,4},i,n=10,count=0,maj=0;
	i=0;
	mergesort(a,i,n-1);
	printf("\n\nSorted Array :");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	
	for(i=1;i<n;i++)
	{
		if(a[i-1]==a[i])
		{
			count++;
		}
		else{
			if(maj<count)
			{
				maj=count;
				count=0;
			}
		}
	}
	maj=maj+1;
	
	if(maj>n/2)
	{
		printf("\n\nMajority : %d",a[n/2]);
	}else{
		printf("\n\nNo Majority");
	}
}
void mergesort(int a[],int i,int n)
{
	int mid;
	if(i>=n)
	return;
	mid=(i+n)/2;
	mergesort(a,i,mid);
	mergesort(a,mid+1,n);
	merge(a,i,n);
}
void merge(int a[],int i,int n)
{
	int j,k,m,b[200],mid;
	mid=(i+n)/2;
	for(j=i,k=mid+1,m=0;j<=mid&&k<=n;m++)
	{
		if(a[j]<a[k])
		b[m]=a[j++];
		else
		b[m]=a[k++];
	}
	while(j<=mid)
	{
		b[m++]=a[j++];
	}
	while(k<=n)
	{
		b[m++]=a[k++];
	}
	for(m=0;i<=n;m++)
	{
		a[i++]=b[m];
	}
}


