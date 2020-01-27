#include <stdio.h> 
#include <string.h>
#define ll long long int
void gray_code(ll num)
{
    ll arr[33];
    ll res = num ^ (num >> 1), count=0;
    if(num == 0)
    {
        printf("0\n");
        return;
    }
    while(res>0)
    {
        arr[count] = res % 2;
        res /= 2;
        count++;
    }
    for(ll j = count - 1; j>=0; j--)
        printf("%lld", arr[j]);
    printf("\n");
    
}
ll decimal(int gray[], int len)
{  
    int binary[len];
    ll num;
    binary[0] = gray[0];
    num = binary[0] * (1 << (len - 1));
    for(int i = 1; i < len; i++)
    {
        binary[i] = binary[i-1] ^ gray[i];
        num += binary[i] * (1 << (len - i - 1));
    }
    return num;

}
int main()
{
    ll n;
    char ch;
    ll d;
    scanf("%lld", &n);
    
    for(ll i = 0; i < n; i++)
    {
        scanf(" %c", &ch);
        if(ch == 'G')
        {
            // char ch = getchar();
            scanf("%lld", &d);
            gray_code(d);
        }
        else if(ch == 'D')
        {
            char s[100], ch = getchar();
            fgets(s, 100, stdin);
            int len = strlen(s) - 1;
            int gray[len];
            for(int i = 0; i < len; i++)
                gray[i] = s[i]-'0';
            printf("%lld\n", decimal(gray, len));
        }
    }
}