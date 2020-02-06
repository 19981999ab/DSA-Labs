#include <stdio.h>
#include <string.h>
#define LIMIT 60
typedef struct Node{
    char s[LIMIT];
    int len;
}node;
void swap_struct(node arr[], int index_1, int index_2)
{
    node temp = arr[index_1];
    arr[index_1] = arr[index_2];
    arr[index_2] = temp;
}
void sort_len(node arr[], int start, int end)
{
    for(int i = start; i < end; i++)
    {
        for(int j = start; j < end - i - 1; j++)
        {
            if(arr[j].len < arr[j + 1].len)
            {
                swap_struct(arr, j, j + 1);
            }
        }
    }
}
void compare(node arr[], int start, int end)
{
    for(int i = start; i < end; i++)
    {
        for(int j = start; j < end - i - 1; j++)
        {
            int k;

            if(arr[j].len > 0)
                k = 0;
            else
                k = 1;

            for(; k < arr[j].len; k++)
            {
                if(arr[j].s[k] - '0' > arr[j + 1].s[k] - '0')
                {
                    break;
                }   
            }
            if(k == arr[j].len)
                swap_struct(arr, j, j + 1);
                
        }
    }
}
void printArray(node arr[], int len)
{
    for(int i = 0; i < len; i++)
    {
        printf("%s\n", arr[i].s);
    }
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
    sort_len(arr, 0, len);
    int start = 0, end, len_temp = arr[0].len;
    for(int i = 1; i < len; i++)
    {
        if(len_temp != arr[i].len)
        {
            end = i;
            compare(arr, start, end);
            start = i;
        }
    }
    printArray(arr, len);
}