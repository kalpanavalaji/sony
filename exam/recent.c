#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node *firstnode(struct node *,int);
struct node *insertion(struct node *,int);
void display(struct node *);
void findpos(struct node *,struct node *);
void merge(struct node *,struct node *,int);
struct node
{
	int data;
	struct node *next;
};
int main()
{
       struct node *head1=NULL,*head2=NULL;
	int value,list1,list2;
	printf("enter two set of linked lists\n");
        printf("enter first list nodes\n");
        scanf("%d",&list1);
        printf("insert first node\n");
        scanf("%d",&value);
        head1=firstnode(head1,value);
	int i=1;
        while(i<list1)
        {
                printf("insert nodes\n");
                scanf("%d",&value);
                head1=insertion(head1,value);
                i++;
        }
	int j=1;
        printf("enter second list nodes\n");
        scanf("%d",&list2);
        printf("insert first node\n");
        scanf("%d",&value);
        head2=firstnode(head2,value);
        while(j<list2)
        {
                printf("insert elements\n");
                scanf("%d",&value);
                head2=insertion(head2,value);
                j++;
        }
	display(head1);
	printf("\n");
        display(head2);
       // merge(head1,head2);
        //display(head2);
        //printf("\n");
        //findpos(head1,head2);
	int n,m,l,p,o,q,k,r;
	l=list1;
	p=list1-1;
	m=list1-2;
	o=1;
	q=2;
	r=0;
	printf("enter your choice\n");
	scanf("%d",&n);
	switch(n)
	{
	case 1:printf("checking for 1st  position\n");
		merge(head1,head2,o);
		printf("pass");
		break;
	case 2:printf("checking for 2nd position\n");
		merge(head1,head2,q);
		printf("pass");
		break;
	case 3:printf("checking for  position\n");
		merge(head1,head2,m);
		printf("pass");
		break;
	case 4:printf("checking for last before position\n");
		merge(head1,head2,p);
		printf("pass");
		break;
	case 5:printf("checking for last position\n");
		merge(head1,head2,l);
		printf("pass");
		break;
	case 6:printf("checking oth position\n");
		merge(head1,head2,r);
		printf("fail");
	default:printf("enter any  position\n");
		scanf("%d",&k);
		merge(head1,head2,k);
		printf("fail");
		break;
	}
//merge(head1,head2,pos);
display(head2);
printf("\n");
findpos(head1,head2);
}

struct node *firstnode(struct node *fpos,int value)
{
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=value;
	newnode->next=fpos;
	if(fpos==NULL)
	{
	fpos=newnode;
	}
	return fpos;
}

struct node *insertion(struct node *fpos,int value)
{
	struct node *newnode,*ptr;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=value;
	ptr=fpos;
	while(ptr->next!=NULL)
		ptr=ptr->next;
	ptr->next=newnode;
	newnode->next=NULL;
	return fpos;
}

void display(struct node *fpos)
{
        struct node *ptr;
        if(fpos==NULL)
        {
                printf("empty ll\n");
        }
        ptr=fpos;
        while(ptr!=NULL)
        {
                printf("%d",ptr->data);
                ptr=ptr->next;
        }
}

void findpos(struct node *head1,struct node *head2)
{
	struct node *pos2;
	pos2=head2;
	int i=0;
	while(head1!=NULL)
	{
		while(pos2!=NULL)
		{
			if(head1==pos2)
			{
				i=1;
				printf("%p\n",pos2);
				printf("%p\n",head1);
				printf("%d\n",head1->data);
				break;
			}
			else
			{
				pos2=pos2->next;
			}
			if(i==1)
				break;
		}
		pos2=head2;
		head1=head1->next;

	}

}
void merge(struct node *head1,struct node *head2,int pos)
{

	int i=0;
	//printf("enter the  value\n");
	//scanf("%d",&m);
	while(i!=pos-1)
	{
		head1=head1->next;
		i++;
	}
	while(head2->next!=NULL)
	head2=head2->next;
	head2->next=head1;
}


