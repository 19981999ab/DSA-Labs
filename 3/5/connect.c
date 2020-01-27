#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}node;

void push(node **head, int data)
{
    node *new_node = malloc(sizeof(node));
    new_node -> data = data;
    new_node -> next = NULL;
    if(*head == NULL)
        *head = new_node;
    else
    {
        node *last = *head;
        while(last -> next != NULL)
            last = last -> next;
        last -> next = new_node; 
    }
}

void spiral_connect(node **head)
{
    node *last = *head, *last_temp = *head, *current = *head;
    while(last -> next != NULL)
        last = last -> next;

    while(current != last)
    {
        node *next = current -> next;
        current -> next = last;
        last -> next = next;
        current = next;
        last_temp = current;
        while(last_temp -> next != last)
            last_temp = last_temp -> next;
        last = last_temp;
        printf("%d %d\n", current -> data, last -> data);
    }
    current -> next = NULL;
}
void traverse(node **head)
{
    printf("Traverse\n");
    node* current=*head;
    while(current!=NULL)
    {
        printf("%d ",current->data);
        current=current->next;
    }
}
int main()
{
    char c='a';
    int d;
    node *head=NULL;
    while(c!='\n')
    {
        scanf("%d", &d);
        push(&head, d);
        c=getchar();
    }
    spiral_connect(&head);
    traverse(&head);
}