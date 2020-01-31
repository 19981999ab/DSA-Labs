#include<stdio.h>

int collatz(int arr[],int num, int len)
{
    int next;
    if(num <= len && arr[num] != -1)
        return arr[num];

    else if(num % 2)
        next = 3*num + 1;
        
    else
        next = num/2;

    int count = collatz(arr, next, len);

    if(num <= len)
    {
        arr[num] = count + 1;
    }    
    return count + 1;
}
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n+1], dummy;
    for(int i = 0; i <= n; i++)
        arr[i] = -1;

    arr[0] = 0, arr[1] = 1, arr[2] = 2;
    
    for(int i = 0; i <= n; i++)
        dummy = collatz(arr, i, n);

    int MAX = 2, index = 2;
    for(int i = 0; i <= n; i++)
    {
        if(arr[i] > MAX)
        {
            MAX = arr[i];
            index = i;
        }
    }
    printf("%d %d",index,MAX);
    
}