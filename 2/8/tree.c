#include<stdio.h>

int main()
{
    int n;
    scanf("%d\n",&n);
    int arr[n],levels[n];
    for(int i=1;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int req_level=0,flag=0,count=0;
    scanf("%d",&req_level);
    arr[0]=0;
    levels[0]=0;
    for(int i=1;i<n;i++)
    {
        levels[i]=0;
    }
    for(int i=1;i<n;i++)
    {
        int j=i;
        count=1;
        while(arr[j])
        {
            // printf("%d %d  ",j,arr[j]);
            j=arr[j];
            count++;
        }
        levels[i]=count;
    }
    for(int i=1;i<n;i++)
    {
        if(levels[i]==req_level)
        {
            printf("%d ",i);
            flag=1;
        }
            
    }
    if(flag==0)
        printf("-1");
}