#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>
#define N 1005
typedef struct node
{
  char data;
  struct node* left;
  struct node* right;
}node;

void print(node* head)
{
  if(head == NULL) return;
  if(!(head -> data >= '0' && head -> data <= '9'))
  {
    printf("(");
    print(head->left);
    printf("%c", head->data);
    print(head->right);
    printf(")");
  }
  else
  {
    print(head->left);
    printf("%c",head->data);
    print(head->right);
  }
}
int evaluate(node* head)
{
  if(head != NULL)
  {
    int res;
    int left = evaluate(head->left);
    int right = evaluate(head->right);

    if(head->data == '+')
      res = left + right;
    else if(head->data == '-')
      res = left - right;
    else if(head->data == '*')
      res = left * right;
    else if(head->data == '/')
      res = left/right;
    else 
      res = head->data - '0';
    return res;
  }
  return 0;
}
int main()
{ 
  node* stack[5000];
  char str[500000];
  scanf("%s", str);
  int len = strlen(str);
  int top = -1;
  for(int i = 0; i < len; i++)
  {
    if(str[i] >= '0' && str[i] <= '9')
    {
      node* new_node = malloc(sizeof(node));
      new_node->data = str[i];
      new_node->left = NULL;
      new_node->right = NULL;
      stack[++top] = new_node;
    } 
    else
    {
      node* new_node = malloc(sizeof(node));
      new_node->data = str[i];
      new_node->right = stack[top--];
      new_node->left =stack[top--];
      stack[++top] = new_node;
    }
  }
  node* head = stack[0];
  printf("%d\n", evaluate(head));
  print(head);
  return 0; 
}

