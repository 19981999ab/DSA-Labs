#include <stdio.h>
#include <math.h>
#include <string.h>
#define LIMIT 60
typedef struct Node{
    char s[LIMIT];
    int len;
}node;
void swap(node arr[], int index_1, int index_2)
{
    node temp = arr[index_1];
    arr[index_1] = arr[index_2];
    arr[index_2] = temp;
}
int compare(node arr1, node arr2)
{
    int k;
    if(arr1.len > 0)
        k = 0;
    else
        k = 1;
    for(; k < abs(arr1.len); k++)
    {
        if(arr1.s[k] - '0' < arr2.s[k] - '0')
            return 2; 
        else if(arr1.s[k] - '0' > arr2.s[k] - '0')
            return 1;
    }
    return 1;
}
void bubble_sort(node arr[], int start, int end)
{
    for(int i = start; i < end; i++)
    {
        for(int j = start; j < end - i - 1; j++)
        {
            if(arr[j].len < arr[j + 1].len)
                swap(arr, j, j + 1);
            else if(arr[j].len == arr[j + 1].len)
            {
                if(compare(arr[j], arr[j + 1]) == 2)
                    swap(arr, j, j + 1);
            }
        }
    }
}

void printArray(node arr[], int len)
{
    for(int i = 0; i < len; i++)
        printf("%s\n", arr[i].s);
}
int main()
{
    int len;
    scanf("%d", &len);
    node arr[len];
    for(int i = 0; i < len; i++)
    {
        scanf("%s", &arr[i].s);
        arr[i].len = strlen(arr[i].s);
        if(arr[i].s[0] == '-')
            arr[i].len *= -1;
    }
    bubble_sort(arr, 0, len);
    printArray(arr, len);
}