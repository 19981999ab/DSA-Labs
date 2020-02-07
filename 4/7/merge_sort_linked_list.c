#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}node;
node *head;
void merge(int l, int m, int r)
{
	node *head1, *head2, *temp1, *temp2;
	node *curr = head;
	int n1 = m - l + 1, n2 = r - m;
	for(int i = 0; i < l; i++) curr = curr->next;
	for(int i = 0; i < n1; i++)
	{
		node *value = (node *)malloc(sizeof(node));
		value->data = curr->data;
		value->next = NULL;
		if (i == 0)
        {
            temp1 = value;
            head1 = value;
        }
		else
        {
            temp1->next = value;
            temp1 = temp1->next;
        }
		curr = curr->next;
	}
	for(int i = 0; i < n2; i++)
	{
		node *value = (node *)malloc(sizeof(node));
		value->data = curr->data;
		value->next = NULL;
		if (i == 0)
        {
            temp2 = value;
            head2 = value;
        }
		else
        {
            temp2->next = value;
            temp2 = temp2->next;
        }
		curr = curr->next;
	}
	curr = head, temp1 = head1, temp2 = head2;
	for(int i = 0; i < l; i++) curr = curr->next;
	while (1)
	{
		if (temp1 == NULL)
		{
			while (temp2 != NULL)
            {
                curr->data = temp2->data;
                temp2 = temp2->next;
                curr = curr->next;
            }
			break;
		}
		if (temp2 == NULL)
		{
			while (temp1 != NULL)
            {
                curr->data = temp1->data;
                temp1 = temp1->next;
                curr = curr->next;
            }
			break;
		}
		if (temp1->data <= temp2->data)
        {
            curr->data = temp1->data;
            temp1 = temp1->next;
        }
		else
        {
            curr->data = temp2->data;
            temp2 = temp2->next;
        }
		curr = curr->next;
	}
}
void msort(int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;
		msort(l, m);
		msort(m + 1, r);
		merge(l, m, r);
	}
}
int main()
{
	node *curr = NULL;
	int length = 0;
	do
	{
		node *temp = (node *)malloc(sizeof(node));
		scanf("%d", &(temp->data));
		temp->next = NULL;
		if (length == 0)
        {
            curr = temp;
            head = temp;
        }
		else
        {
            curr->next = temp;
            curr = curr->next;
        }
		length++;
	} while(getchar() != 10);
	msort(0, length - 1);
	curr = head;
	while(curr != NULL) 
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
        
}