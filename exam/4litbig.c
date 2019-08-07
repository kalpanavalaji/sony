#include<stdio.h>
int main()
{
	int n;
	printf("enter a number\n");
	scanf("%d",&n);
	char *alp=(char *)&n;
	if(*alp==(n&0x000000FF))
	{
		printf("little endian\n");
	}
	else
	{
		printf("big endian");
	}
}
