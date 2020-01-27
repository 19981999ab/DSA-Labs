#include <stdio.h>

int main()
{
    int n,d;
    scanf("%d", &n);
    int arr[10] = {0};
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &d);
        arr[i % 10]++;
    }
    if(arr[0] == 0)
        printf("NO NUMBER");
    else
    {
        int hash[10] = {0};
        for(int i = 9; i >= 0; i--)
        {
            if(arr[i])
            {
                if(i % 3)
                {
                    for(int j = i; j >= 0; j--)
                    {
                        
                    }
                }
            }
        }
    }

}