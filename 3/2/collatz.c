#include<stdio.h>

int collatz(int *arr,int n, int len)
{
    int next;
    if(n <= len && arr[n] != -1)
        return arr[n];

    else if(n % 2)
        next = 3*n + 1;
        
    else
        next = n/2;

    int count = collatz(arr, next, len);

    if(n <= len)
    {
        arr[n] = count + 1;
        return arr[n];
    }    
    else
        return count + 1;
}
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n+1],dummy;
    for(int i=0;i<=n;i++)
        arr[i]=-1;
    arr[0]=0,arr[1]=1,arr[2]=2;
    for(int i = 0; i < n; i++)
        dummy=collatz(arr, i, n);

    int MAX=2,index=2;
    for(int i = 0; i <= n; i++)
    {
        if(arr[i] > MAX)
        {
            MAX=arr[i];
            index=i;
        }
    }
    printf("%d %d",index,MAX);
    
}