#include<stdio.h>
#include<string.h>
#include<math.h>
#define LIMIT 1000000

int main()
{
    
    char s[LIMIT];
    fgets(s,LIMIT,stdin);
    int len_inp=strlen(s)-1;
    int start=0, end=0;
    for(float center=0;center<len_inp;center+=0.5)
    {
        int left=floor(center);
        int right=ceil(center);
        
        while(s[left]==s[right])
        {
            left--;
            right++;
        }
        right-=1;
        left+=1;
        if(right-left>end-start)
        {
            end=right;
            start=left;
        }
      
    }
    printf("%d\n",end-start+1);
    for(int i=start; i<=end; i++){
        printf("%c", s[i]);
    }

    return 0;
}