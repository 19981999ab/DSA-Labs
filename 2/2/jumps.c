#include<stdio.h>
#include<stdlib.h>

int min(int a,int b)
{
    if(a<b)
        return a;
    return b;
}

int main()
{
    int a,b,c,d,e,f;
    int t;
    scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f);
    scanf("%d",&t);
    int arr_test[t];
    int MAX=0;
    for(int i=0;i<t;i++)
    {
        scanf("%d",&arr_test[i]);
        if(arr_test[i]>MAX)
            MAX=arr_test[i];
    }
    
    int arr[MAX+1];
    for(int i=0;i<=MAX;i++)
    {
        arr[i]=MAX+1;
    }
    arr[0]=0;
    for(int i=0;i<=MAX;i++)
    {
        if(arr[i]!=MAX+1)
        {
            int jump[3]={a*i+b,c*i+d,e*i+f};
            for(int j=0;j<3;j++)
            {
                if(jump[j]<=MAX)
                    arr[jump[j]]=min(arr[i]+1,arr[jump[j]]);
            }
        }
        else
            arr[i]=-1;
    }
    for(int i=0;i<t;i++)
    {
        printf("%d ",arr[arr_test[i]]);
    }
    
}