#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *newnode,*head=NULL,*temp=NULL,*tail=NULL,*next=NULL,*prev=NULL,*new;
void creation()
{
    int n;
    printf("Enter the no of values u wish to enter:");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->next=NULL;
        newnode->prev=NULL;
        printf("Enter data for node %d : ",i);
        scanf("%d",&newnode->data);
        if(head==NULL)
        {
            head=newnode;
            tail=newnode;
        }
        else
        {
            tail->next=newnode;
            newnode->prev=tail;
            tail=newnode;
        }
    }  
    printf("Creation of Doubly Linked List is done!\n");
}

void insertAtBeg()
{
    new=(struct node*)malloc(sizeof(struct node));
    new->next=NULL;
    new->prev=NULL;
    printf("Enter data for inserting new node at beginning: ");
    scanf("%d",&new->data);
    new->next=head;
    if (head != NULL)
        head->prev = new;
    else
        tail = new;
    head=new;
    printf("Insertion of node at beginning is done!\n");
}

void insertAtPos()
{
    int pos;
    new=(struct node*)malloc(sizeof(struct node));
    temp=head;
    new->next=NULL;
    new->prev=NULL;
    printf("Enter the value of the position at which u wish to insert newnode: ");
    scanf("%d",&pos);
    printf("Enter data: ");
    scanf("%d",&new->data);
    if(pos==1)
    {
        insertAtBeg();
        return;
    }
    else
    {
    for(int i=1;i<pos-1;i++)
    {
        temp=temp->next;
    }
    new->prev=temp;
    new->next=temp->next;
    temp->next->prev=new;
    temp->next=new;
    }
    printf("Insertion of node at given position is done!\n");
}
void insertAtPrePos()
{
    int pos;
    new=(struct node*)malloc(sizeof(struct node));
    temp=head;
    new->next=NULL;
    new->prev=NULL;
    printf("Enter the value of the position at which u wish to insert newnode before the given position: ");
    scanf("%d",&pos);
    printf("Enter data: ");
    scanf("%d",&new->data);
    if(pos==1)
        insertAtBeg();
    else
    {
    for(int i=1;i<pos-2;i++)
    {
        temp=temp->next;
    }
    new->prev=temp;
    new->next=temp->next;
    temp->next->prev=new;
    temp->next=new;
    }
    printf("Insertion of node before the given position is done!\n");
}    
void display()
{
    temp=head;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
}
void deleteAtPos()
{
    int pos;
    printf("Enter the value of the position at which u wish to delete node: ");
    scanf("%d",&pos);
    temp=head;
    for(int i=1;i<pos;i++)
    {
        temp=temp->next;
    }
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    printf("Deletion of node at given pos is done!\n");
}
void deleteAtValue()
{
    int value;
    printf("Enter the value present in the node which u wish to delete: ");
    scanf("%d",&value);
    temp=head;
    while(temp!=NULL && temp->data!=value)
    {
        temp=temp->next;
    }
    if (temp == NULL)
    {
        printf("Value not found in the list.\n");
        return;
    }
    if (temp->prev == NULL)
    {
        head = temp->next;
        if (head != NULL)
            head->prev = NULL;
    }
    else
    {
        temp->prev->next = temp->next;
    }
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }
    free(temp);
    printf("Deletion of node at given value is done!\n");
}
int main()
{
    head=NULL;
    int choice;
    printf("1:Creation of nodes\n2:Insertion at begining\n3:Insertion at pos\n4:Insertion at position before the given position\n5:Deletion at pos\n6:Deletion of node at spec value\n7:Display\n8:Exit\n");
    choice=1;
    while(choice!=8)
    {
        switch(choice)
        {
            case 1:creation();break;
            case 2:insertAtBeg();break;
            case 3:insertAtPos();break;
            case 4:insertAtPrePos();break;
            case 5:deleteAtPos();break;
            case 6:deleteAtValue();break;
            case 7:display();break;
            default:printf("Invalid choice");
        }
        printf("Enter ur choice: ");
        scanf("%d",&choice);
    }
    printf("Exiting!\n");
    return 0;
}