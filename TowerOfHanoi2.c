//Program to implement Tower of Hanoi
#include<stdio.h>
int cnt=0;
void tower(int n,int k,char a[],char b[],char c[])
{
	if(n==1)
	{
		cnt++;
		if(k==cnt)
			printf("\nmove disk %d from %s --> %s",n,a,c);
		return;
	}
	//move n-1 disks from a to b
	tower(n-1,k,a,c,b);
	//move disk from a to c
	cnt++;
	if(cnt==k)
		printf("\nmove disk %d from %s --> %s",n,a,c);
	//move n-1 disks from b to c
	tower(n-1,k,b,a,c);
}
void main()
{
	int n,k;
	printf("Enter the number of disks :\t");
	scanf("%d",&n);
	
	printf("Enter the k :\t");
	scanf("%d",&k);
	
	if(n<1)
	{
		printf("\n\nINCORRECT VALUE");
	}
	else
	{
	tower(n,k,"A","B","C");
	}
	getch();
}
