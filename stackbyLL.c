//stack and q by ll

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void push();
void pop();
void display();
void peep();

struct node
{
    int data;
    struct node *next;

};
struct node *top= 0;
int main()
{
    int ch;
    while (1)
    {
        printf("\n 1. push \n 2.pop \n 3.display \n 4.peep \n 5.exit \n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1: push();
            
            break;
        case 2: pop();
        break;
        case 3: display();
        break;
        case 4: peep();
        break;

        
        default: printf("\n wrong option");
            
        }

        
    }
    return 0;
}

void push()
    {
        int x;
        struct node *newnode;
        printf("\n enter the element");
        scanf("%d",&x);
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode -> data= x;
        newnode ->next =top;
        top = newnode;
             
        
    }

void display()
{
    struct node *temp;
    temp =top;
    if (top == 0)
    {
        printf("\n underflow");

    }
    else
    {
        while (temp!=0)
        {
            printf("%d",temp ->data);
            temp = temp ->next;
        }
        
    }
}
void pop()
{
    struct node *temp;
    temp =top;
    if (top == 0)
    {
        printf("\n underflow");
        return;
    }
    else
    {
        printf("\n deleted element is %d", top -> data);
        top = top -> next;
        free(temp);
    }
}
void peep()
{
    if (top == 0)
    {
        printf("\n underflow");
        return;
    }
    else
    {
        printf("\n %d",top ->data);

    }
}
