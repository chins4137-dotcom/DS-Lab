#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left,*right;
};struct node* newnode;
struct node* creation(int value)
{

    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
struct node* insert(struct node *root,int value)
{
    if(root==NULL)
    {
        return creation(value);
    }
    if(value<root->data)
    root->left=insert(root->left,value);
    else if(value>root->data)
    root->right=insert(root->right,value);
    return root;
}
void inorder(struct node* root)
{
    if(root==NULL)
    return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
void preorder(struct node* root)
{
    if(root==NULL)
    return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct node* root)
{
    if(root==NULL)
    return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
void display(struct node *root)
{
    printf("Elements of Binary Search Tree: ");
    inorder(root);
    printf("\n");
}
int main()
{
    int ch,value;
    struct node *root=NULL;
    printf("1:Insertion\n2:Inorder\n3:Preorder\n4:Postorder\n5:Display\n6:Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&ch);
    while(ch!=6)
    {
        switch(ch)
        {
            case 1:printf("Enter value: ");
                   scanf("%d",&value);
                   root=insert(root,value);break;
            case 2:printf("__Inorder Traversal__\n");inorder(root);printf("\n");break;
            case 3:printf("__Preorder Traversal__\n");preorder(root);printf("\n");break;
            case 4:printf("__Postorder Traversal__\n");postorder(root);printf("\n");break;
            case 5:display(root);break;
            case 6:printf("Exiting!!");break;
            default:printf("Incorrect Choice");
        }
        printf("Enter your choice: ");
        scanf("%d",&ch);
    }
    printf("Exiting!");
}

