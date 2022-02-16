// q. program to create a linked list first then perform all delete operations u can add more elements as and when required
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head = 0, *temp = 0;
int count = 0;
void create();
void display();
void deletb();
void deletl();
void deletp();

int main()
{
    int ch;
    while (1)
    {
        printf("\n1.create \n2.display \n3.deletb \n4.deletl \n5.deletp \n6.exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            deletb();
            break;
        case 4:
            deletl();
            break;
        case 5:
            deletp();
            break;
        default:
            exit(0);
        }
    }

    return 0;
}
void create()
{
    struct node *newnode;
    int ans = 1, item;

    while (ans == 1)
    {
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
            temp->next = newnode;
            temp = newnode;
            count++;
        }
        printf("\n do u wish to keep adding 0/1?\n");
        scanf("%d", &ans);
    }
}

void display()
{
    struct node *temp1;
    if (head == 0)
    {
        printf("\n underflow \n");
        return;
    }
    temp1 = head;
    while (temp1 != 0)
    {
        printf("\n%d", temp1->data);
        temp1 = temp1->next;
    }
}

void deletb()
{
    struct node *temp, *prev;
    if (head == 0)
    {
        printf("\n underflow \n");
        return;
    }

    else
    {

        temp = head;
        head = head->next;
        free(temp);
        count--;
    }
}
void deletl()
{
    struct node *temp, *prev;
    if (head == 0)
    {
        printf("\n underflow \n");
        return;
    }

    else
    {

        temp = head;
        while (temp->next != 0)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp == head)
        {
            head = 0;
        }
        else
        {
            prev->next = temp->next; //
        }
        free(temp);
        count--;
    }
}
void deletp()
{
    int i = 1;
    int pos;
    struct node *temp, *nextnode;
    if (head == 0)
    {
        printf("\n underflow \n");
        return;
    }
    else
    {
        printf("\n enter the position you would like to delete from\n");
        scanf("%d", &pos);
        if (pos > count)
        {
            printf("\n invalid position \n");
            return;
        }
        else if (pos == 1)
        {
            temp = head;
            head = 0;
            free(temp);
            count--;
        }
        else
        {
            temp = head;
            while (i < pos - 1)
            {
                temp = temp->next;
            }
            nextnode = temp->next;
            temp->next = nextnode->next;
            free(nextnode);
            count--;
        }
    }
}