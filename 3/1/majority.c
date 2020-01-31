#include<stdio.h>
#include<math.h>
#define ll long long int
void findMajority(int arr[], int len) 
{ 
    int count = 0, result;
    for (int i = 0; i < len; ++i) 
    {
        if (count == 0) 
            result = arr[i];
        if (result == arr[i]) 
            ++count;
        else --count;
    }

    count = 0;
    for(int i = 0; i < len; ++i)
    {
        if(arr[i] == result)
            count++;
    }

    float check = len;
    check = floor(check/2);
    if(count > check)
        printf("%d", result);
    else if(count == check && len % 2 == 0)
    {
        int result_2 = result;
        for(int i = 0; i <len ; i++)
        {
            if(result_2 != arr[i])
            {
                result_2 = arr[i];
            }
                
        }
        count = 0;
        for(int i = 0; i < len; ++i)
        {
            if(arr[i] == result_2)
                count++;
        }
        if(result_2 > result && count == check)
            printf("%d",result_2);
        else
            printf("%d",result);
    }
    else
        printf("NO MAJORITY ELEMENT");
} 
int main() 
{ 
  
    int len;
    scanf("%d",&len);
    int arr[len];
    for(int i=0;i<len;i++)
    {
        scanf("%d",&arr[i]);
    }
        
    int n = sizeof(arr) / sizeof(arr[0]); 
    findMajority(arr, n); 
    return 0; 
} 