//Program to implement Tower of Hanoi
#include<stdio.h>
#include<math.h>
void tower(int n,char a[],char b[],char c[])
{
	if(n==1)
	{
		printf("\nmove disk %d from %s --> %s",n,a,c);
		return;
	}
	//move n-1 disks from a to b
	tower(n-1,a,c,b);
	//move disk from a to c
	printf("\nmove disk %d from %s --> %s",n,a,c); //tower(1,a,b,c);
	//move n-1 disks from b to c
	tower(n-1,b,a,c);
}
void main()
{
	int n;
	printf("Enter the number of disks :\t");
	scanf("%d",&n);
	if(n<1)
	{
		printf("\n\nINCORRECT VALUE");
	}
	else
	{
	printf("\n\nMoves required to move all disks to final peg for N = %d : %d",n,(int)pow(2, n)-1);
	tower(n,"A","B","C");
//	tower(n,"BEG","AUX","END");
	}
	getch();
}
