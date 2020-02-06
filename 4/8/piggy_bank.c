#include <stdio.h>
#include <string.h>
int main()
{
    int piggy_bank, num;
    scanf("%d %d", &piggy_bank, &num);
    int arr[piggy_bank];
    memset(arr, 0, sizeof(arr));
    
    for(int i = 0; i < num; i++)
    {
        int left, right, count;
        scanf("%d %d %d", &left, &right, &count);
        for(int j = left; j <= right; j++)
        {
            arr[j] += count;
        }
    }
    for(int i = 0; i < piggy_bank; i++)
    {
        printf("%d ", arr[i]);
    }
}