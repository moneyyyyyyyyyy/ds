// program to create a linked list first then perform all insertion operations
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head = 0;
void insertb();
void insertl();
void insertp();
void display();
void create();
int count = 0;
int main()
{
    int ch;
    while (1)
    {
        printf("\n1.create \n2.insertb \n3.insertl \n4.insertp \n5.display \n6.exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            create();
            break;
        case 2:
            insertb();
            break;
        case 3:
            insertl();
            break;
        case 4:
            insertp();
            break;
        case 5:
            display();
            break;
        default:
            exit(0);
        }
    }

    return 0;
}
void create()
{
    struct node *newnode, *temp;
    int ans = 1;
    int item;

    while (ans == 1)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("\nenter the data \n");
        scanf("%d", &item);
        newnode->data = item;
        newnode->next = 0;
        if (head == 0)
        {
            head = newnode;
            temp = head;
            count++;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
            count++;
        }
        printf("\n do u wish to continue adding items? 1/0\n");
        scanf("%d", &ans);
    }
}
void insertb()
{
    struct node *newnode;
    int item;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\n enter the data\n");
    scanf("%d", &item);
    newnode->data = item;
    newnode->next = 0;
    if (head == 0)
    {
        head = newnode;
        count++;
    }
    else
    {
        newnode->next = head;
        head = newnode;
        count++;
    }
}
void insertl()
{
    struct node *newnode, *temp;
    int item;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\n enter the data\n");
    scanf("%d", &item);
    newnode->data = item;
    newnode->next = 0;
    if (head == 0)
    {
        head = newnode;
        temp = head;
        count++;
    }
    else
    {
        temp = head;
        while (temp->next != 0)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        count++;
    }
}

void insertp()
{
    int i = 1;
    int item;
    int pos;
    printf("\n enter the position you would like to insert at \n");
    scanf("%d", &pos);
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));

    if (pos == 1)
    {
        if (head == 0)
        {
            printf("\n enter the data\n");
            scanf("%d", &item);
            newnode->data = item;
            newnode->next = 0;
            head = newnode;
            temp = head;
            count++;
        }
        else
        {
            printf("\n enter the data\n");
            scanf("%d", &item);
            newnode->data = item;
            newnode->next = head;
            head = newnode;
            count++;
        }
    }
    else if (pos > count)
    {
        printf("\n invalid position \n");
        return;
    }
    else
    {
        temp = head;
        printf("\n enter the data\n");
        scanf("%d", &item);
        newnode->data = item;
        newnode->next = 0;
        while (i < (pos - 1))
        {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
        count++;
    }
}
void display()
{
    struct node *temp = head;
    if (head == 0)
    {
        printf("\n underflow \n");
        return;
    }
    while (temp != 0)
    {
        printf("\n%d", temp->data);
        temp = temp->next;
    }
}