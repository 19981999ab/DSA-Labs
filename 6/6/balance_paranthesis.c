#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char stack[50000];
int top = -1;
int main()
{ 
  char str[50000];
  scanf("%s",str);
  int len = strlen(str);
  for(int i = 0; i < len; i++)
  {
    if(str[i] == '[' || str[i] == '(' || str[i] =='{')
      stack[++top] = str[i];
    else if(top == -1 && (str[i] == ']' || str[i] == ')' || str[i] =='}')) 
    {
      printf("NO");
      return 0;
    }
    else if((str[i] == ']' && stack[top] == '[') || (str[i] == ')' && stack[top] == '(') || (str[i] == '}' && stack[top] == '{'))
      top--;
  }
  if(top == -1) printf("YES");
  else printf("NO");
  return 0; 
}