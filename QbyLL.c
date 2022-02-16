#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next
};
struct node *front = 0;
struct node *rear = 0;
void insert();
void delete ();
void display();

int main()
{
    int ch;
    while (1)
    {
        printf("\n Enter your choice \n 1. insert \n 2.Delete \n 3.display \n 4.exit \n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1: insert();
            break;
        case 2: delete();
        break;
        case 3: display();
        break;
        
        default: exit(0);
            
        }
    }
    return 0;
}

void insert()
{
    int x;
    struct node *newnode;
    printf("\n enter the element");
    scanf("%d",&x);
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode ->data =x;
    newnode ->next =0;
    if (front == NULL && rear == NULL)
    {
        front=rear=newnode;
    }
    else{
        rear ->next= newnode;
        rear = newnode;
    }
}
void delete()
{
    struct node *temp;
    temp = front;
    if (front == 0 && rear == 0)
    {
        printf("\n Queue empty");
        return;
    }
    else if (front -> next == rear -> next)
    {
        printf("\n the deleted element is %d", front ->data);
        front =0;
        rear =0;
        free(temp);
    }
    else
    {
        printf("\n element deleted is %d",front ->data);
        front= front -> next;
        free(temp);
    }
    
}

void display()
{
    struct node *temp;
    if (front ==0 && rear ==0)
    {
        printf("\n underflow");
        return;
    }
    else{
        temp =front;
        while (temp != 0)
        {
            printf("\n %d", front ->data);
            temp = temp ->next;
        }
        
    }
}