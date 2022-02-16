//q.doubly linked list class program

#include <stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*next;
    struct node*prev;
};
struct node*head=0;
struct node*tail=0;
void create();
void insertbeg();
void delfrompos();
void display();

int main()
{   
    int ch;
    while(1)
    {
    printf("\n1.create\n2.insert at beginning\n3.delete from a position\n4.display\n5.exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: create();
        break;
        case 2: insertbeg();
        break;
        case 3: delfrompos();
        break;
        case 4: display();
        break;
        default: exit(0);
        
    }
}
    return 0;
}

void create()
{   
    struct node*newnode;
    struct node*temp;
    int ch=1;
    while(ch)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("\nenter the data\n");
        scanf("%d",&newnode->data);
        newnode->next=0;
        newnode->prev=0;
        if(head==0)
        {
            head=newnode;
            temp=newnode;
            tail=newnode;
        }
        else
        {
            temp->next=newnode;
            newnode->prev=temp;
            temp=newnode;
            tail=newnode;
        }
        printf("\n do you want to continue adding elements 0/1?\n");
        scanf("%d",&ch);
        
    }
}

void display()
{
    struct node*temp;
    if(head==0)
    {
        printf("\nlist empty\n");
        return;
    }
    else
    {
        temp=head;
    while(temp!=0)
    {
        printf("\n%d",temp->data);
        temp=temp->next;
    }
    }
}

void insertbeg()
{
  struct node*newnode;
  newnode=(struct node*)malloc(sizeof(struct node));
  printf("\n enter the data\n");
  scanf("%d",&newnode->data);
  newnode->next=0;
  newnode->prev=0;
  if(head==0)
  {
      head=newnode;
      tail=newnode;
  }
  else
  {
      head->prev=newnode;
      newnode->next=head;
      head=newnode;
  }
}

void delfrompos()
{
    int count=0;
    int pos;
    int i=1;
    struct node*temp;
    struct node*temp1;
    if(head==0)
    {
        printf("\n empty list\n");
        return;
    }
    else
    {
        temp=head;
        temp1=head;
        while(temp1!=0)
        {
            count++;
            temp1=temp1->next;
        }
        printf("\nenter the position \n");
        scanf("%d",&pos);
        if(pos>count||pos<0)
        {
            printf("\n invalid position\n");
            return;
        }
        else if(pos==1)
        {
            temp=head;
            head=head->next;
            head->prev=0;
            free(temp);
        }
        else if(pos==count)
        {
            temp=tail;
            tail=tail->prev;
            tail->next=0;
        }
        else
        {
            while(i<pos)
            {
                temp=temp->next;
                i++;
            }
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            free(temp);
        }
    }
}