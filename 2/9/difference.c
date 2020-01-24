#include<stdio.h>
#define ll long long int 

int main()
{
    ll num;
    scanf("%lld",&num);
    int hash[10]={0};
    for(ll i=num;i>0;i=i/10)
    {
        hash[i%10]++;
    }
    ll largest=0;
    ll smallest=0;
    for(int i=9;i>=0;i--)
    {
        int temp=hash[i];
        while(temp!=0)
        {
            largest=largest*10+i;
            temp--;
        }
    }
    for(int i=1;i<10;i++)
    {

        if(hash[i]!=0)
        {
            smallest=i;
            hash[i]--;
            break;
        }
            
    }
    for(int i=0;i<10;i++)
    {
        int temp=hash[i];
        while(temp!=0)
        {
            smallest=smallest*10+i;
            temp--;
        }
    }
    printf("\n%lld %lld\n",largest,smallest);
    printf("%lld",largest-smallest);


}