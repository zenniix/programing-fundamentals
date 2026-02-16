#include<stdio.h>
#include<time.h>
int main (){


    printf("*****************************************\n");
    printf("WELCONME TO SMART UTILITY & SHOPPING HUB\n");
    printf("*****************************************\n");

    time_t tm;
    time(&tm);
    printf("Current Date/Time = %s", ctime(&tm));

    printf("----Grocery Section----");

    printf("PRICE (PER KG)\n");
    printf("Rice=300\nSugar=200\nPotatoes=150\nApples=400\n");
    int req_quantity1,req_quantity2,req_quantity3,req_quantity4;
    printf("Enter Your Required Quantity Of Rice in KG:");
    scanf("%d",&req_quantity1);
    printf("Price =%d\n",req_quantity1*300);
    printf("Enter Your Required Quantity Of Sugar in KG:");
    scanf("%d",&req_quantity2);
    printf("Price =%d\n",req_quantity2*200);
    printf("Enter Your Required Quantity Of Potatoes in KG:");
    scanf("%d",&req_quantity3);
    printf("Price =%d\n",req_quantity3*150);
    printf("Enter Your Required Quantity Of Apples in KG:");
    scanf("%d",&req_quantity4);
    printf("Price =%d\n",req_quantity4*400);
    int grand_total=req_quantity1*300+req_quantity2*200+req_quantity3*150+req_quantity4*400;
    printf("Grocery Subtotal=%d\n",grand_total);
    printf("...............................................\n");
    printf("Grand Total=%d$\n",grand_total);
    int ammount_paid;
    printf("Ammount Paid $=\n");
    scanf("%d",&ammount_paid);
    int balance_returned=ammount_paid-grand_total;
    printf("Balanced Returned=%d\n",balance_returned);
    printf("NOTES\n");
   
    int N1000 = balance_returned /1000;
    balance_returned %=1000;

    int N500 = balance_returned / 500;
    balance_returned %= 500;

    int N100 = balance_returned / 100;
    balance_returned%= 100;

   int N50 = balance_returned/ 50;
balance_returned %= 50;

int N10 = balance_returned/ 10;
balance_returned %= 10;
int N5 = balance_returned/ 5;
balance_returned %= 5;

int N2 = balance_returned/ 2;
balance_returned %= 2;

  printf("\n1000=%d",N1000);
    printf("\n500=%d",N500);
    printf("\n100=%d",N100);
printf("\n50=%d",N50);
printf("\n10=%d",N10);
    printf("\n5=%d",N5);
    printf("\n2=%d\n",N2);

    printf("----------------------------------------\n");
    printf(" THANK YOU FOR USING SMART HUB!");

    return 0;
}