#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *temp=NULL,*head,*newnode,*i=NULL,*j=NULL,*n1,*n2,*prev=NULL;

struct node* creation()
{
    int n;
    struct node *head_local=NULL;
    printf("Enter the no of values u wish to enter: ");
    scanf("%d",&n);
    
    for(int i=1;i<=n;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->next=NULL;
        printf("Enter Data for node %d : ",i);
        scanf("%d",&newnode->data);
        if(head_local==NULL)
        {
            head_local=newnode;
            temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
    }

    temp=head_local;
    printf("Linked List: ");
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
    head=head_local;
    return head_local;
}

void  sorting()
{
    int tempdata;
    for(i=head;i!=NULL;i=i->next)
    {
        for(j=i->next;j!=NULL;j=j->next)
        {
            if(i->data>j->data)
            {
            tempdata=i->data;
            i->data=j->data;
            j->data=tempdata;
            }

        }
    }
    temp=head;
    printf("Linked List after Sorting: ");
    while(temp!=NULL)
    {
    printf("%d->",temp->data);
    temp=temp->next;
    }
    printf("NULL\n");
}

void reversing()
{
    struct node *curr=NULL;
    curr=head;
    while(curr!=NULL)
    {
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    head=prev;
    temp=head;
    printf("Linked List after REVERSING: ");
    while(temp!=NULL)
    {
    printf("%d->",temp->data);
    temp=temp->next;
    }
    printf("NULL\n");
}

struct node* concatination()
{
    struct node *head1,*head2;
    printf("Create List1: ");
    head1=creation();
    printf("Create List2: ");
    head2=creation();
    temp=head1;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=head2;
    temp=head1;
    printf("Linked List after Concatination: ");
    if(head1==NULL)
        return head2;
    while(temp!=NULL)
    {
    printf("%d->",temp->data);
    temp=temp->next;
    }
    printf("NULL\n");
    head=head1;

}
int main()
{
    int ch;
    printf("Enter\n1:Creation\n2:Sorting\n3:Reversing\n4:Concatination\n0:Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&ch);
    while(ch!=0)
    {
        switch(ch)
        {
            case 1:creation();break;
            case 2:sorting();break;
            case 3:reversing();break;
            case 4:concatination();break;
            default:printf("Incorrect Choice");
        }
        printf("Enter your choice: ");
        scanf("%d",&ch);
    }
    printf("Exiting!");
}
