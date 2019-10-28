#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node* next;
};

int  checkPalindrome(struct Node* head)
{
  struct Node* start=NULL;
  struct Node* ptr1=head;
  if(head==NULL)
    return 0;
  while(ptr1!=NULL)
  {
    struct Node* new=(struct Node*)malloc(sizeof(struct Node));
    new->data=ptr1->data;
    if(start==NULL)
    {
      start=new;
      new->next=NULL;
    }
    else
    {
      new->next=start;
      start=new;
    }
    ptr1=ptr1->next;

  }
  while(head!=NULL)
  {
    if(start->data!=head->data)
      return 0;
    else
    {
      head=head->next;
      start=start->next;
    }
  }
  return 1;

}

void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}


int main()
{
    struct Node* head = NULL;

    // create linked 35->15->4->20
    push(&head, 1);
    push(&head, 2);
    push(&head, 2);
    push(&head, 1);
    if(checkPalindrome(head))
        printf("yes");
    else
        printf("no");
    return 0;
}
