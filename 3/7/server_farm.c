#include <stdio.h>

int V, E, count = 0;
void DFS(int num, int break_node, int arr[V][V], int vis[V])
{
    vis[num] = 1;
    count++;
    for(int i = 0; i < V; i++)
    {
        if(i != break_node && arr[num][i] == 1 && vis[i] == 0)
        {
            DFS(i, break_node, arr, vis);
        }
    }
}

void clear_vis(int vis[])
{
    for(int i = 0; i < V; i++)
        vis[i] = 0;
}
int main()
{
    scanf("%d %d", &V, &E);
    int arr[V][V], vis[V];
    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)  
            arr[i][j] = 0;
    }
    clear_vis(vis);        
    for(int i = 0; i < E; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        arr[a][b] = 1;
        arr[b][a] = 1;
    }
    int main_server;
    scanf("%d", &main_server);

    DFS(main_server, V, arr, vis);
    int min_count = count, index = -1;

    for(int i = 0; i < V; i++)
    {
        count = 0;
        clear_vis(vis);
        DFS(main_server, i, arr, vis);
        if(count < min_count)
        {
            printf("Index = %d Count = %d\n", i, count);
            index = i;
            min_count = count;
        }
    }

    if(index != -1)
        printf("%d ", index);
    else
        printf("BLACKOUT");
}