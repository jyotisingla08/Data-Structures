#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next;
};
void display(struct node* head)
{
      struct node *temp = head;
      printf("\n\nList elements are - \n");
      while(temp != NULL)
      {
   printf("%d --->",temp->data);
   temp = temp->next;
      }
}
void insertAtMiddle(struct node *head, int position, int value) {
    struct node *temp = head;
    struct node *newNode;
    newNode = malloc(sizeof(struct node));
    newNode->data = value;

    int i;
    for( i=2; i < position; i++) {
    if(temp->next != NULL) {
        temp = temp->next;
    }
}
    newNode->next = temp->next;
    temp->next = newNode;
}
void insertAtFront(struct node** headRef, int value) {
    struct node* head = *headRef;

    struct node *newNode;
    newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;

    *headRef = head;
}
void insertAtEnd(struct node* head, int value){
    struct node *newNode;
    newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    struct node *temp = head;
    while(temp->next != NULL){
      temp = temp->next;
    }
    temp->next = newNode;
}
void deleteFromFront(struct node** headRef){
    struct node* head =  *headRef;
    head = head->next;
    *headRef = head;
}
void deleteFromEnd(struct node* head){
    struct node* temp = head;
    while(temp->next->next!=NULL){
      temp = temp->next;
    }
    temp->next = NULL;
}
void deleteFromMiddle(struct node* head, int position){
    struct node* temp = head;
    int i;
    for( i=2; i< position; i++) {
    if(temp->next!=NULL) {
        temp = temp->next;
    }
}
temp->next = temp->next->next;
}
int main() {

  struct node *head;
  struct node *one = NULL;
  struct node *two = NULL;
  struct node *three = NULL;

  one = malloc(sizeof(struct node));
  two = malloc(sizeof(struct node));
  three = malloc(sizeof(struct node));

  one->data = 1;
  two->data = 2;
  three->data = 3;
  one->next = two;
  two->next = three;
  three->next = NULL;
  head = one;
  display(head);
  insertAtFront(&head, 4);
  display(head);
  deleteFromFront(&head);
  display(head);
  insertAtEnd(head, 5);
  display(head);
  deleteFromEnd(head);
  display(head);
  int position = 3;
  insertAtMiddle(head, position, 10);
  display(head);
  deleteFromMiddle(head, position);
  display(head);
}
