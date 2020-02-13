#include <stdio.h>
int n, m, adj[1001][1001], vis[1001], mark[1001], ch, ans[1001], it;
void dfs(int node)
{
	vis[node] = 1, mark[node] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (adj[node][i] && mark[i]) 
			ch = 1;	
		if (adj[node][i] && !vis[i]) 
			dfs(i);
	}
	ans[it++] = node, mark[node] = 0;
}
int main(){
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		adj[y][x] = 1;
	}
	for(int i = 1; i <= n; i++) 
		if (!vis[i]) 
		 	dfs(i);
	if (ch) 
		printf("NOT POSSIBLE");
	else 
		for(int i = n - 1; i >= 0; i--)
			printf("%d ", ans[i]);
}