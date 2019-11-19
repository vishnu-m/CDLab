#include<stdio.h>
#include<string.h>
#include<ctype.h>
 
char input[10];
int i,error,ch=0;
void E();
void T();
void Eprime();
void Tprime();
void F(); 
void main()
{
    do{
        i=0;
        ch=0;
        error=0;
        printf("Enter an arithmetic expression   :  "); // Eg: a+a*a
        scanf("%s",input);
        E();
        if(strlen(input)==i&&error==0)
            printf("Accepted..!!!\n");
        else 
            printf("Rejected..!!!\n");
        printf("Enter 0 to exit, 1 to continue : ");
        scanf("%d",&ch);
    }while(ch!=0);
}
void E()
{
    T();
    Eprime();
}
void Eprime()
{
    if(input[i]=='+')
    {
        i++;
        T();
        Eprime();
    }
}
void T()
{
    F();
    Tprime();
}

void Tprime()
{
    if(input[i]=='*')
    {
        i++;
        F();
        Tprime();
    }
}
void F()
{
    if(isalnum(input[i]))
        i++;
    else if(input[i]=='(') {
        i++;
        E();
        if(input[i]==')')
            i++;
        else error=1;
    }
    
    else error=1;
}
    