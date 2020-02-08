#include <stdio.h>
void swap(int arr[], int index_1, int index_2)
{
    int temp = arr[index_1];
    arr[index_1] = arr[index_2];
    arr[index_2] = temp;
}
void partition(int arr[], int len, int pivot) 
{ 
    int i = -1, pivot_index = -1;
    for (int j = 0; j < len; j++) 
    { 
        if (arr[j] < pivot) 
        { 
            i++;
            swap(arr, i, j); 
        }
        else if(arr[j] == pivot)
            pivot_index = j;
    } 
    swap(arr, i + 1, pivot_index); 
}
void printArray(int *arr, int len)
{
    for(int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main()
{
    int len, pivot, pivot_index, check = 0;
    scanf("%d", &len);
    int arr[len];
    pivot_index = len;
    for(int i = 0; i < len; i++)
        scanf("%d", &arr[i]);
    scanf("%d", &pivot);
    for(int i = 0; i < len; i++)
    {
        if(arr[i] == pivot)
            pivot_index = i;
        else if(i > pivot_index && arr[i] < pivot) 
        {
            check = 1;
            break;
        }
        else if(i < pivot_index && arr[i] > pivot)
        {
            check = 1;
            break;
        }
    }
    if(check == 0)
        printf("ALL SET");
    else
    {
        partition(arr, len, pivot);
        printArray(arr, len);
    }
}