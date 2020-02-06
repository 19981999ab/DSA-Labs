#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    int len, stops;
    scanf("%d %d", &len, &stops);
    int arr[len];
    memset(arr, 0, sizeof(arr));
    for(int i = 0; i < stops; i++)
    {
        int d;
        scanf("%d", &d);
        arr[d] = 1;
    }
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++)
    {
        int d;
        scanf("%d", &d);
        int left = d, right = d, min = len;
        while(left > 0 && right < len)
        {
            if(arr[left])
            {
                min = left;
                break;
            }
            else if(arr[right])
            {
                min = right;
                break;
            }
            if(left == 0)
                right++;
            else if(right == len - 1)
                left--;
            else
            {
                right++;
                left--;
            }
            
        }
        printf("%d\n", abs(min - d));
    }
}