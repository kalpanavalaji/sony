#include <stdio.h>
int main(int argc, char *argv[])
{
	int a,b,sum;
	int i; 
	if(argc<2)
	{
		printf("no args\n");
		return -1;
	}
	for(i=1; i<argc; i++)
	{
		printf("arg: %d\n",atoi(argv[i]));
	}
	
	return 0;
}

