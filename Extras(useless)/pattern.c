#include<stdio.h>
void main()
{
 int i,j,k=0;
 for(i=1;i<=17;i++)
 {
   for(j=1;j<=3;j++)
  {
   if((i-j)%4==0 || (j==2&&i%4==0))
   printf("*");
   else 
   printf(" ");
  }
  printf("\n");
 }
}