#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,i,j,k;
    printf("Enter number of elements in the array\n");
     scanf("%d",&n); //Enter the number of integers
    int arr[n];
    printf("Enter the elements of the array\n");
    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
    printf("Enter a number to be searched\n");
    scanf("%d",&k); //k is the number to be searched
    for(i=0;i<n;i++)
    {
        if(k == arr[i])
        {
            printf("Number found! at %d position",i+1);
            break;
        }
        else
        continue;
    }
    if( i == n)
    printf("Number not found");
    
    return 0;
}
