# define N 5
#include <stdio.h>
int queue[N];
int front=-1,rear=-1;

void enqueue()
{
    int n;
    printf("Enter the element: ");
    scanf("%d",&n);
    if(rear==N-1)
    {
        printf("Queue Overflow\n");
        printf("OOPS!! Insertion cannot be done anymore");
    }
    else if(front==-1&&rear==-1)
    {
        front=rear=0;
        queue[rear]=n;
        rear++;
    }
    else
    {
        rear++;
        queue[rear]=n;
    }
}

void dequeue()
{
    if(front==-1 && rear==-1)
    {
        printf("\nQueue underflow");
    }
    else if(front==rear)
    {
        printf("\npopped element : %d",queue[front]);
        front=rear=-1;
    }
    else
    {
        printf("\npopped element: %d",queue[front]);
        front++;
    }
}

void display()
{
    if(front==-1 && rear==-1)
    {
        printf("Queue underflow\n");
    }
    else
    {
        printf("\nElements from top of the Queue are : ");
        for(int i=front;i<=rear;i++)
        {
            printf("%d ",queue[i]);
        }
    }
}

int main()
{
    int ch;
    ch=1;
    while(ch!=0)
    {
        printf("\nInsert :1,Delete :2,Display :3,Exit :0 ");
        printf("\nEnter ur choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            enqueue();break;
            case 2:
            dequeue();break;
            case 3:
            display();break;
            case 0:
            printf("Exiting");break;
            default:
            printf("Invalid choice");
            break;
        }
    }
}