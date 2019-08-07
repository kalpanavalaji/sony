#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void insertion(int);
void display();
void reverse();
void findevenodd();
void evenfunction();
void oddfunction();
struct node
{
	int data;
	struct node *next;
}*head = NULL;

void main()
{
	int value,i,n;
	printf("enter no of values to be insert\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter value to be inser\n");
		scanf("%d",&value);
		insertion(value);
	}

	findevenodd();
	//reverse();
	display();

}
void insertion(int value)
{
	struct node *newNode;
	newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = value;
	newNode->next = NULL;
	if(head == NULL)
		head = newNode;
	else
	{
		struct node *temp = head;
		while(temp->next != NULL)
			temp = temp->next;
		temp->next = newNode;
	}
	//   printf("node value  %d inserted\n",value);
}
void display()
{
	if(head == NULL)
	{
		printf("empty list\n");
	}
	else
	{
		struct node *temp = head;
		printf("no of elements are\n");
		while(temp->next != NULL)
		{
			printf("%d",temp->data);
			temp = temp->next;
		}
		printf("%d",temp->data);
	}
}
void reverse()
{
	if(head == NULL)
	{
		printf("empty list\n");
	}
	else
	{
		struct node *temp = head;
		struct node *prev = NULL, *nxt = NULL; 
		while (temp!= NULL) 
		{ 
			nxt = temp->next;
			temp->next = prev;
			prev = temp; 
			temp = nxt; 
		} 
		head = prev; 
	}
}
void findevenodd()
{
	struct node *fast=head;
	struct node *slow=head;
	struct node *prev=head;

	while(fast->next->next!=NULL)
	{
		fast=fast->next->next;
		prev=slow;
		slow=slow->next;            
		if(fast->next==NULL)
		{
			printf("odd");
			break;
		}
		if(fast->next->next==NULL)
		{
			printf("even");
			break;
		}
		//printf("%d in loop fast\n",fast->data);
		//printf("%d in loop slow",slow->data);
	}
	printf("%d  fast\n ",fast->data);
	printf("%d slow",slow->data);
	printf("%d prev",prev->data);
	
}
void evenfunction()
{
	struct node *ptr;
	struct node *temp=head;
	ptr=slow->next;
	slow->next=NULL;
	reverse(head);
	reverse(ptr);
	while(temp->next !=NULL)
	{
	temp=temp->next;
	}
	temp->next=ptr;
}
void oddfunction()
{
	struct node *temp;
	struct node *mid=slow;
	struct node *ptr=slow->next;
	slow->next=NULL;
	prev->next=NULL;
	reverse(head);
	reverse(ptr);
	while(temp->next !=NULL)
	{
	temp=temp->next;
	}
	temp->next=mid;
	mid->next=ptr;
}

