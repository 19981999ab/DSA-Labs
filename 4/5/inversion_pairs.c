#include <stdio.h>
int inversions = 0;
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
        else    arr[k] = R[j++], inversions += n1 - i;
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
void printArray(int A[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 
int main()
{
    int len;
    scanf("%d", &len); 
    int arr[len];
    for(int i = 0; i < len; i++)
        scanf("%d", &arr[i]);
    merge_sort(arr, 0, len);
    printArray(arr, len);
    printf("%d", inversions);
}