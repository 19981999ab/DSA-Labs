#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define LIMIT 100000000
void calculate_angle(int index[], int x[], int y[], float angle[], int index_min, int len)
{
    for(int i = 0; i < len; i++)
    {
        if(i != index_min)
        {
            float tan_th = y[index_min] - y[i];
            tan_th /= x[index_min] - x[i];
            angle[i] = atan(tan_th) * 180 / 3.14;
            if(angle[i] < 0)
                angle[i] = 180 + angle[i];
        }
        
    }
}
void swap_int(int arr[], int index_1, int index_2)
{
    int temp = arr[index_1];
    arr[index_1] = arr[index_2];
    arr[index_2] = temp;
}
void swap_float(float arr[], int index_1, int index_2)
{
    float temp = arr[index_1];
    arr[index_1] = arr[index_2];
    arr[index_2] = temp;
}
void sort(int index[], int x[], int y[], float angle[], int index_min, int len)
{
    for(int i = 0; i < len; i++)
    {
        for(int j = 0; j < len - i - 1; j++)
        {
            if(angle[j] > angle[j + 1])
            {
                swap_int(index, j, j + 1);
                swap_float(angle, j, j + 1);
            }
        }
    }
}
void printArray_float(float *arr, int len)
{
    for(int i = 0; i < len; i++)
    {
        printf("%f ", arr[i]);
    }
    printf("\n");
}
void printArray_int(int *arr, int len, int exclude_index)
{
    for(int i = 0; i < len; i++)
    {
        if(arr[i] != exclude_index)
            printf("%d ", arr[i]);
    }
    printf("\n");
}
int main()
{
    int len, index_min, index_min_val, y_min = LIMIT;
    scanf("%d", &len);
    int index[len], x[len], y[len];
    float angle[len];
    for(int i = 0; i < len; i++)
    {
        scanf("%d %d %d", &index[i], &x[i], &y[i]);
        if(y[i] < y_min)
        {
            y_min = y[i];
            index_min = i;
        }
    }
    index_min_val = index[index_min];
    calculate_angle(index, x, y, angle, index_min, len);
    sort(index, x, y, angle, index_min, len);
    printArray_int(index, len, index_min_val);
}