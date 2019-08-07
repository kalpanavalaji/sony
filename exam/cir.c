#include<stdio.h>
int main()
{
	int arr1[20],arr2[10],n,val,i,j=1,k=0,m,l=0,lastval;
	printf("enter n number\n");
	scanf("%d",&n);
	printf("enter array values\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr1[i]);
	}
	for(i=0;i<n;i++)
	{
		if(arr1[i]>arr1[i+1])
		{
			j++;

			if((l==0)&(i+1==n-1))
			{
				l=1;
				m=i+1;
				i=-1;
				if(arr1[m]>=arr1[0])
				{
					j++;
					
				}
			}
			
		}
		if(arr1[i]<=arr1[i+1])
		{
		 	if((l==0)&(i+1==n-1))
                        {
                                l=1;
                                m=i+1;
                                i=0;
                                if(arr1[m]>=arr1[i])
                                {
                                        j++;
                                }
			}
			arr2[k]=j;
			k++;
			j=1;
		}

	}
	for(i=0;i<k;i++)
	{
	printf("all %d",arr2[i]);
	}
	lastval=arr2[0];
	for(i=0;i<k-1;i++)
	{
		if(arr2[i]>=lastval)
		{
			lastval=arr2[i];
			
			
		}
	}
	printf("last val=%d\n",lastval);
}
