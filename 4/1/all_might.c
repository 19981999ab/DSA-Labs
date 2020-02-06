#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define LIMIT 100000000
#define PI acos(-1)
typedef struct Node
{
    int index, x, y;
    float angle;
}node;
void calculate_angle(node arr[], int len, int index_min)
{
    for(int i = 0; i < len; i++)
    {
        if(i != index_min)
        {
            float tan_th = (arr[index_min].y - arr[i].y);
            tan_th /= (arr[index_min].x - arr[i].x);
            arr[i].angle = atan(tan_th) * 180 / PI;
            if(arr[i].angle < 0)
                arr[i].angle += 180;
        }
    }
}
void swap_struct(node arr[], int index_1, int index_2)
{
    node temp = arr[index_1];
    arr[index_1] = arr[index_2];
    arr[index_2] = temp;
}
void printArray_angle(node arr[], int len, int all_might_index)
{
    for(int i = 0; i < len; i++)
    {
        if(arr[i].index == all_might_index)
            continue;
        printf("%f ", arr[i].angle);
    }
    printf("\n");
}
void printArray_index(node arr[], int len, int all_might_index)
{
    
    for(int i = 0; i < len; i++)
    {
        if(arr[i].index == all_might_index)
            continue;
        printf("%d ", arr[i].index);
    } 
    printf("\n");
}
void sort(node arr[], int len, int all_might_x, int all_might_y)
{
    for(int i = 0; i < len; i++)
    {
        for(int j = 0; j < len - i - 1; j++)
        {
            if(arr[j].angle > arr[j + 1].angle)
                swap_struct(arr, j, j + 1);
            else if(arr[j].angle == arr[j + 1].angle)
            {
                float distance_1  = pow((all_might_x - arr[j].x), 2) + pow((all_might_y - arr[j].y), 2);
                float distance_2  = pow((all_might_x - arr[j + 1].x), 2) + pow((all_might_y - arr[j + 1].y), 2);
                if(distance_2 < distance_1)
                    swap_struct(arr, j, j + 1);
            }
        }
    }
}

int main()
{
    int len, index_min, y_min = LIMIT;
    scanf("%d", &len);
    node arr[len];
    for(int i = 0; i < len; i++)
    {
        scanf("%d %d %d", &arr[i].index, &arr[i].x, &arr[i].y);
        if(arr[i].y < y_min)
        {
            y_min = arr[i].y;
            index_min = i;
        }
    }
    int all_might_index = arr[index_min].index, all_might_x = arr[index_min].x, all_might_y = arr[index_min].y;
    calculate_angle(arr, len, index_min);
    sort(arr, len, all_might_x, all_might_y);
    printArray_angle(arr, len, all_might_index);
    printArray_index(arr, len, all_might_index);
}