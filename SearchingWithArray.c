#include<stdio.h>
int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int arr[n];
    for (int i=0;i<n;i++)
    {
        printf("Enter element %d: ", i+1);
        scanf("%d",&arr[i]);
    }
    int search, found = 0;
    printf("Enter the searching element: ");
    scanf("%d",&search);
    for(int i=0;i<n;i++)
    {
        if(arr[i] == search)
        {
            found = 1;
            break;
        }
    }
    if(found)
    {
        printf("Element %d is found in the array.\n", search);
    }
    else
    {
        printf("Element %d is not found in the array.\n", search);
    }
     
  return 0;
}