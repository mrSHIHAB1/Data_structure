
#include <stdio.h>
#include <stdlib.h>
int front=-1;
int rear=-1;
int size=3;
int queue[3];
void EnQueue()
{
    int i;

    if(rear==size)
    printf("Queue if Full");

    else
    {

        if(front==-1)
          front=0;
            rear++;
            printf("Enter the data to queue: ");
            for(i=rear;i<=rear;i++)
            scanf("%d", &queue[i]);
    }
}
void DeQueue()
{
    if(front==-1)
    printf("Queue is Empty;");
    else
    {
        printf("\nDeleted: %d\n",queue[front]);
        front++;
        if(front>rear)
        rear=front=-1;
    }
}
void display()
{
    int i;
    printf("--Queue elements are:--\n");
    for(i=front;i<=rear;i++)
    printf("%d  ",queue[i]);

}
int main()
{
    int opction,n;
    do
    {
    if(front==-1)
    printf("The Queue is Empty.\n");
    printf("\n 1. Enque\n 2. Deque \n 3. Display\n 4. Exit\n");

    printf("Enter your opction: ");

    scanf("%d",&opction);

     switch(opction)
      {

      case 1:
          EnQueue();
          break;
      case 2:
          DeQueue();
          break;
      case 3:
          display();
          break;
      default:
          printf("Wrong choice");
      }
    }
    while(1);
  return 0;
}
