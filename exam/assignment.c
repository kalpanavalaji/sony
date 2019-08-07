#include<stdio.h>
#include<limits.h>
int main()
{ 
	 int a;
	 printf("enter signed number\n");
	 scanf("%d",&a);
	 unsignedconversion(a);
	 unsigned int b;
	 printf("enter unsigned number\n");
	 scanf("%d",&b);
	 signedconversion(b);
}
void unsignedconversion(int num)
{
	unsigned int res;
	if(num<0)
	{
		//res=2147483647+(2147483648+num)+1;
		res=UINT_MAX+num+1;
		printf("%u\n",res);
	}
	else
		printf("%u",num);
}
void signedconversion(unsigned int num)
{
         int res;
        if(num>=0)
        {
                
		res=INT_MAX+num-INT_MIN+1;
                printf("%d\n",res);
        }
        else
                printf("%d",num);
}


