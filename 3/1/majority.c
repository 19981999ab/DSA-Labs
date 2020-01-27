#include<stdio.h>
#define ll long long int
void findMajority(int arr[], int n) 
{ 
    int cnt = 0, result;
    for (int i = 0; i < n; ++i) 
    {
        if (cnt == 0) 
            result = arr[i];
        if (result == arr[i]) 
            ++cnt;
        else --cnt;
    }
    cnt=0;
    for(int i = 0; i < n; ++i)
    {
        if(arr[i]==result)
            cnt++;
    }
    if(cnt > (n/2))
        printf("%d",result);
    else
        printf("NO MAJORITY ELEMENT");
} 
int main() 
{ 
  
    int num;
    scanf("%d",&num);
    int arr[num];
    for(int i=0;i<num;i++)
    {
        scanf("%d",&arr[i]);
    }
        
    int n = sizeof(arr) / sizeof(arr[0]); 
    findMajority(arr, n); 
    return 0; 
} 