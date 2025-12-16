#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *newnode=NULL;
struct node *top=NULL;

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

struct node* push()
{
    createNewNode();
    if(top==NULL)
    {
        top=newnode;
    }
    else
    {
        newnode->next=top;
        top=newnode;
    }
    printf("\nInserted element %d",newnode->data);
}

struct node* pop()
{
    struct node* temp=NULL;
    if(top==NULL)
    {
        printf("\nNothing to delete");
    }
    else
    {
        temp=top;
        printf("\nDeleted element %d",top->data);
        top=top->next;
        free(temp);
    }
}

void display()
{
    struct node* temp=top;
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
    do
    {
        printf("\n------------Operations on Stack using Linked List--------------");
        printf("\nEnter\n1:Create Linked List\n2:Push\n3:Pop\n4:Display\n5:exit\n");
        scanf("%d",&x);
        switch(x)
        {
            int value;
            case 1: createNewNode();
                    break;
            case 2: push();
                    break;
            case 3: pop();
                    break;
            case 4: display();
                    break;
            case 5: printf("\nExit");
                    break;
            default: printf("\nEnter Valid value");

        }
    }while (x!=5);
}