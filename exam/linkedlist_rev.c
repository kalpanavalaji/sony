#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void insertion(int);
void display();
void reverse();
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

	
	reverse();
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

