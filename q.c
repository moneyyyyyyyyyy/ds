#include <stdio.h>
#include<stdlib.h>
#define MAX 50
void insert();
void delete();
void display();
int queue_array[MAX];
int rear = - 1;
int front = - 1;
int main()
{
int choice;
while (1)
{
printf("1.Insert element to queue \n 2.Delete element from queue \n 3.Display all elements of queue \n 4.Quit \n");
printf("Enter your choice : \n");
scanf("\n%d", &choice);
switch(choice)
{
case 1:
insert();
break;
case 2:
delete();
break;
case 3:
display();
break;
case 4:
exit(1);
default:
printf("Wrong choice \n");
}
}
}
void insert()
{
int item;
if(rear == MAX - 1)
printf("Queue Overflow \n");
else
{
if(front== - 1)
front = 0;
printf("Insert the element in queue : \n");
scanf("%d", &item);
rear++;
queue_array[rear] = item;
}
}
void delete()
{
if(front == - 1 || front > rear)
{
printf("Queue Underflow \n");
return;
}
else
{
printf("Element deleted from queue is : %d\n", queue_array[front]);
front++;
}
}
void display()
{
int i;
if(front == - 1)
printf("Queue is empty \n");
else
{
printf("Queue is : \n");
for(i = front; i <= rear; i++)
printf("%d ", queue_array[i]);
printf("\n");
}
}