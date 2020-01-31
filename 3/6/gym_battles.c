#include <stdio.h>

int V, level = 1, min_len, min_val, min_count = 0;
void DFS(int num, int arr[V][V], int vis[V], int level)
{
    vis[num] = 1;
    int flag = 0;
    for(int i =0; i < V; i++)
    {
        if(arr[num][i] == 1)
        {
            flag++;
            if(vis[i] == 0)
                DFS(i, arr, vis, level + 1);
        }
    }
    if(flag == 1)
    {
        printf("Num = %d Level = %d\n", num, level);
        if(min_len > level)
        {
            min_val = num;
            min_len = level;
            min_count = 1;
        }
        else if(min_len == level)
        {
            if(min_val > num)
            {
                min_val = num;
            }
            min_count++;
        }
    }

            
}
int main()
{
    scanf("%d", &V);
    int arr[V][V], vis[V];
    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
            arr[i][j] = 0;
        vis[i] = 0;
    }
    min_len = V, min_val = V;
    for(int i = 0; i < V - 1; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        arr[a][b] = 1;
        arr[b][a] = 1;
    }
    DFS(0, arr, vis, level);  
    printf("Min. Value = %d Count = %d", min_val, min_count);
}