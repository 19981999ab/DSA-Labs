#include <stdio.h>
#include<string.h>
#include <stdbool.h>
#include <limits.h>
int max_dist = INT_MIN, V, temp_dest, distance;
void DFS(int num, int arr[V][V], int vis[V])
{
    distance++;
    vis[num]++;
    for(int i = 0; i < V; i++)
        if(arr[num][i] == 1 && vis[i] == 0)    DFS(i, arr, vis);
    if(distance >= max_dist) max_dist = distance, temp_dest = num;
    distance--; 
    
}
int main()
{
    int final_dist = 0, final_dest, final_source;
    scanf("%d", &V);
    int arr[V][V], vis[V];
    memset(arr, 0, sizeof(arr));
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < V - 1; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        arr[u][v] = 1;
        arr[v][u] = 1;
    }
    for(int i = 0; i < V; i++)
    {
        distance = 0;
        memset(vis, 0, sizeof(vis));
        DFS(i, arr, vis);
        if(max_dist > final_dist) final_dist = max_dist, final_source = i, final_dest = temp_dest; 
        printf("%d %d %d\n", i, final_dest, max_dist);
    }
    printf("%d\n%d %d", final_dist - 1, final_source, final_dest);
}