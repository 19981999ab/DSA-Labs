#include<stdio.h>

void swap(int arr[], int index_1, int index_2)
{
    int temp = arr[index_1];
    arr[index_1] = arr[index_2];
    arr[index_2] = temp;
}
void sort(int start[], int end[], int len)
{
    for(int i = 0;i < len; i++)
    {
        int index = 0;
        for(int j = 0; j < len - i; j++)
        {
            if(end[j] > end[index])
            {
                index = j;
            }
        }
        swap(end, index, len - i - 1);
        swap(start, index, len - i - 1);
    }
}
int main()
{
    int len;
    scanf("%d", &len);
    int start[len], end[len];
    for(int i = 0; i < len; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        start[i] = a;
        end[i] = b;
    }
    sort(start, end, len);
    int count = 1, end_time = end[0];
    for(int i = 1; i < len; i++)
    {
        if(end_time < start[i])
        {
            end_time = end[i];
            count++;
        } 
    }
    for(int i = 0; i < len; i++)
    {
        printf("%d %d\n", start[i], end[i]);
    }
    printf("%d ", count);

}