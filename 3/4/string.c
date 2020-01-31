#include <stdio.h>
#include<string.h>
#define LIMIT 50000
int main()
{
    char s[LIMIT], t[LIMIT];
    fgets(s, LIMIT, stdin);
    fgets(t, LIMIT, stdin);
    int start_s = 0, start_t = 0, count = 0, match = 0, flag = 1;
    int len_t = strlen(t) - 1;
    while(s[start_s] != '\n')
    {
        // printf("%d %d\n", start_s, start_t);
        if(s[start_s] != t[start_t] && flag == 1)
        {
            match++;
            flag = 0;
        }
        else if(s[start_s] == t[start_t])
        {
            match++;    
        }

        start_s++;
        start_t++;

        if(t[start_t] == '\n')
        {
            // printf("%d %d\n", start_s, match);
            if(match == len_t)
            {
                count++;
            }
            flag = 1;
            start_t = 0;
            match = 0;
            start_s -= len_t - 1;
        }
    }
    printf("%d ", count);
}