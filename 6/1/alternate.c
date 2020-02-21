#include <stdio.h>
#include <stdlib.h>
#define LIM 3000000

int main(){
	char A[LIM], c = getchar(), prev = '#';
	int end = -1;
	
	while(c!='\n'){
		if(c != A[end]){
			if(c != prev){
				end++;
				A[end] = c;
			}
		}
		else if(end!=-1) end--;
		prev = c;
		c = getchar();
	}
	
	if(end==-1) printf("VANISHED");
	else
		for(int i=0; i<=end; i++)
			printf("%c", A[i]);
	return 0;
}