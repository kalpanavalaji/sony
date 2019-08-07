#include<stdio.h>
int main()
{ 
	 int a;
	printf("enter signed number between integer range");
	scanf("%d",&a);
	conversion(a);
}
void conversion(int num)
{
	unsigned int res;
	if(num<0)
	{
		res=2147483647+(2147483648+num)+1;
		printf("%u",res);
	}
	else
		printf("%u",num);
}
