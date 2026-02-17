#include<stdio.h>
int main(){

int Final,Attendence,Internal;
printf("Enter Attendence=\n");
scanf("%d",&Attendence);
printf("Enter Internal\n");
scanf("%d",&Internal);
printf("Enter Final\n");
scanf("%d",&Final);


if(Attendence>=75 && Internal>=40){
    if(Final>=90)
    {
        printf("GRADE A+\n");
    
    if (Attendence>=90)
    {
        printf("Scholarship 100%%");
    }
}
    else {
        if(Final>=80 && Final<90)
        {
            printf("GRADE A\n");
        
        if(Attendence>=85)
        {
            printf("scholarship 50%%\n");
        }
        }
        else {
            if ( Final>=70 && Final<80)  {
                printf("GRADE B\n");

            }
            else {
                if( Final>=60 && Final<70){
                    printf("GRADE C\n");
                }
                else {
                    if(Final>=50 && Final<60){
                        printf("Grade D\n");
                    }
                    else{
                        if (Final<50){
                            printf("FAIL\n");
                        }
                    }
                  printf("NOT ELIGIBLE FOR SCHOLARSHIP");
                }
               printf("NOT ELIGIBLE FOR SCHOLARSHIP");
            }
            printf("NOT ELIGIBLE FOR SCHOLARSHIP");
        }
    }
}
else 
{
    printf("NOT ELIGIBLE");
}
return 0;
}