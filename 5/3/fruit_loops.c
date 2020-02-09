#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int V, count;
void DFS_count(int arr[V + 1][V + 1], int vis[], int num)
{
    vis[num] = 1;
    count++;
    for(int i = 1; i <= V; i++)
        if(arr[num][i] == 1 && vis[i] == 0)
                DFS_count(arr, vis, i);
}
void DFS_final(int arr[V + 1][V + 1], int vis[], int num)
{
    vis[num] = 1;
    count++;
    printf("%d ", num);
    bool flag;
    for(int i = 1; i <= V; i++)
    {
        if(arr[num][i] == 1 && vis[i] == 0)
        {
            flag = true;
            for(int j = 1; j <= V; j++)
            {
                if(arr[j][i] == 1 && vis[j] == 0)
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
                DFS_final(arr, vis, i);
        }
    }
}
int main()
{
    int len;
    scanf("%d %d", &V, &len);
    int arr[V + 1][V + 1], vis[V + 1];
    memset(arr, 0, sizeof(arr));
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < len; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        arr[v][u] = 1;
    }
    for(int i = 1; i <= V; i++)
    {
        count = 0;
        memset(vis, 0, sizeof(vis));
        DFS_count(arr, vis, i);
        if(count == V)
        {
            count = 0;
            memset(vis, 0, sizeof(vis));
            DFS_final(arr, vis, i);
            break;
        }
    }
}