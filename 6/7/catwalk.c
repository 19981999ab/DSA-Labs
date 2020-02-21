#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <math.h>
#define N 5000
int arr[N][N];
#define min(a,b) a < b ? a : b
int main()
{ 
    int n;
    scanf("%d", &n);
    int vis[n];
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
        {
            arr[i][j] = 1e9;
            if(i == j)
                arr[i][j] = 0;
        }
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= n - 1; i++)
    {
        int x, y, d;
        scanf("%d %d %d", &x, &y, &d);
        vis[x]++; vis[y]++;
        arr[x][y] = d; arr[y][x] = d;
    }
    int source, max_step;
    scanf("%d %d", &source, &max_step);
    for(int j = 0; j < n; j++)
        for(int k = 0; k < n; k++)
            arr[source][j] = min(arr[source][j], arr[source][k] + arr[k][j]);
    int ok = 0;
    for(int i = 0; i < n; i++)
        if(arr[source][i] <= max_step && vis[i] == 1) ok = 1, printf("%d ", i);
    if(ok == 0)
        printf("MEOW");
    return 0;
}