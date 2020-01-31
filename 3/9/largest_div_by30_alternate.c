#include <stdio.h>

int main()
{
    int n, d, count_mod_1 = 0, count_mod_2 = 0, sum = 0, flag = 1;
    scanf("%d", &n);
    int arr[10] = {0}, hash[10] = {0};
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &d);
        arr[d]++;
        if(d % 3 == 1)
            count_mod_1++;
        else if(d % 3 == 2)
            count_mod_2++;
        sum += d;
    }
    // printf("%d\n", sum);
    if(arr[0] == 0)
    {
        flag = 0;
        printf("NO NUMBER");
    }
       
    else
    {
        if(sum % 3 == 1)
        {
            if(count_mod_1 >= 1)
            {
                for(int i = 0; i <= 9; i++)
                {
                    if(i % 3 == 1 && arr[i])
                    {
                        arr[i]--;
                        break;
                    }
                }
            }
            else if(count_mod_2 >= 2)
            {
                int temp_count = 0;
                for(int i = 0; i <=9; i++)
                {
                    while(i % 3 == 2 && arr[i])
                    {
                        arr[i]--;
                        temp_count++;
                        if(temp_count == 2)
                            break;
                    }
                }
            }
            else
            {
                flag = 0;
                printf("NO NUMBER");
            }
        }
        if(sum % 3 == 2)
        {
            if(count_mod_2 >= 1)
            {
                for(int i = 0; i <=9; i++)
                {
                    if(i % 3 == 2 && arr[i])
                    {
                        arr[i]--;
                        break;
                    }
                }
            }
            else if(count_mod_1 >= 2)
            {
                int temp_count = 0;
                for(int i = 0; i <=9; i++)
                {
                    while(i % 3 == 1 && arr[i])
                    {
                        arr[i]--;
                        temp_count++;
                        if(temp_count == 2)
                            break;
                    }
                }
            }
            else
            {
                flag = 0;
                printf("NO NUMBER");
            }
        }

    }
    if(flag == 1)
    {
        for(int i = 9; i >= 0; i--)
            while(arr[i] > 0)
            {
                printf("%d", i);
                arr[i]--;
            }
    }
    
        

}