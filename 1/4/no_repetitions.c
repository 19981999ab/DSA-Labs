#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char s[100];
    gets(s);
    int start_pos=0;
    int end_pos=0;
    int hash[26],MIN=0,MAX=0;
    for(int i=0;i<26;i++)
    {
        hash[i]=-1;
    }
    while(end_pos<=strlen(s))
    {
        if(hash[s[end_pos]-'a']>=start_pos||end_pos==strlen(s))
        {
            printf("\n%d %d",start_pos,end_pos-1);
            if(MAX-MIN<end_pos-start_pos)
            {
                MAX=end_pos-1;
                MIN=start_pos;
            }
            start_pos=hash[s[end_pos]-'a']+1;
        }

        hash[s[end_pos]-'a']=end_pos;

        end_pos++;
    }
    printf("\n%d\n",MAX-MIN+1);
    for(int i=MIN;i<=MAX;i++)
        printf("%c",s[i]);
}