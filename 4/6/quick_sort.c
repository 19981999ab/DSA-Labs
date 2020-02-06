#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
}node;

void push(node **head, int data)
{
    node *new_node = malloc(sizeof(node));
    new_node -> data = data;
    new_node -> next = NULL;
    new_node -> prev = NULL;
    if(*head == NULL)
        *head = new_node;
    else
    {
        node *last = *head;
        while(last -> next != NULL)
            last = last -> next;
        last -> next = new_node;
        new_node -> prev = last;
    }
}
void swap(node **node1, node **node2)
{
    int data = (*node1) -> data;
    (*node1) -> data = (*node2) -> data;
    (*node2) -> data = data;

}
void delete_node(node **node1)
{
    node *temp = *node1;
    (*node1) -> prev -> next = (*node1) -> next;
    *node1 = (*node1) -> prev;
    free(temp);
}
void push_inbetween(node **head, int data)
{
    node *new_node = malloc(sizeof(node));
    new_node -> data = data;
    new_node -> next = (*head) -> next;
    (*head) -> next -> prev = new_node;
    (*head) -> next = new_node;
    new_node -> prev = (*head);
}
int quick_sort(node **head, int pivot_data)
{
    node *pivot = *head, *start = *head, *last = *head;
    int count = 0;
    while(pivot -> data != pivot_data)
        pivot = pivot -> next;
    while(last -> next != NULL)
        last = last -> next;
    while(start != last)
    {
        while(start -> data <= pivot -> data && start != pivot)
        {
            start = start -> next;
        }
        while(last -> data > pivot -> data && last != pivot)
        {
            last = last -> prev;
        }
        printf("%d %d\n", start -> data, last -> data);
        if(last == pivot && start == pivot)
            return count;
        else if(start == pivot)
        {
            node *temp = pivot -> prev;
            push_inbetween(&temp, last -> data);
            delete_node(&last);
        }
        else if(last == pivot)
        {
            node *temp = pivot -> next;
            push_inbetween(&temp, start -> data);
            delete_node(&start);
        }
        else
            swap(&start, &last);
        count++;
    }
}

int main()
{
    int len, d;
    scanf("%d", &len);
    node *head = NULL;
    for(int i = 0; i < len; i++)
    {
        scanf("%d", &d);
        push(&head, d);
    }
    scanf("%d", &d);
    
    printf("%d", quick_sort(&head, d));
}