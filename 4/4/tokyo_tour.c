#include <stdio.h>
#include <string.h>
#include <math.h>
#define min(a,b) ((a > b) ? b : a)
void swap(int arr[], int index_1, int index_2)
{
    int temp = arr[index_1];
    arr[index_1] = arr[index_2];
    arr[index_2] = temp;
}
void bubble_sort(int arr[], int len)
{
    for(int i = 0; i < len; i++)
        for(int j = 0; j < len - i - 1; j ++)
            if(arr[j] > arr[j + 1])
                swap(arr, j, j + 1);

}
int main()
{
    int len, stops;
    scanf("%d %d", &len, &stops);
    int arr[len];
    for(int i = 0; i < stops; i++)
        scanf("%d", &arr[i]);

    bubble_sort(arr, stops);

    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++)
    {
        int d;
        scanf("%d", &d);
        if(d >= arr[stops - 1])
            printf("%d\n", d - arr[stops - 1]);
        else
        {
            int left = 0, right = stops - 1;
            while(1)
            {
                if(right - left <= 1)   break;
                int m = (right + left) / 2;
                if(arr[m] < d)  left = m;
                else right = m;
            }
            printf("%d\n", min(d - arr[left], arr[right] - d));
        }
    }
}