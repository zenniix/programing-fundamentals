#include<stdio.h>
int main ()
{
int consumer_type;
printf("ENTER THE TYPE OF CONSUMER\n 1--> Domestic\n 2-->Comercial\n 3-->Industrial\n");
scanf("%d",&consumer_type);
switch(consumer_type)
{ 
    case 1 :
    printf("YOUR CONNECTION TYPE IS DOMESTIC\n");
    break;
    case 2:
    printf("YOUR CONNECTION TYPE IS COMERCIAL\n");
    break;
    case 3 :
    printf("YOUR CONNECTION TYPE IS INDUSRIAL\n");
    break;
}

int unit_consumed;
printf("ENTER THE CONSUMED UNITS \n");
scanf("%d",&unit_consumed);
if(consumer_type==1)
{
    if(unit_consumed<=100)
    {
        printf("YOUR BILL IS = RS%d",unit_consumed*5);
    }
    else if (unit_consumed>100&&unit_consumed<=300)
    {
        printf("YOUR BILL IS = RS%d",unit_consumed*7);
    }
    else if (unit_consumed >300)
    {
        printf("YOUR BILL IS = RS%d",unit_consumed*10);
    }
}
if(consumer_type==2)
{
    if(unit_consumed<=200)
    {
        printf("YOUR BILL IS = RS%d",unit_consumed*8);
    }
    else if (unit_consumed>200&&unit_consumed<=500)
    {
        printf("YOUR BILL IS = RS%d",unit_consumed*12);
    }
    else if (unit_consumed >500)
    {
        printf("YOUR BILL IS = RS%d",unit_consumed*15);
    }
}
if(consumer_type==3)
{
    if(unit_consumed<=500)
    {
        printf("YOUR BILL IS = RS%d",unit_consumed*15);
    }
    else if (unit_consumed>500 && unit_consumed<=1000)
    {
        printf("YOUR BILL IS = RS%d",unit_consumed*20);
        
    }
    else if (unit_consumed >1000)
    {    printf("BILL WITHOUT SURCASE CHARGE=RS %d\n",unit_consumed*20);
        float SURCASE = (float) unit_consumed*20+(0.1*((float) unit_consumed*20));
        printf("BILL WITH SURCASE CHARGE  10%% =RS %f\n",SURCASE);

    }
}

return 0;
}