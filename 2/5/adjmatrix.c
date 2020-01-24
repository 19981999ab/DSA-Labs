#include<stdio.h>
#include<stdlib.h>

int V,E;

void DFS(int src, int vis[], int a[V+1][V+1])
{
    vis[src]=1;
    for(int i=1;i<=V;i++)
        if(vis[i]==0 && a[src][i]==1)
            DFS(i,vis,a);
}

int main()
{
     scanf("%d %d",&V,&E);

    int a[V+1][V+1];

    for(int i=0;i<=V;i++)
        for(int j=0;j<=V;j++)
            a[i][j]=0;

    for(int i=0;i<E;i++)
    {
        int u,v;
        scanf("%d %d", &u,&v);
        a[u][v]=1;
    }

    int vis[V+1];
    for(int j=1;j<=V;j++)
    {
        for(int i=0;i<=V;i++)
            vis[i]=0;

        int check=1;
        DFS(j,vis,a);

        for(int i=1;i<=V;i++)
            if(vis[i]==0)
            {
                check=0;
                break;
            }

        if(check)
            printf("%d ",j);

    }
    return 0;
}