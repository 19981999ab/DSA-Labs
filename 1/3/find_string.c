#include<stdio.h>
#include<string.h>
int compare_arrays();
int main()
{
    char str_inp[100];
    gets(str_inp);
    char str_test[100];
    gets(str_test);

    // printf("%s %s",str_inp,str_test);

    int arr[26],check_arr[26];
    for(int i=0;i<26;i++)
    {
        arr[i]=0;
        check_arr[i]=0;
    }

    for(int i=0;i<strlen(str_test);i++)
    {
        arr[str_test[i]-'a']+=1;
    }
    for(int i=0;i<26;i++)
    {
        printf("%d ",arr[i]);
    }
    int start_pos=0;
    int end_pos=start_pos;
    int MIN=0,MAX=strlen(str_inp);
    while(start_pos<strlen(str_inp))
    {
        for(;end_pos<strlen(str_inp);end_pos++)
        {
            if(str_inp[end_pos]==' ')
                continue;
            check_arr[str_inp[end_pos]-'a']+=1;
            if(compare_arrays(check_arr,arr))
            {
                break;
            }
                
        }
        if(end_pos>=strlen(str_inp))
            break;
        while(compare_arrays(check_arr,arr))
        {
            check_arr[str_inp[start_pos]-'a']-=1;
            start_pos++;
        }
        printf("\n%d %c %d %c",start_pos-1,str_inp[start_pos-1],end_pos,str_inp[end_pos]);
        if(MAX-MIN>end_pos-(start_pos-1))
        {
            MAX=end_pos;
            MIN=start_pos-1;
        }
        end_pos+=1;
    }
    if(MAX==0 && MIN==0)
    {
        printf("NO WINDOW");
    }
    else
    {
        printf("\n%d %d \n",MIN,MAX);
        for(int i=MIN;i<=MAX;i++)
            printf("%c",str_inp[i]);
    }
        
    return 0;
}
int compare_arrays(int arr_check[],int arr_test[])
{
    for(int i=0;i<26;i++)
    {
        if(arr_check[i]<arr_test[i])
            return 0;
    }
    return 1;
}