#include <stdio.h>
int binary_search(int arr[], int l, int r, int num)
{
    // printf("%d %d %d\n", l, r, num);
    int m = (l + r) / 2;
    if(l == r)
        return arr[m] <= num ? m : -1;
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
        // int index = binary_search(arr, i + 2, len - 1, sum + arr[i]);
        // count += (index == -1 ? 0 : (index - i) * (index - i - 1) / 2);
        // printf("Index = %d\n", index);
        for(int j = i + 2; j < len; j++)
        {
            if(arr[j] - arr[i] <= sum) count += (j - i - 1);
            else break;
        }

    }
    printf("%d", count);
}