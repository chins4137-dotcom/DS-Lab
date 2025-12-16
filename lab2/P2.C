#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define N 100
int stack[N];
int top=-1;

void push(char x)
{
    if(top==N-1)
    printf("STACK OVERFLOW");
    else
    {
        top++;
        stack[top]=x;
    }
}
char pop()
{
    char ch;
    if(top==-1)
    {
        printf("STACK UNDERFLOW");
        return -1;
    }

    else
    {
        ch=stack[top];
        top--;
        return ch;
    } 
}

char peek()
{
    if(top==-1)
    {
        printf("STACK UNDERFLOW");
        return -1;
    }
    else
    return stack[top];
}

int precedence(char op)
{
    switch(op)
    {
        case '+':
        case '-':
        return 1;
        case '*':
        case '/':
        return 2;
        case '^':
        return 3;
        case '(':
        return 0;
    }
    return -1;   // added default return to avoid undefined behavior
}

int associativity(char ch)
{
    if(ch=='^')
    return 1;
    else
    return 0;
}

void infixtopostfix(char infix[],char postfix[])
{
    int i=0,k=0;
    char c;
    
    for(i=0;i<strlen(infix);i++)
    {
        c=infix[i];
        if(isalnum(c))
        postfix[k++]=c;
        else if(c=='(')
        push(c);
        else if(c==')')
        {
            while(peek()!='(')        // FIXED: was ')'
            {
                postfix[k++]=pop();
            }
            pop();
        }
        else
        {
            while((top!=-1 && 
                  (precedence(peek()) > precedence(c) ||     // FIXED
                  (precedence(peek()) == precedence(c) && associativity(c)==0))))  // FIXED
            {
                postfix[k++]=pop();
            }
            push(c);
        }
    }
    while(top!=-1)
    {
        postfix[k++]=pop();
    }
    postfix[k]='\0';
}

int main()
{
    char infix[N];
    char postfix[N];
    printf("Enter the Infix Expression: ");
    scanf("%s",infix);
    infixtopostfix(infix,postfix);
    printf("Postfix Expression :%s\n",postfix);
    return 0;
}
