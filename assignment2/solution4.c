#include<stdio.h>
int main()
{
    char ch;
    int num;
    printf("Enter First Letter of your Name=\n");
    scanf(" %c",&ch);
    printf("Enter The ID=\n");
    scanf("%d",&num);
  // coverting the number into indiviual digits.  
    int x=num%10;
    int y=(num/10)%10;
    int z=num/100;
    char new_ch;
    int digit1=z+5;
    int digit2=y+5;
    int digit3=x+5;
    int digit4=z-2;
    int digit5=y-2;
    int digit6=x-2;
//using these if else for the number greater then 9(two digit number).
if(digit1>9)
{
    digit1=digit1-10;
}
else if (digit1<0)
{
    digit1=digit1+10;
}

if(digit2>9)
{
    digit2=digit2-10;
}
else if (digit2<0)
{
    digit2=digit2+10;
}
 if(digit3>9)
{
    digit3=digit3-10;
}
else if (digit3<0)
{
    digit3=digit3+10;
}
if(digit4>9)
{
    digit4=digit4-10;
}
else if (digit4<0)
{
    digit4=digit4+10;
}
 if(digit5>9)
{
    digit5=digit5-10;
}
else if (digit5<0)
{
    digit5=digit5+10;
}

if(digit6>9)
{
    digit6=digit6-10;
}
else if (digit6<0)
{
    digit6=digit6+10;
}
// changing the first letter of user's name into its reverse alphabet.
    switch(ch)
    {
        case 'a':
        case 'A':
        new_ch = 'Z';
        break;
        case 'b':
        case 'B':
        new_ch = 'Y';
        break;
        case 'c':
        case 'C':
        new_ch = 'X';
        break;
        case 'd':
        case 'D':
        new_ch = 'W';
        break;
        case 'e':
        case 'E':
        new_ch = 'V';
        break;
        case 'f':
        case 'F':
        new_ch = 'U';
        break;
        case 'g':
        case 'G':
        new_ch = 'T';
        break;
        case 'h':
        case 'H':
        new_ch = 'S';
        break;
        case 'i':
        case 'I':
        new_ch = 'R';
        break;
        case 'j':
        case 'J':
        new_ch = 'Q';
        break;
        case 'k':
        case 'K':
        new_ch = 'P';
        break;
        case 'l':
        case 'L':
        new_ch = 'O';
        break;
        case 'm':
        case 'M':
        new_ch = 'N';
        break;
        case 'n':
        case 'N':
        new_ch = 'M';
        break;
        case 'o':
        case 'O':
        new_ch = 'L';
        break;
        case 'p':
        case 'P':
        new_ch = 'K';
        break;
        case 'q':
        case 'Q':
        new_ch = 'J';
        break;
        case 'r':
        case 'R':
        new_ch = 'I';
        break;
        case 's':
        case 'S':
        new_ch = 'H';
        break;
        case 't':
        case 'T':
        new_ch = 'G';
        break;
        case 'u':
        case 'U':
        new_ch = 'F';
        break;
        case 'v':
        case 'V':
        new_ch = 'E';
        break;
        case 'w':
        case 'W':
        new_ch = 'D';
        break;
        case 'x':
        case 'X':
        new_ch = 'C';
        break;
        case 'y':
        case 'Y':
        new_ch = 'B';
        break;
        case 'z':
        case 'Z':
        
        new_ch = 'A';
        break; 
    }
    // ENCODING 
    if(ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U'||ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
    {
        printf("Encode =%c%d%d%d",new_ch,digit1,digit2,digit3);
        
    }
    else 
    {
        
        printf("Encode= %c%d%d%d",new_ch,digit4,digit5,digit6);
    }

    //DECODING.
    if(ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U'||ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
    {
        printf("\nDecode =%c%d%d%d\n",ch,digit1+5,digit2+5,digit3+5);
    }
    else
    {
        printf("\nDecode= %c%d%d%d\n",ch,digit4+2,digit5+2,digit6+2);
    }
    return 0;
}