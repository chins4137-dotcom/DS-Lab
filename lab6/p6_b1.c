#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *newnode=NULL;
struct node *front=NULL;
struct node *rear=NULL;

struct node* createNewNode()
{
    int value;
    printf("Enter Data: ");
    scanf("%d",&value);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=NULL;
    return newnode;
}

struct node* enqueue()
{
    createNewNode();
    if(rear==NULL)
    {
        front=newnode;
        rear=newnode;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
    }
    printf("\nInserted element %d",newnode->data);
}

struct node* dequeue()
{
    struct node* temp=NULL;
    if(front==NULL && rear==NULL)
    {
        printf("\nNothing to delete");
    }
    else
    {
        temp=front;
        printf("\nDeleted element %d",front->data);
        front=front->next;
        free(temp);
    }
}

void display()
{
    struct node* temp=front;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL");
}

int main()
{               
    int x;
    printf("\n------------Operations on Queue using Linked List--------------");
    printf("\nEnter\n1:Create Linked List\n2:Enqueue\n3:Dequeue\n4:Display\n5:exit\n");
    do
    {

        scanf("%d",&x);
        switch(x)
        {
            int value;
            case 1: createNewNode();
                    break;
            case 2: enqueue();
                    break;
            case 3: dequeue();
                    break;
            case 4: display();
                    break;
            case 5: printf("\nExit");
                    break;
            default: printf("\nEnter Valid value");

        }
    }while (x!=5);
}