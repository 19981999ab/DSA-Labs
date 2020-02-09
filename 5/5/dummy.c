#include <stdio.h>
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 
int binary_search(int arr[], int l, int r, int num)
{
    int m = (l + r) / 2;
    if(l > r) return -1;
    if(arr[m] == num) return m;
    else if(num < arr[m])
    {
        if(m == l) return -1;
        else if(num > arr[m - 1]) return m;
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
    for(int i = 0; i < m; i++) printf("%d ", arr[i]);
    printf("\n");
    // merge_sort(can, 0, l - 1);
    // for(int i = 0; i < l; i++) printf("%d ", can[i]);
    // int start_index = binary_search(arr, 0, m, u), end_index = binary_search(arr, 0, m, v);
    // int count = 0;
    // for(int i = start_index; i < end_index; i++)
    // {
    //     int miles = arr[i + 1] - arr[i] - b;
    //     printf("MILES = %d", miles);
    //     if(miles % a) miles = miles / a + 1;
    //     else miles /= a;
       
    //     if(binary_search(can, 0, l, miles) == 0)
    //     {
    //         printf("NOT POSSIBLE\n");
    //         break;
    //     }
    //     count += miles;
    // }
    // printf("%d", end_index);
}