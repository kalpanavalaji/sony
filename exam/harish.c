#include<stdio.h>
#include<string.h>
int main()
{
	char str[50]="hello this is new world";
	int size=sizeof(str);
	int i,j=0;
	char temp;
	//fgets(str,size,stdin);
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]!=' ')
		{	
			str[i]=str[i]-32;

			if(j%2!=0)
			{
				while(str[i]!=' ')
				{
					//str[i]=str[i];
					i++;
				}
				i--;
				
			}
		continue;
		}
			
		j++;	
		
	}
	//str[i]='\0';
	printf("after converting lower to upper case:::%s\n",str);
	printf("enter a charecter for removing::\n");
	scanf("%c",&temp);



	for(i=0;str[i]!='\0';i++)
	{
		if(temp==str[i])
		{	
			str[i]=' ';	
		}	
	}
	printf("after removing of given charter:::%s\n",str);
}


//output::HELLO This IS New WORLD
