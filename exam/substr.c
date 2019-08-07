#include <stdio.h>
#include <string.h> 
int counter(char * str, char * Search);
int main()
{
	char str[100];
	char Search[20];
	int count;
	printf("enter string: ");
	gets(str);
	printf("enter sub string");
	gets(Search);
	count = counter(str, Search);
	printf("total %s : %d", Search, count);
	return 0;
}

int counter(char * str, char * Search)
{
	int i, j, k, count;
	int len1, len2;
	len1 = strlen(str);      
	len2 = strlen(Search); 
	count = 0;
	for(i=0; i <=len1-len2; i++)
	{
		k = 1;
		for(j=0; j<len2; j++)
		{
			if(str[i + j] != Search[j])
			{
				k = 0;
				break;
			}
		}

		if(k == 1)
		{
			count++;
		}
	}

	return count;
}
