#include<stdio.h>
struct field
{
unsigned int a:3;
unsigned int b:2;
};
int main()
{
struct field f;
f.a=7;
f.b=2;
printf("%d %d",f.a,f.b);
}
