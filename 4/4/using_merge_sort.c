#include <stdio.h>
#include <string.h>
#include <math.h>
#define min(a, b) ((a > b) ? b : a)
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];
    for(int i = 0; i < n1; i++) L[i] = arr[l + i];
    for(int i = 0; i < n1; i++) R[i] = arr[m + 1 + i];
    int i, j, k;
    i = j = 0;
    k = l;
    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
            arr[k] = L[i++];
        else
        {
            arr[k] = R[j++];
        }
        k++;
    }
    while(i < n1)
        arr[k++] = L[i++];
    while(j < n2)
        arr[k++] = R[j++];
}
void merge_sort(int arr[], int l, int r)
{
    if(l < r)
    {
        int m = (l + r) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
} 
int main()
{
    int len, stops;
    scanf("%d %d", &len, &stops);
    int arr[len];
    for(int i = 0; i < stops; i++)
        scanf("%d", &arr[i]);
    merge_sort(arr, 0, stops - 1);
    for(int i = 0; i < stops; i++)
        printf("%d ", arr[i]);
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