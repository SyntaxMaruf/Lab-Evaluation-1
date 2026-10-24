#include<stdio.h>
int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter element %d:", i+1);
        scanf("%d",&arr[i]);
    }
    int pos;
    while(1)
    {
        printf("Enter Valid Position = ");
        scanf("%d",&pos);
        if(pos>=1 && pos<=n)
        {
            printf("Thank you for enter correct position!\n");
            break;
        }
        else
        {
            printf("Please enter correct position !\n");    
        }
    }
    for(int i=pos-1;i<n-1;i++)
    {
        arr[i]=arr[i+1];
    }
    for(int i=0;i<n-1;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}


