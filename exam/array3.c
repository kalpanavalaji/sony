#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int rotatearray(int);
int size;
int *array;
int main() {
	int n,i;
	printf("enter the size of the array\n");
	scanf("%d",&size);
	printf("enter the no of rotation\n");
	scanf("%d",&n);
	array = malloc(size*sizeof(array));
	printf("enter the elements of the array\n");
	for(i=0;i<size;i++)
	{ 
		scanf("%d", &array[i]);
		//	printf("%d",array[i]);
	}
	rotatearray(n);
	free(array);
}
int rotatearray(int n)
{
	int i,j,temp;

	for(j=0;j<n;j++)
	{
		for(i=0;i<size-1;i++)
		{
			temp=array[i];
			array[i]=array[i+1];
			array[i+1]=temp;
			//	temp++;
		}
		//array[temp+1]=array[i];
	}

	for(i=0;i<size;i++)
	{	
		printf("%d",array[i]);	

	}

}
