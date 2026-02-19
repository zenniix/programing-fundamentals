#include<stdio.h>
int main ()
{
int i,j,n;
printf("ENTER THE HEIGHT ");
scanf("%d",&n);
if(n>=3)
{
char c1,c2,c3;
printf("FOR SINGLE DIMOND TYPE s AND FOR TWO OVERLAPPING TYPE t \n");
scanf(" %c",&c1);
if(c1=='t')
{
    goto label;
}
printf("SYMBOL TYPE * OR # \n");
scanf(" %c",&c2);
if(c2!='#'&&c2!='*')
{
  printf("you have entered a wrong symbol");
  return 0;
}

printf("FOR HOLLOW DIMOND PRINT y AND FOR FILLED PRINT n \n");
scanf(" %c",&c3);
label:
if (c1=='t')
{
for(i=1;i<=n;i++)
{
for(j=i;j<=n;j++)
{
    printf(" ");
}
for(j=1;j<=(2*i-1);j++)
{
     if(j==1||j==(2*i-1))
      {
        printf("*");
      }
      else 
      {
        printf("#");
      }
}
printf("\n");
}
for(i=n-1;i>=1;i--)
{
    for(j=n;j>=i;j--)
    {
        printf(" ");
    }
    for(j=1;j<=(2*i-1);j++)
    {
      if(j==1||j==(2*i-1))
      {
        printf("*");
      }
      else 
      {
        printf("#");
      }
    }
    printf("\n");
}
}
else if(c2=='#'&&c3=='y'&&c1=='s')
{
for(i=1;i<=n;i++)
{
for(j=i;j<=n;j++)
{
    printf(" ");
}
for(j=1;j<=(2*i-1);j++)
{
     if(j==1||j==(2*i-1))
      {
        printf("#");
      }
      else 
      {
        printf(" ");
      }
}
printf("\n");
}
for(i=n-1;i>=1;i--)
{
    for(j=n;j>=i;j--)
    {
        printf(" ");
    }
    for(j=1;j<=(2*i-1);j++)
    {
      if(j==1||j==(2*i-1))
      {
        printf("#");
      }
      else 
      {
        printf(" ");
      }
    }
    printf("\n");
}
}
else if (c2=='*'&&c3=='y'&&c1=='s')
{
for(i=1;i<=n;i++)
{
for(j=i;j<=n;j++)
{
    printf(" ");
}
for(j=1;j<=(2*i-1);j++)
{
     if(j==1||j==(2*i-1))
      {
        printf("*");
      }
      else 
      {
        printf(" ");
      }
}
printf("\n");
}
for(i=n-1;i>=1;i--)
{
    for(j=n;j>=i;j--)
    {
        printf(" ");
    }
    for(j=1;j<=(2*i-1);j++)
    {
      if(j==1||j==(2*i-1))
      {
        printf("*");
      }
      else 
      {
        printf(" ");
      }
    }
    printf("\n");
}
}
else if(c2=='#'&&c3=='n'&&c1=='s')
{
for(i=1;i<=n;i++)
{
for(j=i;j<=n;j++)
{
    printf(" ");
}
for(j=1;j<=(2*i-1);j++)
{
    
        printf("*");
}
printf("\n");
}
for(i=n-1;i>=1;i--)
{
    for(j=n;j>=i;j--)
    {
        printf(" ");
    }
    for(j=1;j<=(2*i-1);j++)
    {
      {
        printf("*");
      }
     
    }
    printf("\n");
}
}
else if(c2=='*'&&c3=='n'&&c1=='s')
{
for(i=1;i<=n;i++)
{
for(j=i;j<=n;j++)
{
    printf(" ");
}
for(j=1;j<=(2*i-1);j++)
{
    
        printf("*");
      
      
}
printf("\n");
}
for(i=n-1;i>=1;i--)
{
    for(j=n;j>=i;j--)
    {
        printf(" ");
    }
    for(j=1;j<=(2*i-1);j++)
    {
      {
        printf("*");
      }
     
    }
    printf("\n");
}
}
}
else
{
    printf("INVALID NUMBER");
}
  return 0;
}