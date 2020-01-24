#include<stdio.h>
// #include<math.h>
#define ll long long int
int main()
{
    ll num;
    scanf("%lld",&num);
    ll xor=-1;
    
    if(num%2==0)
    {
        xor=2;
        while(num%2==0)
            num/=2;
    }
    for(ll i=3;i*i<=num;i+=2)
    {
        if(num%i==0)
        {
            if(xor==-1)
                xor=i;
            else
                xor=xor^i;
            while(num%i==0)
                num/=i;
     
        }
    }
    if(num>2 && xor!=-1)
        xor^=num;
    if(xor!=-1)
        printf("%lld",xor);
    else
        printf("%lld",num);
}