//bst construction 
#include <stdio.h>
#include<conio.h>
#include<stdlib.h>

struct bst
{
    int data;
    struct bst *left;
    struct bst *right;
};
void insert(struct bst *root, struct bst *temp)
{
    if(temp->data<root->data)
    {
        if(root->left!=0)
        insert(root->left,temp);
        
        else
        root->left=temp;
    }
    
    if(temp->data>root->data)
    {
        if(root->right!=0)
        insert(root->right,temp);
        
        else
        root->right=temp;
    }
}

void preorder(struct bst *root)
{  
    if(root!=0)
    {
    printf(" %d ",root->data);
    preorder(root->left);
    preorder(root->right);
    }
}

void inorder(struct bst *root)
{
    if(root!=0)
    {
        inorder(root->left);
        printf(" %d ",root->data);
        inorder(root->right);
    }
}

void postorder(struct bst *root)
{
    if(root!=0)
    {
        postorder(root->left);
        postorder(root->right);
        printf(" %d ",root->data);
    }
}


struct bst *create()
{
    struct bst *newnode;
    newnode=(struct bst*)malloc(sizeof(struct bst));
    printf("\n enter the element\n");
    scanf("%d",&newnode->data);
    newnode->left=0;
    newnode->right=0;
    return newnode;
}
int main()
{
   int ch=1;
   struct bst *root=0;
   struct bst *temp;
   while(ch==1)
   {
     temp=create();
     if(root==0)
     {
     root=temp;
     }
     else
     {
         insert(root,temp);
     }
     printf("\n do you want to continue adding elements?\n");
     scanf("%d",&ch);
   }
   printf("\n preorder\n");
   preorder(root);
   printf("\npostorder\n");
   postorder(root);
   printf("\ninorder\n");
   inorder(root);
    return 0;
}