#include <stdio.h>

int main()
{
    int n, d, flag_mod_1 = 0, flag_mod_2 = 0;
    scanf("%d", &n);
    int arr[10] = {0}, hash[10] = {0};
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &d);
        arr[d]++;
        if(d % 3 == 1)
            flag_mod_1++;
        else if(d % 3 == 2)
            flag_mod_2++;
    }
    if(arr[0] == 0)
        printf("NO NUMBER");
    else
    {
        
        for(int i = 9; i >= 0; i--)
        {
            if(arr[i] != 0)
            {
                if(i % 3 == 0)
                {
                    hash[i] = arr[i];
                    arr[i] = 0;
                }
                else if(i % 3 == 1)
                {
                    printf("i = %d mod_1 = %d mod_2 = %d\n", i, flag_mod_1, flag_mod_2);
                    flag_mod_1--;
                    if(flag_mod_1 >= 2)
                    {
                        int run_count = 0;
                        hash[i]++;
                        arr[i]--;
                        for(int j = 9; j >= 0; j--)
                        {
                            while(j % 3 == 1 && arr[j] > 0)
                            {
                                hash[j]++;
                                arr[j]--;
                                flag_mod_1--;
                                run_count++;
                                if(run_count == 2)
                                    break;
                            }
                        }
                    }
                    else if(flag_mod_2 >= 1)
                    {
                        hash[i]++;
                        arr[i]--;
                        for(int j = 9; j >= 0; j--)
                        {
                            while(j % 3 == 2 && arr[j] > 0)
                            {
                                hash[j]++;
                                arr[j]--;
                                flag_mod_2--;
                                break;
                            }
                        }
                    }     
                }
                else if(i % 3 == 2)
                {
                    flag_mod_2--;
                    printf("i = %d mod_1 = %d mod_2 = %d arr[] = %d\n", i, flag_mod_1, flag_mod_2, arr[i]);
                    if(flag_mod_2 >= 2)
                    {
                        int run_count = 0;
                        hash[i]++;
                        arr[i]--;
                        for(int j = 9; j >= 0; j--)
                        {
                            while(j % 3 == 2 && arr[j] > 0)
                            {
                                hash[j]++;
                                arr[j]--;
                                flag_mod_2--;
                                run_count++;
                                printf("j = %d mod_1 = %d mod_2 = %d arr[] = %d\n", j, flag_mod_1, flag_mod_2, arr[j]);
                                if(run_count == 2)
                                    break;
                            }
                        }
                    }
                    else if(flag_mod_1 >= 1)
                    {
                        hash[i]++;
                        arr[i]--;
                        for(int j = 9; j >= 0; j--)
                        {
                            while(j % 3 == 1 && arr[j] > 0)
                            {
                                hash[j]++;
                                arr[j]--;
                                flag_mod_1--;
                                break;
                            }
                        }
                    }     
                }
            }
        }
    }
    for(int i = 9; i >= 0; i--)
        while(hash[i] > 0)
        {
            printf("%d", i);
            hash[i]--;
        }
        

}