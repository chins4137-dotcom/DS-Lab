#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int data;
    struct node *next;
};
struct node *temp=NULL,*head=NULL,*prev=NULL,*newnode;
void creation()
{
    char ch[5];
    strcpy(ch,"yes");
    while(strcmp(ch,"no")!=0 && strcmp(ch,"NO")!=0)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->next=NULL;
        printf("Enter data: ");
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
        printf("Would u like to add another node(yes/no): ");
        scanf("%s",ch);
    }

}
void deleteAtBegining()
{
    temp=head;
    prev=NULL;
    head=head->next;
    free(temp);
    printf("Deletion of first node is done!\n");
}
void deleteAtEnd()
{
    temp=head;
    prev=NULL;
    while(temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    free(temp);
    printf("Deletion of last node is done!\n");
}
void deleteAtPos()
{
    int pos;
    printf("Enter the postion of the node u wish to delete: ");
    scanf("%d",&pos);
    temp=head;
    prev=NULL;
    for(int i=1;i<pos;i++)
    {
        prev=temp;
        temp=temp->next;
    }
    prev->next=temp->next;
    free(temp);
    printf("Deletion of node at pos %d is done!\n");
}
void display()
{
    temp=head;
    while(temp!=NULL)
    {
        printf("%d-> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
int main()
{
    head=NULL;
    int choice;
    printf("Enter 1:Creation of nodes\n2:Deletion at begining\n3:deletion at end\n4:deletion at specified position\n5:Display\n6:Exit\n");
    choice=1;
    while(choice!=6)
    {
        switch(choice)
        {
            case 1:creation();break;
            case 2:deleteAtBegining();break;
            case 3:deleteAtEnd();break;
            case 4:deleteAtPos();break;
            case 5:display();break;
            default:printf("Invalid choice");
        }
        printf("Enter ur choice: ");
        scanf("%d",&choice);
    }
    printf("Exiting!\n");
    return 0;
}