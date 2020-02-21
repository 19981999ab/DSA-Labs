#include <stdio.h>
#include <limits.h>

int max(int a, int b)
{
    return a > b ? a : b;
}
int main()
{
    int len;
    scanf("%d", &len);
    int arr[len], area = 0;
    for(int i = 0; i < len; i++) scanf("%d", &arr[i]);
    for(int i = 0; i < len; i++)
    {
        for(int j = i + 1; j < len; j++)
        {
            if(arr[j] < arr[i])
            {
                printf("%d %d\n", i, j);
                area = max(area, (j - i) * arr[i]);
                break;
            }
            if(j == len - 1)
                area = max(area, (j - i) * arr[i]);
        }
    }
    printf("%d", area);
}