#include<stdio.h>
#include<string.h>
int stack[500][2], vis[500][500];
char word[250000], arr[500][500];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int N, M, l, top = -1, len, end_check, test, flag;
int check(int x, int y)
{
    if(x >= 0 && x < N && y >= 0 && y < M)
        return 1;
    return 0;
}
void DFS()
{  
    while(top != -1)
    {
        int x = stack[top][0];
        int y = stack[top][1];
        vis[x][y] = 1;
        top--;
        if(l == len)
            end_check = 1;
        for(int i = 0; i < 4; i++)
        {
            int x1 = x + dx[i];
            int y1 = y + dy[i];
            if(check(x1,y1))
            {
                if(arr[x1][y1] == word[l] && !vis[x1][y1] )
                {
                    stack[++top][0] = x1;
                    stack[top][1] = y1;
                    flag = 1;
                }
            }
        }
        vis[x][y] = 0;
        if(flag)
        {   
            l++;
            flag = 0;
        }
            
    }
}
int main()
{
    scanf("%d %d", &N, &M);        
    int i, j;
    for(i = 0;i < N; i++)
        for(j = 0; j < M; j++) 
            scanf(" %c", &arr[i][j]);
    scanf("%d", &test);
    while(test--)
    {
        scanf("%s", word);
        len = strlen(word);
        end_check = 0;
        memset(vis, 0, sizeof(vis));
        for(i = 0; i < N; i++)
        {
            for(j = 0; j < M; j++)
            {
                if(arr[i][j] == word[0])
                {
                    l = 1;
                    top = 0;
                    flag = 0;
                    stack[top][0] = i;
                    stack[top][1] = j;
                    vis[i][j] = 1;
                    DFS();
                    if(end_check)
                        break;
                }
            }
            if(end_check)
                break;
        }
        if(i == N && j == M)
            printf("-1\n");
        else
            printf("%d %d\n",i,j);
    }
}