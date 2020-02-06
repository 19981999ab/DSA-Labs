#include <stdio.h>
void swap(int arr[], int index_1, int index_2)
{
    int temp = arr[index_1];
    arr[index_1] = arr[index_2];
    arr[index_2] = temp;
}
int partition(int arr[], int len, int pivot) 
{ 
    int low = 0;
    int i = (low - 1);
    int pivot_index;
    for (int j = low; j <= len - 1; j++) 
    { 
        if (arr[j] < pivot) 
        { 
            i++;
            swap(arr, i, j); 
        }
        else if(arr[j] == pivot)
        {
            pivot_index = j;
        }
    } 
    swap(arr, i + 1, pivot_index); 
    return i + 1 == pivot_index;
}
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
    int len, pivot;
    scanf("%d", &len);
    int arr[len];
    for(int i = 0; i < len; i++)
    {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &pivot);
    
    if(partition(arr, len - 1, pivot))
        printf("ALL SET");
    else
        printArray(arr, len);
}