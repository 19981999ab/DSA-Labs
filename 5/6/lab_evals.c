#include <stdio.h>
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];
    for(int i = 0; i < n1; i++) L[i] = arr[l + i];
    for(int i = 0; i < n2; i++) R[i] = arr[m + 1 + i];
    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2)
    {
        if(L[i] < R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while(i < n1) arr[k++] = L[i++];
    while(j < n2) arr[k++] = R[j++];
}
void merge_sort(int arr[], int l, int r)
{
    if(l < r)
    {
        int m = l + (r - l) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main()
{
    int len;
    scanf("%d", &len);
    int arr[len];
    for(int i = 0; i < len; i++) scanf("%d", &arr[i]);
    merge_sort(arr, 0, len - 1);
    int unique = 1, count = 1;
    //for(int i = 0; i < len; i++) printf("%d ", arr[i]);
    for(int i = 1; i < len; i++)
        if(arr[i] == arr[i - 1]) count += unique;
        else count += ++unique;
    printf("%d", count);
}
