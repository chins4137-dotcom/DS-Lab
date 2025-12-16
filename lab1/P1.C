#include<stdio.h>
#include<stdlib.h>
#define M 5
int stack[M];
int top=-1;
void push()
{
    if(top==(M-1))
    printf("Stack overflow");
    else
    {
        int x;
        printf("Enter the element: ");
        scanf("%d",&x);
        top++;
        stack[top]=x;
    }
}
void pop()
{
    if(top==-1)
    printf("Stack underflow");
    else
    {
        int a;
        a=stack[top];
        top--;
        printf("%d is deleted",a);
    }
}
void peek()
{
    if(top==-1)
    printf("Stack underflow");
    else
    {
        printf("The top element is %d",stack[top]);
    }
}
void display()
{
    if(top==-1)
    printf("Stack underflow");
    else
    {
        printf("\nThe stack elements are:");
        for(int i=top;i>=0;i--)
        {
            printf("\n%d",stack[i]);
        }
    }
}
int main()
{
    int o;
    do
    {
        printf("\nChoose an operation\n1:push, 2:pop, 3:peek, 4:display\n");
        scanf("%d",&o);
        switch(o)
        {
            case 1:push();
                break;
            case 2:pop();
                break;
            case 3:peek();
                break;
            case 4:display();
                break;
            default: printf("\nInvalid value entered");
        }

    } while(o!=0);
   
}
