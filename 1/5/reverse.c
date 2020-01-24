#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int check_palindrome(char arr[],int start,int end);
int main()
{
    char s[100];
    gets(s);
    char palindromes[strlen(s)][2];
    int start_pos=0,end_pos=0;
    int palindromes_start=0;
    while(end_pos<=strlen(s))
    {
        if(s[end_pos]==' '|| end_pos==strlen(s))
        {
            for(int i=end_pos-1;i>=start_pos;i--)
            {
                printf("%c",s[i]);
            }
            printf(" ");
            if(check_palindrome(s,start_pos,end_pos-1))
            {
                palindromes[palindromes_start][0]=start_pos;
                palindromes[palindromes_start++][1]=end_pos;
            }
            start_pos=end_pos+1;
        }
        end_pos+=1;
    }
    for(int j=0;j<palindromes_start;j++)
    {
        printf("\n");
        for(int k=palindromes[j][0];k<palindromes[j][1];k++)
        {
            printf("%c",s[k]);
        }
    }

}
int check_palindrome(char arr[],int start,int end)
{
    while(start<=end)
    {
        if(arr[start]!=arr[end])
            return 0;
        start+=1;
        end-=1;
    }
    return 1;
}