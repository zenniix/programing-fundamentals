#include<stdio.h>
int main(){

int num,sum;
printf("enter the number\n");
scanf("%d",&num);

int a=num%10;
int b=(num/10)%10;
int c=(num/100)%10;
int d=num/1000;
 sum= a*1000+b*100+c*10+d;
int e=b+c;
if(sum==num)
{

    if (e == 2)
    {
        printf("SPECIAL PALINDRONE");
    }
    else 
    {
        printf("NOT A SPECIAL PALINDRONE");
    }
}
else
{
    printf("INVALID BECAUSE IT IS NOT EVEN A PALINDRONE.");
}
 return 0;
}