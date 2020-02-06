#include<stdio.h>
#define LIMIT 100000000
typedef struct Node
{
    int exp, index;
}node;
void swap(node arr[], int i, int j)
{
    node temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void bubble_sort(node arr[], int len)
{
    for(int i = 0; i < len; i++)
        for(int j = 0; j < len - i - 1; j ++)
            if(arr[j].exp > arr[j + 1].exp)
                swap(arr, j, j + 1);

}
int main()
{
    int len, exp;
    scanf("%d", &len);
    node arr[len];
    int sum = 0;
    for(int i = 0; i < len; i++)
    {
        scanf("%d", &arr[i].exp);
        arr[i].index = i + 1;
        sum += arr[i].exp;
    }
    scanf("%d", &exp);
    if(sum < exp)
        printf("NO CHANCE");
    else
    {
        int i = 0;
        bubble_sort(arr, len);
        while(exp > 0)
        {
            exp -= arr[i].exp;
            printf("%d ", arr[i].index);
            i++;
        }
    }
}