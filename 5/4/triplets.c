#include <stdio.h>
int binary_search(int arr[], int l, int r, int num)
{
    // printf("%d %d %d\n", l, r, num);
    if(l == r)
        return arr[l] <= num ? l : -1;
    int m = (l + r) / 2;
    if(num < arr[m]) return binary_search(arr, l, m, num);
    int ret = binary_search(arr, m + 1, r, num);
    return ret == -1 ? m : ret;

}
int main()
{
    int len, sum;
    scanf("%d %d", &len, &sum);
    int arr[len], count = 0;
    for(int i = 0; i < len; i++) scanf("%d", &arr[i]);
    for(int i = 0; i < len - 2; i++) 
    {
        int index = binary_search(arr, i + 2, len - 1, sum + arr[i]);
        count += (index == -1 ? 0 : (index - i) * (index - i - 1) / 2);
        // printf("Index = %d\n", index);

    }
    printf("%d", count);
}