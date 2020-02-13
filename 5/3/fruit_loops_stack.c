#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int V, stack_pos = 0, ch = 0;
void DFS(int arr[V + 1][V + 1], int *vis, int num, int *stack_arr, int *mark)
{
    vis[num] = 1;
    mark[num] = 1;
    for(int i = 1; i <= V; i++)
    {
        if(arr[num][i] == 1)
        {
            if(mark[i] == 1) ch = 1;
            if(vis[i] == 0) DFS(arr, vis, i, stack_arr, mark);
        }
    }
    stack_arr[stack_pos++] = num; 
    mark[num] = 0;
}   
int main()
{
    int len;
    scanf("%d %d", &V, &len);
    int arr[V + 1][V + 1], vis[V + 1], stack_arr[V + 1], mark[V + 1];
    memset(arr, 0, sizeof(arr));
    memset(vis, 0, sizeof(vis));
    memset(stack_arr, 0, sizeof(stack_arr));
    memset(mark, 0, sizeof(mark));
    for(int i = 0; i < len; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        arr[v][u] = 1; 
    }

    for(int i = 1; i <= V; i++) if (!vis[i]) DFS(arr, vis, 1, stack_arr, mark);
    if (ch) printf("NOT POSSIBLE");
	else for(int i = V - 1; i >= 0; i--) printf("%d ", stack_arr[i]);   
}