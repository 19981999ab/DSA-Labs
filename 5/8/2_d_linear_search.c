#include <stdio.h>
int N, M;
int search(int arr[N][M], int N, int M, int num)
{
    if(num < arr[0][0] || num > arr[N - 1][M - 1]) return 0;
    else
    {
        int i = 0, j = M - 1;
        while(i < N && j >= 0)
        {
            if(arr[i][j] == num)
            {
                printf("YES\n%d %d", i, j);
                return 1;
            }
            else if(num > arr[i][j]) i++;
            else j--;
        }
    }
    return 0;
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
    if(!search(arr, N, M, num))
        printf("NO\n");

}