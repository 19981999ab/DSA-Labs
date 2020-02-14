#include <stdio.h>
#include <math.h>
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    long long int ans = 0, count = 0, mod = 1e9 + 7;
    for(int i = 0; i < 32; i++)
    {
        count = 0;
        for(int j = 0; j < n; j++)
        {
            if(arr[j] & (1 << i)) count++;
        }
        ans = (ans + ((((count * (n - count)) % mod) * 2) % mod)) % mod;
    }
    printf("%lld", ans);
}