#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <limits.h>
typedef struct node
{
  int data;
  struct node* next;
}node;

void push(node** head, int x)
{
  node* new_node = malloc(sizeof(node));
  new_node->data = x;
  new_node->next = *head;
  *head = new_node;
} 

int pop(node** head)
{
  if(*head == NULL)
  {
    printf("STACK UNDERFLOW\n");
    return INT_MAX;
  } 

  int x = (*head) -> data;
  *head = (*head) -> next;
  return x;
}

int peek(node** head)
{
  if(*head == NULL)
  {
    printf("STACK UNDERFLOW\n");
    return INT_MAX;
  }
  return (*head) -> data;
}
int main()
{ 
  int queries;
  scanf("%d",&queries);
  node* head = NULL;
  node* min = NULL;
  while(queries--)
  {
    char str[10];
    scanf("%s", str);
    if(!strcmp(str, "push"))
    {
        int x;
        scanf("%d", &x);
        push(&head, x);
        printf("OK pushed %d\n", x);
        if(min == NULL) push(&min, x);
        else if(x <= min -> data) push(&min, x);
    }
    else if(!strcmp(str,"pop"))
    {
      int x = pop(&head);
      if(x != INT_MAX)
      {
        printf("OK popped %d\n", x);
        if(x == min -> data)
          pop(&min);
      }
    }
    else if(!strcmp(str, "peek"))
    {
      int x = peek(&head);
      if(x != INT_MAX)
        printf("%d\n",x);
    }
    else if(!strcmp(str,"getMin"))
    {
      int x = peek(&min);
      if(x != INT_MAX)
        printf("%d\n",x);
    }
  } 
  return 0; 
}