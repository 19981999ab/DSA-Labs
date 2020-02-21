#include <stdio.h>
#include <string.h>
#define LIMIT 300000
int main()
{
    char s[LIMIT], ans[LIMIT];
    fgets(s, LIMIT, stdin);
    int len = strlen(s) - 1, stack_pos = -1;
    for(int i = 0; i < len; i++)
    {
        if(stack_pos > -1)
        {
            while(s[i] == s[stack_pos] && i < len && stack_pos >= 0)
            {
                while(s[i] == s[stack_pos] && i < len)
                    i++;
                    
                s[stack_pos--] = '\0';
            }
            s[++stack_pos] = s[i];
        }
        else
            s[++stack_pos] = s[i];
    }
    s[stack_pos + 1] = '\0';
    if(strlen(s) == 1)  printf("VANISHED");
    else puts(s);
}