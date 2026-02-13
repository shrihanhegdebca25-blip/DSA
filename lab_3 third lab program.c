#include<stdio.h>
void main()
{
    int a=0,b=1 ,c;
    printf("Enter a number\n");
    int n;
    scanf("%d",&n);
    printf("%d\t%d\t",a ,b);
    for(int i=0;i<=n;i++)
    {
        c=a+b;
        a=b;
        b=c;
        printf("%d\t",c);
    }

}
