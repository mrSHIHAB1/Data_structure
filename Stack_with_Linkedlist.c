
#include<stdio.h>
 struct node{
 int data;
 struct node*next;
 }*top,*top1,*temp;

 int count=0;
 void push(int dat)
 {
     if(top==NULL)
     {
         top=(struct node*)malloc(sizeof(struct node));
         top->next=NULL;
         top->data=dat;
     }
     else{
        temp=(struct node*)malloc(sizeof(struct node));
        temp->next=top;
        temp->data=dat;
        top=temp;

     }
     count++;
     printf("node is inserted\n");
 }
 int pop()
 {
     top1= top;
     if(top1==NULL)
     {
         printf("Eempty stack\n");
     }
     else{
        top1=top1->next;
        int  poped=top->data;
        free(top);
        top=top1;
        count--;
        return poped;
     }
 }
 void display()
 {
     top1=top;
     while(top1!=NULL)
     { printf("%d\n",top1->data);
         top1=top1->next;
     }

 }
 int main() {
    int choice, value;
    printf("\nImplementation of Stack using Linked List\n");
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("\nEnter the value to insert: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            printf("Popped element is :%d\n", pop());
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nWrong Choice\n");
        }
    }
}
