#include<stdio.h>
#define LIMIT 100000000
typedef struct Node
{
    int exp, index;
}node;
void merge(node arr[], int l, int m, int r)
{
    int n1 = m - l + 1, n2 = r - m;
    node L[n1], R[n2];
    for(int i = 0; i < n1; i++) L[i] = arr[l + i];
    for(int i = 0; i < n2; i++) R[i] = arr[m + 1 + i];
    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2)
    {
        if(L[i].exp <= R[j].exp)
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
    int len, exp;
    scanf("%d", &len);
    node arr[len];
    int sum = 0;
    for(int i = 0; i < len; i++)
    {
        scanf("%d", &arr[i].exp);
        arr[i].index = i + 1;
        sum += arr[i].exp;
    }
    scanf("%d", &exp);
    if(sum < exp)
        printf("NO CHANCE");
    else
    {
        merge_sort(arr, 0, len - 1);
        int i = 0;
        while(exp > 0)
        {
            exp -= arr[i].exp; 
            printf("%d ", arr[i].index);
            i++;
        }
    }
}