#include <stdlib.h>
#include<stdio.h>
typedef struct node
{
    int data;
    struct node *link;
}NODE;

void Insert(int);
int  Delete();
void Display();
NODE *front,*rear;

int main()
{

    int opn,elem;
    front=rear=NULL;
    do
    {
        printf("\n  Linked List Implementation of QUEUE Operations\n");
        printf("\n Press 1-Insert, 2-Delete, 3-Display,4-Exit\n");
        printf("\n Your option ? ");
        scanf("%d",&opn);
        switch(opn)
        {
        case 1:
            printf("\nRead the Element to be Inserted ?");
            scanf("%d",&elem);
            Insert(elem);
            break;
        case 2:
            elem=Delete();
            if(elem != -1)
                printf(" Deleted Node(From Front)with the Data: %d\n",elem);
            break;
        case 3: printf("Linked List Implementation of Queue: Status:\n");
            Display(); break;
        case 4: printf("\n Terminating \n"); break;
        default: printf("\nInvalid Option !!! Try Again !! \n");
            break;
        }printf("\n Press a Key to Continue . . . ");
        getch();
    }while(opn != 4);
}

void Insert(int info)
{
    NODE *temp;
    temp=(NODE *)malloc(sizeof(NODE));
    if( temp == NULL)
        printf(" Overflow");
    else
    {
        temp->data=info;
        temp->link=NULL;

        if(front == NULL) { front = rear = temp; }
        else
        { rear->link=temp; rear = temp; }
        printf(" Node has been inserted at End Successfully !!");
    }
}

int Delete()
{
    int info;
    NODE *t; if( front ==  NULL) { printf(" Underflow!!!"); return -1; }
    else
    {
        t=front;
        info=front->data;
        if(front == rear) rear=NULL;
        front=front->link;
        t->link=NULL;
        free(t);
        return(info);
    }
}

void Display()
{
    NODE *t;
    if( front == NULL) printf("Empty Queue\n");
    else
    {
        t=front;
        printf("Front->");
        while(t)
        { printf("[%d]->",t->data);
            t=t->link;
        }
        printf("Rear\n");
    }
}
