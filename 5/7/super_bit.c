#include <stdio.h>

void printbits(int num, int len)
{
    int arr[len];
    for(int i = 0; i < len; i++) arr[i] = num % 2, num = num / 2;
    for(int i = len - 1; i >= 0; i--) printf("%d", arr[i]);
    printf("\n");
}
int main()
{
    int len, num;
    scanf("%d %d", &len, &num);
    for(int i = 0; i < (1 << len); i++)
        if((i & num) == num) 
            // printf("%d %d %d\n", i, num, i & num);
            printbits(i, len);

}