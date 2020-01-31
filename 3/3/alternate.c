#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>

#define mod 998244353

int ptr=0;

void primes(int prime[], int max)
{
    for(int i=2;i<=max;i++)
    {
        bool flag = true;

        for(int j = 2;j*j <= i; j++)
            if(i%j == 0)
                flag = false;

        if(flag == true)
            prime[ptr++] = i;
    }
}

void factorise(int freq[], int prime[], int num)
{
    for(int i = 2; i <= num; i++)
    {
        for(int j = 0; prime[j] <= i && j < ptr ; j++)
        {
            int curr = i;
            while(curr % prime[j]==0)
            {
                curr /= prime[j];
                freq[prime[j]]++;
            }
        }
    }
}

int modularexpansion(int base, int pow)
{
    if(pow == 0)
        return 1;

    return base * modularexpansion(base % mod, pow - 1) % mod;
}

int main()
{
    int x1, y1, z1, x2, y2, z2, k, m, n;
    scanf("%d %d %d\n%d %d %d", &x1, &y1, &z1, &x2, &y2, &z2);
    
    k = abs(x2 - x1);
    m = abs(y2 - y1);
    n = abs(z2 - z1);
    
    int max = k + m + n;
    int den[max+1], num[max+1], prime[max], mode[max+1];

    for(int i = 0;i <= max; i++)
    {
        den[i] = 0;
        num[i] = 0;
        mode[i] = -1;
    }

    primes(prime,max);
    factorise(den,prime,k);
    factorise(den,prime,m);
    factorise(den,prime,n);
    factorise(num,prime,max);

    for(int i=0; i <= max; i++)
        num[i] -= den[i];

    for(int i=0;i<=max;i++)
        mode[i] = modularexpansion(i,num[i]);

    long long int ans=1;

    for(int i=0;i <= max; i++)
        ans=((ans % mod) * (mode[i] % mod)) % mod;

    printf("%lld", ans);
    return 0;
}