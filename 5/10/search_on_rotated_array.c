#include <stdio.h>

int binary_search(int arr[], int l, int r, int num)
{
    int m = (l + r) / 2;
    if(arr[m] == num) return m;
    else if(l > r) return -1;
    if(arr[l] <= arr[m])
    {
        if(num >= arr[l] && num <= arr[m]) return binary_search(arr, l, m - 1, num);
        else return binary_search(arr, m + 1, r, num);
    }
    if(num <= arr[r] && num >= arr[m]) return binary_search(arr, m + 1, r, num);
    else return binary_search(arr, l, m - 1, num);

}
int main()
{
    int len;
    scanf("%d", &len);
    int arr[len], num, result = -1;
    for(int i = 0; i < len; i++) scanf("%d", &arr[i]);
    scanf("%d", &num);
    result = binary_search(arr, 0, len - 1, num);
    result != -1 ? printf("YES\n%d", result) : printf("NO");
}