#include <stdio.h>
int main() 
{
    int n1, n2, i, j,k,product=1,temp=0,condition=0;
    int sum=0,total_sum=0;
    int smallest,largest;
    
    printf("ENTER THE STARTING NUMBER: ");
    scanf("%d",&n1);
    printf("ENTER THE ENDING NUMBER: ");
    scanf("%d",&n2);
    for(i = n1; i <= n2; i++)
     {
    printf("Showing The Table of %d\n", i);
    total_sum=total_sum+sum;
    sum =0;

     for(j = 1; j <= 10; j++)
      {
        temp=1;
        product=i*j;
        k=2;
        do
        {
            if (product%k==0)
            {
                temp=0;
                break;
            }
            k++;
        } while (k<=product/2);
        if(product%3==0&&product%5==0)
        {
            printf("SKIP\n");
        }
        else{ 
            if (temp==1)
                  printf(" %d x %d = *%d\n", i, j, product);// THIS WILL PRINT * SIGN WITHPRIME NUMBER 
            else      
            printf(" %d x %d = %d\n", i, j, product);
           
         } sum=sum+product;
          if(i==n1&&j==1)
            {
                smallest=product;
            }
            else if(i==n2&&j==10)
            {
                largest=product;
            }
       } 
       printf("SUM IS%d\n",sum);
        printf("\n"); 
    }
    printf("SMALLEST%d\n",smallest);
    printf("LARGEST %d\n",largest);
    printf("TOTAL SUM%d\n",total_sum);
    if(total_sum>10000)
    {
        printf("OVERFLOW DETECTED");
    }
    return 0;
}