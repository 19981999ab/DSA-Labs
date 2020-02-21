#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int id;
	int start;
	int end;
	struct node* next;
}node;
void merge(node arr[],int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;
	node L[n1], R[n2];
	for (int i = 0; i < n1; i++)
		L[i] = arr[l+i];
	for (int i = 0; i < n2; i++)
		R[i] = arr[m + 1 + i];
	int i = 0, j = 0, k = l;
	while(i < n1 && j < n2)
		if (L[i].start < R[j].start)
			arr[k++] = L[i++];
		else if(L[i].start > R[j].start)
			arr[k++] = R[j++];
		else
			if (L[i].id < R[j].id)
				arr[k++] = L[i++];
			else
				arr[k++] = R[j++];
	while (i < n1)
		arr[k++] = L[i++];
	while (j < n2)
		arr[k++] = R[j++];
}
void mergesort(node arr[],int l, int r)
{
	if (l < r)
    {
		int m = (l + r)/2;
		mergesort(arr, l, m);
		mergesort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
	else return;
}
node* addArr(node p)
{
	node* new_node = (node*)malloc(sizeof(node));
	*new_node = p;
	new_node->next = NULL;
	return new_node;
}
int main()
{
	int n, m, sum = 0, j = 1, time = 0;
	scanf("%d %d", &n, &m);
	node arr[n];
	for (int i = 0; i < n; i++)
    {
		scanf("%d%d%d", &arr[i].id, &arr[i].start, &arr[i].end);
		arr[i].next = NULL;
	}
	mergesort(arr, 0, n-1);
	node* qhead = addArr(arr[0]);
	node* qtail = qhead;
	while(j < n && arr[j].start == 0)
    {
		qtail -> next = addArr(arr[j]);
		qtail = qtail->next;
		j += 1;
	}
	node* trav = qhead;
	while(trav != NULL)
    {
		if(trav -> end > m)
			time += m;
		else
			time += trav -> end;
		trav -> end -= m;
		if(trav->end > 0)
        {
			while(j < n && arr[j].start <= time)
            {
				qtail -> next = addArr(arr[j]);
				qtail = qtail->next;
				j += 1;
			}
			qtail ->next = addArr(*trav);
			qtail = qtail -> next;
		}
		else 
        {
			sum += time - trav -> start;
			// trav->end = time;
		}
		trav = trav->next;
	}
	for(int i = 0; i < n; i++)
		sum -= arr[i].end;

	printf("%d\n",sum);
	while(qhead!=NULL){
		printf("%d ", qhead -> id);
		qhead = qhead->next;
	}
}