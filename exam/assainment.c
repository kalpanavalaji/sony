#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
int M_row,N_clm,tempM,tempN;
int sum,temp,temp1,i,j;
sum=0;
temp =0;
temp1 =0;
i=0;
j=0;

 printf("enter row size of matrix:1ton\n");
 scanf("%d" ,&M_row);
 if(M_row <=0)
{
 printf("invalid row number\n");
 exit(1);
}

 /**** checking for rows multiples of 3*****/
 if((M_row%3)){
 tempM = M_row+(3-(M_row%3));
 }
 else
 {
 tempM = M_row;
 }


 printf("enter colum size of matrix:1ton\n");
 scanf("%d", &N_clm);
 if(N_clm <=0)
{
 printf("invalid clumn numbr\n");
 exit(1);
}

 if((N_clm%3)){
 tempN = N_clm+(3-(N_clm%3));
 }
 else
 {
 tempN = N_clm;
 }

 int **p = (int**) malloc(tempM*sizeof(int*));/*memory declaration for rows*/

 for(int i=0;i<tempM;i++)
  {
 *(p+i) = (int*)malloc(tempN*sizeof(int));/*memory declaration for columns*/
  }	
 printf("enter elements of matrix");

 for(int i=0;i<M_row;i++)                   
        {
         for(int j=0;j<N_clm;j++)
	  {
		scanf("%d",&(*(*(p+i)+j)));
		
 	  }
	}

if(tempM > M_row) 
{
for(j=0;j<tempN;j++)
{	 
for(int i=M_row;i<tempM;i++)
	 {
	 
		 *(*(p+i)+j) = 1;
	 }
}
}
if(tempN > N_clm)
{
	for(i =0;i<tempM;i++)
	{
        for(int j=N_clm;j<tempN;j++)
	{
	  
	  *(*(p+i)+j) = 1;
	  
	}
}
}
else
{
/*do nothing*/
}
for(int i=0;i<tempM;i++)
{
for(int j=0;j<tempN;j++)
{
 printf("  %d  " ,p[i][j]);
}
printf("\n");
}
sum =0;
if(tempM==tempN)
{
for( i=0;i<tempM;i++)
{
        for( j=0;j<tempN;j++)
        {

                if(i==j)
                {
                sum = sum+ p[i][j];
                }



        }

}
printf("\n frwd diagonal sum is:%d\n" ,sum);

sum =0;
i=0;
for( j=tempN-1;j>=0;j--)
{
                sum = (sum+p[i++][j]);

}
printf("\n rev diagonal sum is:%d\n" ,sum);

}
else
{
printf("\n can not find diagonal for rectangle matrix\n ");

}

sum =0;
i=0;
j=0;
 while(i < tempM || j< tempN )
 {
	for(i=temp;i<tempM;i++)	
	{
		for( j=temp1;j<tempN;j++)
		{
			sum = (sum+ p[i][j]);
               	if( ( (j+1) % 3 )== 0)
		{
	        	break;
		}

		}
              
               if(( (i+1) % 3 )== 0)
		{
			 printf("\nsum is :%d \n" ,sum);
			sum=0;
                	if( (j+1) < tempN)
                	{
		 	temp1 = (temp1+3);
                	}
			else
			{
                 
			temp = (temp + 3);
                	temp1= 0;
			}
       			break; 
                }
	}		
}


}


