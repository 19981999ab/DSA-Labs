#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>
int main()
{	
	int n;
	scanf("%d",&n);
	int arr[n], stack[n];

	for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    
	int area, i = 0, max = 0, top = -1;
	while(i < n || top != -1)
	{
		if((top == -1 || arr[i] >= arr[stack[top]]) && i < n)
			stack[++top] = i++;
		else
		{	
			if(top != 0)
                area = arr[stack[top]] * (i - stack[top - 1] - 1);
			else
				area = arr[stack[top]] * i;
			if(area > max)
                max = area;
			top--;
		}
	}
	// while(top !=  -1)
	// {
	// 	if(top != 0)
	// 		area = arr[stack[top]] * (i - stack[top - 1] - 1);
	// 	else
	// 		area = arr[stack[top]] * i;
	// 	if(area > max)
	// 		max = area;
	// 	top--;
	// }
	printf("%d\n",max);
	return 0;
}