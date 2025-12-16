#include <stdio.h>
#include<stdlib.h>
#include <string.h>
struct node
{
    int data;
    struct node *next;
};
struct node *temp=NULL,*head=NULL,*newnode,*new;
void insertAtBeginning();
void insertAtEnd();
void insertAtPos();
void display();

int main()
{
char ch[5];
int choice;
strcpy(ch,"yes");
while(strcmp(ch,"NO")!=0 && strcmp(ch,"no")!=0)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->next=NULL;
    printf("Enter Data: ");
    scanf("%d",&newnode->data);

    if(head==NULL)
    {
        head=newnode;
        temp=newnode;
    }
    else
    {
        temp->next=newnode;
        temp=newnode;    
    }
    printf("Do You wanna enter another node: ");
    scanf("%s",ch);
    
}
printf("Creation of nodes is done!\n");
printf("1:insert_at_beginning\n2:insert_at_end\n3:insert_at_pos\n4:diplay\n");
choice=4;

    while(choice!=0)
    {
        switch(choice)
        {
        case 1:
        insertAtBeginning();break;
        case 2:
        insertAtEnd();break;
        case 3:
        insertAtPos();break;
        case 4:
        display();break;
        default:
        printf("Exiting");break;           
        }
        printf("\nEnter ur choice: ");
        scanf("%d",&choice);
    }

}

void insertAtBeginning()
{
    temp=head;
    new=(struct node*)malloc(sizeof(struct node));
    new->next=NULL;
    printf("\nEnter Data:");
    scanf("%d",&new->data);
    new->next=temp;
    head=new;
    printf("Insertion of newnode is done at Beginning is done!");
}
void insertAtEnd()
{
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
        new=(struct node*)malloc(sizeof(struct node));
        new->next=NULL;
        printf("\nEnter Data: ");
        scanf("%d",&new->data);
        new->next=NULL;
        temp->next=new;
        printf("Insertion of newnode at end is done!");
}
void insertAtPos()
{
    int pos;
    printf("Enter the position u wish to add newnode: ");
    scanf("%d",&pos);
    temp=head;
    for(int i=1;i<pos-1;i++)
    {
        temp=temp->next;
    }
    new=(struct node*)malloc(sizeof(struct node));
    new->next=NULL;
    printf("Enter Data: ");
    scanf("%d",&new->data);
    new->next=temp->next;
    temp->next=new;
    printf("Insertion of newnode at given position is done!");
}
void display()
{
    temp=head;
    printf("\nElements of Linked list are: ");
    while(temp!=NULL)
    {
        printf("%d-> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}


                                                                               