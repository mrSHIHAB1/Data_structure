#include <stdio.h>
#include <stdlib.h>
int top = -1;
int size = 3;
int stack[3];

void Push()
{
    int data;

    if (top <size - 1)
    {
         printf("Enter data to push: ");
        scanf("%d", &data);
        top++;
        stack[top] = data;

    }
    else
    {
        printf("Stack is Full\n");
    }
}

void Pop()
{
    if (top >=0)
    {
        int val=stack[top];
        top--;
        printf("%d is poped\n",val);
    }
    else
    {
        printf("empty\n");
    }
}
void peek()
{
    if(top>=0)
    {
        printf(" peek data = %d\n",stack[top]);
    }
    else{
        printf("no data\n");

    }
}

void Display()
{
    int i;
    printf("--Stack elements are:--\n");
    for (i = top; i >= 0; i--)
        printf("%d \n ", stack[i]);
}

int main()
{
    int option;

    do
    {
        if (top == -1)
            printf("The Stack is Empty.\n");
        printf("\n 1. Push\n 2. Pop\n 3. Display\n 4. Exit\n");

        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            Push();
            break;
        case 2:
            Pop();
            break;
        case 3:
            Display();
            break;
        case 4:
            exit(0);
        default:
            printf("Wrong choice\n");
        }
    } while (1);

    return 0;
}
