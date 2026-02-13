#include<stdio.h>
void main()
{
    int a;
    printf("Enter the size of the array");
    scanf("%d",&a);
    int arr[a];
    printf("Enter the array elements\n");
    for(int i=0;i<a;i++)
    {
        scanf("%d",&arr[i]);
    }

    printf(" the array elements are\n");
    for(int i=0;i<a;i++)
    {
        printf("%d\n",arr[i]);
    }

    int lar=arr[0];
    int sma=arr[0];

    for(int i=0;i<a;i++)
    {
        if(arr[i]>lar)
        {
            lar=arr[i];
        }
        if(arr[i]<sma)
        {
            sma=arr[i];
        }
    }
    printf("The largest number is %d\n",lar);
    printf("The smallest  number is %d\n",sma);


}
