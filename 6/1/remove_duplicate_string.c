#include <stdio.h>
#include <string.h>
#define LIMIT 300000
int main()
{
    char s[LIMIT], ans[LIMIT];
    fgets(s, LIMIT, stdin);
    int len = strlen(s) - 1, top = -1, i = 0;
    while(i < len)
    {
        if(top == -1)
            s[++top] = s[i++];
        else
        {
            while(s[i] == s[top] && i < len && top >= 0)
            {
                while(s[i] == s[top] && i < len)
                    i++;
                    
                s[top--] = '\0';
            }
            s[++top] = s[i++];
        }
    }
    s[top + 1] = '\0';
    if(strlen(s) == 1)  printf("VANISHED");
    else puts(s);
}