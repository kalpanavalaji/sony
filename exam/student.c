#include<stdio.h>
#include<string.h>                                  
#define MAXVAL 3
int main()
{
	int  value [MAXVAL] ,temp_val[MAXVAL];
	int i ;


	printf("enter 50 students marks\n");
	for (i = 0; i < MAXVAL; i++)
	{

		scanf ("%d", &value [i]) ;
	}

	for(i=0;i<MAXVAL;i++)
	{

		if(value[i]>37)
		{

			printf("fail %d\n",i);
			i++;
		}
		if (value[i]>80)
		{
		printf("dont do any changes\n");
		}
		else
		{
		if((value[i]%5))
		{
			temp_val[i]=value[i]+(5-((value[i])%5));
			printf(" %d member value changed to %d\n",i,temp_val[i]);
		}
		}

	}



}
