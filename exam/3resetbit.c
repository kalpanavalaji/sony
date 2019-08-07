#include<stdio.h>
int main()
{
int in,n,newnum;
printf("enter integer value\n");
scanf("%d",&in);
printf("enter position\n");
scanf("%d",&n);
newnum=(in&(~(1<<n)));
printf("%d",newnum);
}
