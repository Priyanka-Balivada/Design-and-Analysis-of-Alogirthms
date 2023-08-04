#include<stdio.h>

struct node
{
	int data;
	struct node *next;
};
struct node* last=NULL;
struct node* head=NULL;

int josephus()
{
	int sword=0; //1 for sword indicates the sword is assigned to a person and 0 indicates searching for person to assign the sword
	struct node* temp=head;
	struct node* prev=NULL;
	while(temp)
	{
		if(temp==temp->next)
		{
			return temp->data;
		}
			
		if(sword==0)
		{
			prev=temp;
			sword=1;
		}else{
			prev->next=temp->next;
			free(temp);
			sword=0;
		}
		
		temp=prev->next;
		
//		printf("\nSword : %d",sword);
//		print(temp);
	}	
}

void insert(int x)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	if(head==NULL)
	{
		head=temp;
		temp->next=head;
		last=temp;
	}
	else
	{
		last->next=temp;
		last=last->next;
		temp->next=head;
	}
		
}

void print(struct node* head1)
{
	struct node* temp=head1;
	printf("\n\nPeople : ");
	printf("%d ",head1->data);
	temp=head1->next;
//	temp=head;
	while(temp!=head1)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
}

void main()
{
	int n,i;
	printf("Enter number of people : ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		insert(i+1);
//		print(head);
	}
	
	printf("\n\nPerson %d is the winner",josephus());
}
