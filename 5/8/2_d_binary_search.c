#include <stdio.h>
int N, M;
int search_row(int arr[N][M], int l, int r, int num)
{
    int m = (l + r) / 2;
    if(l > r) return -1;
    if(num >= arr[m][0])
        if(m == r || num <= arr[m + 1][0])
            return m;
    else if(num < arr[m][0]) search_row(arr, l, m, num);
    else search_row(arr, m + 1, r, num);
}
int search_column(int arr[N][M], int l, int r, int num, int row)
{
    int m = (l + r) / 2;
    if(l > r) return 0;
    if(num == arr[row][m])
    {
        printf("YES\n%d %d", row, m);
        return 1;
    }
    else if(num < arr[row][m]) search_column(arr, l, m, num, row);
    else search_column(arr, m + 1, r, num, row);
}
int main()
{
    int num;
    scanf("%d %d", &N, &M);
    int arr[N][M];
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++) 
            scanf("%d", &arr[i][j]);
    scanf("%d", &num);
    int pred_row = search_row(arr, 0, N, num);
    if(pred_row != -1)
    {
        if(!search_column(arr, 0, M, num, pred_row))
            printf("NO\n");
    }
    else printf("NO\n");

}