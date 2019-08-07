#include <stdio.h>
    void main()
    {
 
        int arr[10], arr2[10];
        int i, j,n,m;
 	printf("Enter the size of array");
        scanf("%d", &n);
	m=n;
 	printf("Enter the elements of the array n");
        for (i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
           
        }
	for(j=0;j<m;j++)
	{
	arr2[j]=arr[n-1];
	printf("%d",arr2[j]);
 	n--;
      }
 }
   
