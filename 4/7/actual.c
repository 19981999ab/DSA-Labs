#include <stdio.h> 
#include <stdlib.h> 
typedef struct Node{ 
	int data; 
	struct Node* next; 
}node; 
void push(node** head, int new_data) 
{ 
	node* new_node = malloc(sizeof(node)); 
	new_node->data = new_data; 
	new_node->next = *head; 
	*head = new_node; 
}
void split(node *head, node **front, node **back)
{
	node *fast, *slow;
	slow = head;
	fast = head -> next;
	while(fast != NULL)
	{
		fast = fast -> next;
		if(fast != NULL)
		{
			slow = slow -> next;
			fast = fast -> next;
		}
	}
	*front = head;
	*back = slow -> next;
	slow -> next = NULL;
}
node* merge(node *a, node *b)
{
	node *result = NULL;
	if(a == NULL)
		return b;
	else if(b == NULL)
		return a;
	if(a -> data <= b -> data)
	{
		result = a;
		result -> next = merge(a -> next, b);
	}
	else
	{
		result = b;
		result -> next = merge(a, b -> next);
	}
	return result;
}
void merge_sort(node **head)
{
	node *current = *head;
	node *a, *b;
	if(current == NULL || current -> next == NULL)
	{
		return;
	}
	split(current, &a, &b);
	merge_sort(&a);
	merge_sort(&b);
	*head = merge(a, b);
}
void printList(node* node) 
{ 
	while (node != NULL) { 
		printf("%d ", node->data); 
		node = node->next; 
	} 
} 
int main() 
{ 
	node* res = NULL; 
	node* a = NULL; 
	do
	{   
        int d;
		scanf("%d", &d);
		push(&a, d);
	} while(getchar() != '\n');
	merge_sort(&a); 
	printList(a);
	return 0; 
} 
