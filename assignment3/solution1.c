#include<stdio.h>
int main ()
{
int n,i=0,j,y;
printf("Enter the number");
scanf("%d",&n);
int x=n;
int rep=0;
while (x!=1)
{
 if(x%2==0)
 {
    x=x/2;
 }   
 else
 {
    x=x*3+1;
 }
 rep++;
}
while(i<rep)
{ 
y=n;
j=0;
while (j<(rep-i))
{
    if(y%2==0)
    {
        y=y/2;
    }
    else
    {
        y=y*3+1;
    }
    j++;
}
printf("%d ",y);
i++;
}
printf("%d",n);




    return 0;
}