#include <stdio.h>
#include <string.h>
void swap(int arr[], int index_1, int index_2)
{
    int temp = arr[index_1];
    arr[index_1] = arr[index_2];
    arr[index_2] = temp;
}
int main()
{
    int piggy_bank, num;
    scanf("%d %d", &piggy_bank, &num);
    int left[num], right[num], count[num];

    memset(left, 0, sizeof(left));
    memset(right, 0, sizeof(right));
    memset(count, 0, sizeof(count));

    for(int i = 0; i < num; i++)
    {
        int left_in, right_in, count_in;
        scanf("%d %d %d", &left_in, &right_in, &count_in);
        left[i] = left_in;
        right[i] = right_in;
        count[i] = count_in;
        if(i)
        {
            int j = i;
            while(left[j] < left[j - 1])
            {
                swap(left, j, j - 1);
                swap(right, j, j - 1);
                swap(count, j, j - 1);
            }
        }
    }
    // for(int i = 0; i < num; i++)
    // {
    //     printf("%d ", right[i]);
    // }
    // printf("\n");
    for(int i = 0; i < piggy_bank; i++)
    {
        int temp_count = 0;
        for(int j = 0; j < piggy_bank; j++)
        {
            if(i >= left[j] && i<=right[j])
            {
                temp_count += count[j];
            }
            if(i < left[j])
                break;
        }
        printf("%d ", temp_count);
    }
}