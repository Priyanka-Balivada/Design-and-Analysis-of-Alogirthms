#include<stdio.h>

int josephus(int n)
{
	if(n==1||n==2)
		return 1;
	else if(n%2==0)
		return 2*josephus(n/2)-1;
	else
		return 2*josephus(n/2)+1;
}

void main()
{
	int n;
	printf("Enter number of people : ");
	scanf("%d",&n);
	
	printf("\n\nPerson %d is the winner",josephus(n));
}
