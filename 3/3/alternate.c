#include<stdio.h> 
#define ll long long int
int x_max, y_max, z_max, count=0;

int min_path(int  i, int j, int k)
{
    if(i > x_max || j > y_max || k > z_max)
    {
        return 0;
    }
    else if(i == x_max && j == y_max && k == z_max)
    {
        return 1;
    }

    return min_path(i + 1, j, k) + min_path(i, j + 1, k) + min_path(i, j, k + 1);
}

int main()
{
    int x_min, y_min, z_min;

    scanf("%d %d %d", &x_max, &y_max, &z_max);
    scanf("%d %d %d", &x_min, &y_min, &z_min);

    x_max = x_max - x_min;
    y_max = y_max - y_min;
    z_max = z_max - z_min;
    printf("%lld\n", min_path(0,0,0));

}