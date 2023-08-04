#include<stdio.h>

//1 indicates alive and 0 indicates dead
void initialize(int n,int *people)
{
	int i;
	
	for(i=0;i<n;i++)
	{
		//initialize all people as alive with 1
		people[i]=1;
	}
	
//	print(n,people);
	return people;
}

int josephus(int n,int *people)
{
	int sword=0; //1 for sword indicates the sword is assigned to a person and 0 indicates searching for person to assign the sword
	int i,j,count=0,winner=0,loop=0;
//	print(n,people);
	for(i=0;i<n;i=(i+1)%n)
	{
//		printf("\n* : %d",i);
		if(i==0)
		{
			count=0;
			for(j=0;j<n;j++)
			{
				if(people[j]==1)
				{
					count++;
					winner=j;
				}
			}
			
//			printf("\nCount : %d",count);
			if(count==1)
				return winner;
		}
			
		if(sword==0)
		{
			if(people[i]==1)
				sword=1;
		}else{
			if(people[i]==1)
			{
				people[i]=0;
				sword=0;
			}
		}
		
//		printf("\nSword : %d",sword);
//		print(n,people);
	}	
}

void print(int n,int arr[])
{
	int i=0;
	printf("\n\nPeople : ");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
}

void main()
{
	int n;
	printf("Enter number of people : ");
	scanf("%d",&n);
	
	int *people= (int*)malloc(sizeof(n));  
	
	initialize(n,people);
	printf("\n\nPerson %d is the winner",josephus(n,people)+1);
}
