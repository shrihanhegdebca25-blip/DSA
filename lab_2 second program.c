#include<stdio.h>
int fact(int n)
{
    if(n==0)
    {
        return 1;
    }
    else
    {
        return n*fact(n-1);
    }
}
void main()
{
    int a;
    printf("Enter a number");
    scanf("%d",&a);
    printf("The factorial is %d", fact(a));
}

