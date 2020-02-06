#include <stdio.h>
#include <math.h>
#include <string.h>
#define LIMIT 60
typedef struct Node{
    char s[LIMIT];
    int len;
}node;
int compare(node arr1, node arr2)
{
    int k;
    if(arr1.len > 0)
        k = 0;
    else
        k = 1;
    for(; k < abs(arr1.len); k++)
    {
        if(arr1.s[k] - '0' < arr2.s[k] - '0')
            return 2; 
        else if(arr1.s[k] - '0' > arr2.s[k] - '0')
            return 1;
    }
    return 1;
}
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
        if(L[i].len > R[j].len)
            arr[k] = L[i++];
        else if(L[i].len == R[j].len)
        {
            if(compare(L[i], R[j]) == 1)
                arr[k] = L[i++];
            else
                arr[k] = R[j++];
        }
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

void printArray(node arr[], int len)
{
    for(int i = 0; i < len; i++)
    {
        printf("%s\n", arr[i].s);
    }
}
int main()
{
    int len;
    scanf("%d", &len);
    node arr[len];
    for(int i = 0; i < len; i++)
    {
        scanf("%s", &arr[i].s);
        arr[i].len = strlen(arr[i].s);
        if(arr[i].s[0] == '-')
            arr[i].len *= -1;
    }
    merge_sort(arr, 0, len - 1);
    printArray(arr, len);
}