//Using Merge Sort and custom datatype instead of array
#include<stdio.h>
typedef struct Node
{
    int start, end;
}node;
void merge(node arr[], int l, int m, int r)
{
    int n1 = m - l + 1, n2 = r - m;
    node L[n1], R[n2];
    for(int i = 0; i < n1; i++) L[i] = arr[l + i];
    for(int i = 0; i < n2; i++) R[i] = arr[m + 1 + i];
    int i, j, k;
    i = j = 0;
    k = l;
    while(i < n1 && j < n2)
    {
        if(L[i].end <= R[j].end)
            arr[k] = L[i++];
        else
            arr[k] = R[j++];
        k++;
    }
    while(i < n1)
        arr[k++] = L[i++];
    while(j < n2)
        arr[k++] = R[j++];
}
void merge_sort(node arr[], int l, int r)
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
    int len;
    scanf("%d", &len);
    node arr[len];
    for(int i = 0; i < len; i++)
    {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }
    merge_sort(arr, 0, len - 1);
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