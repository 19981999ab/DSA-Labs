#include<stdio.h> 
#define ll long long int
int x_max, y_max, z_max, count=0;

ll min_path(int (*arr)[y_max + 1][z_max + 1], int  i, int j, int k)
{
    if(i > x_max || j > y_max || k > z_max)
    {
        return 0;
    }
    else if(i == x_max && j == y_max && k == z_max)
    {
        arr[i][j][k]=1;
        return 1;
    }
    else if(arr[i][j][k] != 0)
    {
        return 1;
    }

    arr[i][j][k] = 1;

    return min_path(arr, i+1,j,k) + min_path(arr, i, j + 1, k) + min_path(arr, i, j, k + 1);
}

int main()
{
    int x_min, y_min, z_min;

    scanf("%d %d %d", &x_max, &y_max, &z_max);
    scanf("%d %d %d", &x_min, &y_min, &z_min);

    x_max = x_max - x_min;
    y_max = y_max - y_min;
    z_max = z_max - z_min;

    int arr[x_max + 1][y_max + 1][z_max + 1];
    for(int i = 0; i <= x_max; i++)
        for(int j = 0; j <= y_max; j++)
            for(int k = 0; k <= z_max; k++)
            {
                arr[i][j][k] = 0;
            }

    int (*p)[y_max + 1][z_max + 1] = arr;
    
    printf("%lld\n", min_path(p,0,0,0));

}