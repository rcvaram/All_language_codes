//This program calculates factorial of a number using recursion.
#include<stdio.h>
int fact(int);
int main()
{
  int n,res;
  printf("Enter the number whose factorial you want to print : ");
  scanf("%d",&n);
  res = fact(n);
  printf("\n\nAnswer -> %d",res);
  return 0;
}
int fact(int a)
{
  if(a==0)
    return 1;
  else
    return a*(a-1);
}
