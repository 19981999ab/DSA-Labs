#include<stdio.h>
#define MAX_LIMIT 100000
int main()

{
char s[MAX_LIMIT];
fgets(s,MAX_LIMIT,stdin);
puts(s);
int arr[100]={2,3};
for(int i=0;i<100;i++)
	printf("%d",arr[i]);
return 0;

}

