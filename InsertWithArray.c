#include<stdio.h>
int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int arr[n+1];
    for(int i=0;i<n;i++)
    {
        printf("Enter element %d: ", i+1);
        scanf("%d",&arr[i]);
    }
    int pos,value;
    while(1)
    {
        printf("Enter Valid Position = ");
        scanf("%d",&pos);
        if(pos>=1 && pos<=n+1)
        {
            printf("Thank you for enter correct position!\n");
            break;
        }
        else
        {
            printf("Please enter correct position !\n");
        }
    }
    printf("Enter Value = ");
    scanf("%d",&value);
    n++;
    for(int i=n-1;i>=pos;i--)
    {
        arr[i]=arr[i-1];
    }
    arr[pos-1]=value;
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
