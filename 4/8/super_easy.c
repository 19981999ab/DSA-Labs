#include <stdio.h>
#include<time.h>
int main()
{
	int n, m, left, right, count; 
	scanf("%d %d", &n, &m);
	int arr[n];
	while(m--)
	{
		scanf("%d %d %d", &left, &right, &count);
		arr[left] += count;
		arr[right + 1] += -count;
	}
	for(int i = 1; i <= n; i++) 
	{
		arr[i] += arr[i - 1];
		printf("%d ", arr[i - 1]);
	}
    return 0; 
}