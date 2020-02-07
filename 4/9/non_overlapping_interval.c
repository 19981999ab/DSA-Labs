#include<stdio.h>
typedef struct Node
{
    int start, end;
}node;
void swap(node arr[], int index_1, int index_2)
{
    node temp = arr[index_1];
    arr[index_1] = arr[index_2];
    arr[index_2] = temp;
}
void bubble_sort(node arr[], int len)
{
    for(int i = 0;i < len; i++)
        for(int j = 0; j < len - i - 1; j++)
            if(arr[j].end > arr[j + 1].end)
                swap(arr, j , j + 1);
}

int main()
{
    int len;
    scanf("%d", &len);
    node arr[len];
    for(int i = 0; i < len; i++)
        scanf("%d %d", &arr[i].start, &arr[i].end);
        
    bubble_sort(arr, len);
    int count = 1, end_time = arr[0].end;
    for(int i = 1; i < len; i++)
    {
        if(end_time < arr[i].start)
        {
            end_time = arr[i].end;
            count++;
        } 
    }
    /* To print the array sorted according to end time
    for(int i = 0; i < len; i++)
    {
        printf("%d %d\n", arr[i].start, arr[i].end);
    }*/
    printf("%d ", count);

}