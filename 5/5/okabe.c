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
int binary_search(int arr[], int l, int r, int num)
{
    int m = (l + r) / 2;
    if(l == r) 
    {
        if(num <= arr[m]) return m;
        else return -1;
    }
    if(num > arr[m]) binary_search(arr, m + 1, r, num);
    else binary_search(arr, l, m, num);
}
int main()
{
    int n, m, l, u, v, a, b, k;
    scanf("%d %d %d", &n, &m, &l);
    scanf("%d %d %d %d %d", &u, &v, &a, &b, &k);
    int arr[m], can[l];
    for(int i = 0; i < m; i++) scanf("%d", &arr[i]);
    for(int i = 0; i < l; i++) scanf("%d", &can[i]);
    merge_sort(arr, 0, m - 1);
    merge_sort(can, 0, l - 1);
    int start_index = binary_search(arr, 0, m - 1, u), end_index = binary_search(arr, 0, m - 1, v);
    int count = 0;
    for(int i = start_index; i < end_index; i++)
    {
        int miles = arr[i + 1] - arr[i] - b;
        if(miles % a) miles = miles / a + 1;
        else miles /= a;
        int litres = binary_search(can, 0, l - 1, miles);
        if(litres == -1)
        {
            printf("NOT POSSIBLE\n");
            break;
        }
        printf("%d %d MILES = %d LITRES = %d\n", arr[i], arr[i + 1], miles, can[litres]);
        count += can[litres];
    }
    printf("%d", count * k);
}