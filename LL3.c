// q.singly linked list various functions
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head = 0, *temp = 0;
struct node *head2 = 0;
int count = 0;
int count1 = 0;
void create();
void display();
void sort();
void reverse();
void display2();
void create2();
void concat();

int main()
{
    int ch;
    while (1)
    {
        printf("\n1.create \n2.display \n3.reverse \n4.concatenate \n5.sort \n6.create2\n7.display2\n8.exit\n");
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
            reverse();
            break;
        case 4:
            concat();
            break;
        case 5:
            sort();
            break;
        case 6:
            create2();
            break;
        case 7:
            display2();
            break;
        default:
            exit(0);
        }
    }
    return 0;
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
void sort()
{
    struct node *current = head, *index = NULL;
    int temp;

    if (head == NULL)
    {
        return;
    }
    else
    {
        while (current != NULL)
        {
            // Node index will point to node next to current
            index = current->next;

            while (index != NULL)
            {
                // If current node's data is greater than index's node data, swap the data between them
                if (current->data > index->data)
                {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
}

void reverse()
{
    // Initialize current, previous and
    // next pointers
    struct node *current = head;
    struct node *prev = NULL, *next = NULL;

    while (current != NULL)
    {
        // Store next
        next = current->next;

        // Reverse current node's pointer
        current->next = prev;

        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    head = prev;
}

void create2()
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
        if (head2 == 0)
        {
            head2 = newnode;
            temp = head2;
            count1++;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
            count1++;
        }
        printf("\n do u wish to keep adding 0/1?\n");
        scanf("%d", &ans);
    }
}

void display2()
{
    struct node *temp1;
    if (head2 == 0)
    {
        printf("\n underflow \n");
        return;
    }
    else
    {
        temp1 = head2;
        while (temp1 != 0)
        {
            printf("\n%d", temp1->data);
            temp1 = temp1->next;
        }
    }
}

void concat()

{

    struct node *ptr;

    ptr = head;

    while (ptr->next != NULL)

        ptr = ptr->next;

    ptr->next = head2;
}