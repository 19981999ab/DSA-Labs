#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define LIM 500000
bool isOperator(char c){
	char str[] = {'%', '/', '*', '+', '-'};
	for(int i = 0; i < 5; i++)
		if(c == str[i]) return true;
	return false;
}

bool HighPrec(char a, char b){
	if(b == '%' || b == '/' || b == '*') return false;
	return true;
}
int main(){
	char str[LIM];
	fgets(str, LIM, stdin);
	int top = -1;
	for(int i = 0; str[i] != '\n'; i++)
    {
		if(str[i] == '(') 
            str[++top] = str[i];
		else if(isOperator(str[i]))
        {
			while(isOperator(str[top]) && HighPrec(str[top], str[i]) && str[top]!='(')
                printf("%c", str[top--]);
			str[++top] = str[i];
		}
		else if(str[i] == ')')
        {
			while(str[top] != '(')
                printf("%c", str[top--]);
			top--;
		}
		else
            printf("%c", str[i]);
	}
	return 0;
}