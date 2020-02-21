#include<stdio.h>
struct Node
{
	int id, arrival, time;
};
typedef struct Node node;
node stack[1000001];
node arr[1000001];
int ans[1000001];
int top = -1;
int main()
{
    int n;
    scanf("%d ",&n);
    for(int i = 0; i < n; i++) scanf("%d %d %d", &arr[i].id, &arr[i].arrival, &arr[i].time);
    node temp;
    for(int i = 0; i < n - 1; i++)
        for(int j = 0; j < n - 1 - i; j++)
        {
            if(arr[j].arrival > arr[j + 1].arrival)
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            else if (arr[j].arrival == arr[j + 1].arrival && arr[j + 1].id > arr[j].id)
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    for(int i = 0; i < n; i++) printf("%d %d\n", arr[i].id, arr[i].arrival);
    int currTime = 0, i = 0;
    while(top > -1 || i < n)
    {
        while(arr[i].arrival <= currTime && i < n)
            stack[++top] = arr[i++];
        currTime++;
        stack[top].time--;
        if(stack[top].time == 0)
        {
            ans[stack[top].id] = currTime;
            top--;
        }
    } 

    for(i = 0; i < 1000000; i++)
		if(ans[i] != 0)
			printf("%d %d\n", i, ans[i]);
    return 0;
}