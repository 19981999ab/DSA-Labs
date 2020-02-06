#include <stdio.h>
#include<time.h>
int a[1000005];
int main()
{
	int n, m, l, r, x; 
	scanf("%d %d", &n, &m);
	while(m--)
	{
		scanf("%d %d %d", &l, &r, &x);
		a[l] += x;
		a[r + 1] += -x;
	}
	for(int i = 1; i <= n; i++) 
	{
		a[i] += a[i - 1];
		printf("%d ", a[i - 1]);
	}
    return 0; 
}