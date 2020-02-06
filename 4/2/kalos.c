#include<stdio.h>
#define LIMIT 100000000
void printArray(int *arr, int len)
{
    for(int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main()
{
    int len, exp;
    scanf("%d", &len);
    int arr[len], sum = 0;
    for(int i = 0; i < len; i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    scanf("%d", &exp);
    if(sum < exp)
        printf("NO CHANCE");
    else
    {
        while(exp > 0)
        {
            int min = LIMIT, min_index;
            for(int i = 0; i < len; i++)
            {
                if(arr[i] < min && arr[i] != -1)
                {
                    min = arr[i];
                    min_index = i;
                }
            }
            exp -= min; 
            arr[min_index] = -1;
            printf("%d ", min_index + 1);
        }
    }
}