#include <stdio.h>

int r, c;
int traverse(int arr[r][c], int r1, int c1, int r2, int c2)
{
    
    if(r1 == r2 && c1 == c2)
    {
        return 1;
    }
    else if(r1 >= r || c1 >= c || r1 < 0 || c1 < 0)
        return 0;
    else if(arr[r1][c1] == 0 || arr[r1][c1] == 2)  // if arr = 2, then that cell is already visited, no need to visit it once again
    {
        if(arr[r1][c1] == 2)
            printf("r = %d, c = %d arr[][] = %d\n", r1, c1, arr[r1][c1]);
        return 0;
    }
    else
        arr[r1][c1] = 2;   // arr = 2 so as to mark it visited

    printf("r = %d, c = %d\n", r1, c1);
    return traverse(arr, r1 + 1, c1, r2, c2) + traverse(arr, r1, c1 + 1, r2, c2) + traverse(arr, r1 - 1, c1 , r2, c2) + traverse(arr, r1, c1 - 1, r2, c2);
}
int main()
{
    
    scanf("%d %d", &r, &c);
    int arr[r][c];
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    int r1, c1, r2, c2;
    scanf("%d %d", &r1, &c1);
    scanf("%d %d", &r2, &c2);
    int count = traverse(arr, r1, c1, r2, c2);
    if(count)
        printf("YES");
    else
        printf("NO");

}