#include<stdio.h>
#include<stdlib.h>
int V,E,count;

void DFS(int src, int a[V+1][V+1], int vis[v+1])
{
    vis[src]=1;
    count++;
    for(int i=1;i<=V;i++)
    {
        if(vis[i]==0 && a[src][i]==1)
            DFS(i,a,vis);
    }
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
        scanf("%d %d",&u,&v);
        a[u][v]=1;
        a[v][u]=1;
    }

    int vis[V+1];

    int max=-1,root=1;

    for(int i=1;i<=V;i++)
    {
        count=0;
        for(int i=0;i<=V;i++)
            vis[i]=0;

        DFS(i,a,vis);
        
        if(count>max)
        {
            max=count;
            root=i;
        }
    }

    count=0;
    for(int i=0;i<=V;i++)
        vis[i]=0;
        
    DFS(root,a,vis);

    printf("%d\n",V-count);
    
    for(int i=1;i<=V;i++)
        if(vis[i]==0)
            printf("%d ",i);
    return 0;
}