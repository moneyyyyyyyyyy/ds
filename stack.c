#include <stdio.h>
#include <process.h>
#include <stdlib.h>

#define MAX 5 // Maximum number of elements that can be stored
int *temp;
int top = -1, stack[MAX];
void push();
void pop();
void display();
void removeDuplicates();

int main()
{
    int ch;
    while (1) // infinite loop, will end when choice will be 4
    {
        printf("\n*** Stack Menu ***");
        printf("\n\n1.Push\n2.Pop\n3.Display\n4.rem");
        printf("\n\nEnter your choice(1-4):");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            removeDuplicates();
        default:
            printf("\nWrong Choice!!");
        }
    }
}

void push()
{
    int val;
    if (top == MAX - 1)
    {
        printf("\nStack is full!!");
    }
    else
    {
        printf("\nEnter element to push:");
        scanf("%d", &val);
        top = top + 1;
        stack[top] = val;
    }
}
void removeDuplicates()
{
    int *temp = (int *)malloc(10 * sizeof(int));
    int temp_size = MAX;
    int temp_sp = -1;

    for (int i = 0; i < top + 1; i++)
    {
        temp[i] = stack[i];
    }
    temp_sp = top;

    for (int i = 0; i < temp_sp + 1; i++)
    {
        for (int j = i + 1; j < temp_sp + 1; i++)
        {
            if (!(temp[i] == temp[j]))
            {
                push(temp[i]);
            }
        }
    }
}
void pop()
{
    if (top == -1)
    {
        printf("\nStack is empty!!");
    }
    else
    {
        printf("\nDeleted element is %d", stack[top]);
        top = top - 1;
    }
}

void display()
{
    int i;
    if (top == -1)
    {
        printf("\nStack is empty!!");
    }
    else
    {
        printf("\nStack is...\n");
        for (i = top; i >= 0; i--)
            printf("%d\n", stack[i]);
    }
}