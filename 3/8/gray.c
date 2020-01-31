#include <stdio.h> 
#include <string.h>
void gray_code(int num)
{
    int arr[33];
    int res = num ^ (num >> 1), count=0;
    if(num == 0)
    {
        printf("0\n");
        return;
    }
    while(res > 0)
    {
        arr[count] = res % 2;
        res /= 2;
        count++;
    }
    for(int j = count - 1; j >= 0; j--)
        printf("%d", arr[j]);
    printf("\n");
    
}
int decimal(int gray[], int len)
{  
    int binary[len];
    int num;
    binary[0] = gray[0];
    num = binary[0] * (1 << (len - 1));
    for(int i = 1; i < len; i++)
    {
        binary[i] = binary[i-1] ^ gray[i];
        num += binary[i] * (1 << (len - i - 1));
    }
    return num;

}
int main()
{
    int n;
    char ch;
    int d;
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++)
    {
        scanf(" %c", &ch);
        if(ch == 'G')
        {
            scanf(" %d", &d);
            gray_code(d);
        }
        else if(ch == 'D')
        {
            char s[100], ch = getchar();
            fgets(s, 100, stdin);
            int len = strlen(s) - 1;
            int gray[len];
            for(int i = 0; i < len; i++)
                gray[i] = s[i]-'0';
            printf("%d\n", decimal(gray, len));
        }
    }
}