#include<stdio.h>
int main ()
{
int balance=5000;
int hardcode_acc=1000;
float tax;
int deposite;
int transfer;
int history;
int count=1;
int withdraw;
int op1=0,op2=0,op3=0;
printf("INITIAL BALANCE %d\n",balance);
do{ 
int n;
printf("press\n");
printf("1. Deposit money\n");
printf("2. Withdraw money\n");
printf("3. Check balance\n");
printf( "4. Transfer money\n");
printf ("5. View mini history\n");
printf("6. Exit\n");
scanf("%d",&n);
if(n!=5)
{
    if(count%3==1)
    {
        op1=n;
    }
    else if(count%3==2)
    {
        op2=n;
    }
    else if(count%3==0)
    {
        op3=n;
    }
}

switch (n)
{
case 1:
printf("ENTER THE DEPOSITE AMOUNT\n");
    scanf("%d",&deposite);
    if(deposite>0&&deposite<10000)
    { 
    printf("DEPOSITED MONEY %d\n",deposite);
    balance=balance+deposite;
    }
    else
    {
        printf("INVALID AMMOUNT\n");
    }
    break;
    case 2:
    printf("ENTER THE WITHDRAW AMOUNT\n");
    scanf("%d",&withdraw);
    if(withdraw>0&&withdraw<balance){ 
    printf("withdraw ammount%d",withdraw);
    balance=balance-withdraw;
    }
    else{ 
        printf("insufficient amount 50$ fine\n");
        balance=balance-50;
    }
    break;
    case 3:
    balance=balance+deposite;
    printf("YOUR BALANCEIS%d\n",balance);
    break;
    case 4:
    printf("ENTER THE TRANSFER AMOUNT\n");
    scanf("%d",&transfer);
    printf("TRANSFER AMOUNT IS %d",transfer);
    tax=transfer*0.02;
    hardcode_acc=hardcode_acc+(transfer-tax);
    printf("(2%% DEDUCTION BY THE BANK) YOUR BALANCE  =%d\n",hardcode_acc);
    break;
    case 5:
    printf("******HISTORY*****\n");
    if (op1==1)
        printf("DEPOSITED THE MONEY\n");
    else if (op1==2)
        printf("withdraw THE MONEY\n");
    else if (op1==3) 
       printf("BALANCE\n");
    else if (op1==4) 
       printf("TRANSFER THE MONEYD\n");
    else if (op1==5)
        printf("HISTORY\n");
    else if (op1==6)
        printf("EXIT\n");
    if (op3==1) 
       printf("DEPOSITED THE MONEY\n");
    else if (op2==2) 
       printf("withdraw THE MONEY\n");
    else if (op2==3) 
       printf("BALANCE\n");
    else if (op2==4) 
       printf("TRANSFERD THE MONEY\n");
    else if (op2==5) 
       printf("HISTORY\n");
    else if (op2==6) 
       printf("EXIT\n");
     if (op3==1)  
       printf("DEPOSITED THE MONEY\n");
    else if (op3==2)   
     printf("withdraw THE MONEY\n");
    else if (op3==3)  
      printf("BALANCE\n");
    else if (op3==4)  
      printf("TRANSFERD  THE MONEY\n");
    else if (op3==5)  
      printf("HISTORY\n");
    else if (op3==6)  
      printf("EXIT\n");
    break;
    case 6:
    printf("Exit\n");
    break;
}
if (n==6)
{
    break;
}
count++;
}
while(balance>0);

    return 0;
} 