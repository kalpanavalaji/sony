#include <stdio.h>
enum weekdays { monday=4, tuesday, wednesday, thursday, friday, saturday,sunday };
int main()
{
    enum weekdays day;
    day = monday;
	int i;
for(i=day;i<=sunday;i++)
{

    printf("day %d",i);
    
}
}
