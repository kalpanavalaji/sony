#include<stdio.h>
#include<stdlib.h>
int longdist(int arr[],int n)
{
	int arr2[n];
	int i,j,max=0;
	for(i=0;i<n;i++)
		arr2[i]=1;
	for(i=1;i<n;i++)
		for(j=0;j<i;j++)
			if(arr[i]<arr[j] && arr2[i]<arr2[j]+1)
				arr2[i]=arr2[j]+1;
	for(i=0;i<n;i++)
		if(max<arr2[i])
			max=arr2[i];

	return max;
}
int main()
{
	int ret;
	int arr[]={3,4,7,8,6};
	int n=sizeof(arr)/sizeof(arr[0]);
	ret=longdist(arr,n);
	printf("%d\n",ret);
}              
