#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
   int data;
   int *next;
}*head= NULL;
void push(int);
void pop();
void display();
void main()
{
   int choice, value;
//   clrscr();
   while(1)
	{
      printf("menu\n");
      printf("1.Push 2.Pop 3.display4.Exit\n");
      printf("Enter your choice");
      scanf("%d",&choice);
      switch(choice)
	{
	 case 1: printf("Enter the value");
		 scanf("%d", &value);
		 push(value);
		 break;
	 case 2: pop(); 
		 break;
	 case 3: display(); 
		 break;
	 case 4: exit(0);
	 default:printf("please choice correctly\n");
      }
   }
}
void push(int value)
{
   struct node *newNode;
   newNode=(struct node*)malloc(sizeof(struct node));
   newNode->data = value;
   if(head==NULL)
      newNode->next=NULL;
   else
      newNode->next=head;
   head=newNode;
   printf("insertion is Success\n");
}
void pop()
{
   if(head==NULL)
      printf("Stack is Empty\n");
   	else
	{
      struct node *temp=head;
      printf("deleted element %d",temp->data);
      head=temp->next;
      free(temp);
   }
}
void display()
{
   if(head==NULL)
      printf("Stack is Empty\n");
   else
	{
      struct node *temp=head;
      while(temp->next!=NULL)
	{
	 printf("%d",temp->data);
	 temp=temp->next;
      }
      printf("%d",temp->data);
   }
}    
    
