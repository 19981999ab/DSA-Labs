#include <stdio.h>
#define ll long long int
ll square_root(ll num)
{
    ll x = num; 
    ll y = 1; 
    while (x > y) 
    { 
        x = (x + y) / 2; 
        y = num / x; 
    } 
    return x; 

}
int main()
{
    ll len;
    scanf("%lld", &len);
    for(int i = 0; i < len; i++)
    {
        ll num;
        scanf("%lld", &num);
        printf("%lld ", square_root(num));
    }
    
}