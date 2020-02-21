#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int id;
	int start;
	int end;
	struct node* next;
}node;
node* addArr(node p)
{
	node* new_node = malloc(sizeof(node));
	*new_node = p;
	new_node->next = NULL;
	return new_node;
}
int main()
{
	int n, m, sum = 0, i = 1, time = 0;
	scanf("%d %d", &n, &m);
	node arr[n];
	for (int i = 0; i < n; i++)
    {
		scanf("%d%d%d", &arr[i].id, &arr[i].start, &arr[i].end);
		arr[i].next = NULL;
	}
	node temp;
	for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        if(arr[j].start > arr[j + 1].start || (arr[j].start == arr[j + 1].start && arr[j].id > arr[j + 1].id))
		{
			temp = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = temp;
		}
    for(int i = 0; i < n; i++) printf("%d %d\n", arr[i].id, arr[i].start);
	node* qhead = addArr(arr[0]);
	node* qtail = qhead;
	while(i < n && arr[i].start == 0)
    {
		qtail -> next = addArr(arr[i++]);
		qtail = qtail->next;
	}
	node* trav = qhead;
	while(trav != NULL)
    {
		if(trav -> end > m)
			time += m;
		else
			time += trav -> end;
		trav -> end -= m;
		if(trav -> end > 0)
        {
			while(i < n && arr[i].start <= time)
            {
				qtail -> next = addArr(arr[i++]);
				qtail = qtail->next;
			}
			qtail ->next = addArr(*trav);
			qtail = qtail -> next;
		}
		else sum += time - trav -> start;
		trav = trav -> next;
	}
	for(int i = 0; i < n; i++)
		sum -= arr[i].end;
	printf("%d\n", sum);
	
	while(qhead != NULL)
	{
		printf("%d ", qhead -> id);
		qhead = qhead -> next;
	}
}