#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#define LIMIT INT_MAX
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
        int m = (l + r) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
// int binary_search(int arr[], int l, int r, int num, int excluded_index)
// {
//     int m = (l + r) / 2;
//     if(arr[m] == num && m != excluded_index) return 1;
//     if(l > r) return -1;
//     if(num < arr[m]) return binary_search(arr, l, m - 1, num, excluded_index);
//     else return binary_search(arr, m + 1, r, num, excluded_index);
// }
int main()
{
    int len;
    scanf("%d", &len);
    int arr[len], num, result = -1, sum;
    for(int i = 0; i < len; i++) scanf("%d", &arr[i]);
    scanf("%d", &sum);
    merge_sort(arr, 0, len - 1);
    int min = INT_MAX, min_val;
    int start_pos = 0, end_pos = len - 1;
    while(start_pos < end_pos)
    {
        printf("%d %d\n", arr[start_pos], arr[end_pos]);
        if((arr[start_pos] + arr[end_pos]) > sum) end_pos--;
        else if((arr[start_pos] + arr[end_pos]) < sum) start_pos++;
        else 
        {
            if(min > abs(arr[end_pos] - arr[start_pos]))
            {
                min = abs(arr[end_pos] - arr[start_pos]);
                min_val = arr[start_pos];
                start_pos++;
                end_pos--;
            }
        }
    }
    // for(int i = 0; i < len; i++)
    // {
    //     int search_result = binary_search(arr, 0, len - 1, sum - arr[i], i);
    //     if(search_result != -1)
    //     {
    //         if(min > abs(sum - 2 * arr[i])) min = abs(sum - 2 * arr[i]), min_val = arr[i];
    //     }
    // }
    min == INT_MAX ? printf("NO\n") : printf("YES\n%d %d", min_val, sum - min_val);
    
}