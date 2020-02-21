#include<stdio.h>
#include<stdlib.h>
char s[5000000];

struct Node{
    char val;
    struct Node *left;
    struct Node *right;
};
typedef struct Node node;
int value(node *node)
{
    if(node -> left == NULL && node -> right == NULL)
        return (node -> val - '0');
    if(node -> val == '+')
        return value(node -> left) + value(node -> right);
    if(node -> val == '-')
        return value(node -> left) - value(node -> right);
    if(node -> val == '*')
        return value(node -> left) * value(node -> right);
    if(node -> val == '/')
        return value(node -> left) / value(node -> right);
}
void infix(node* node)
{
    int flag = 0;
    if(node -> left != NULL && node -> right != NULL) printf("("), flag = 1;
    if(node -> left != NULL) infix(node->left);
    printf("%c", node -> val);
    if(node -> right != NULL) infix(node -> right);
    if(flag)
        printf(")");
}
node *stack[5000000];
int top = -1;
int main()
{ 
    scanf("%s", s);
    int i = 0;
    while(s[i] != '\0')
    {
        node *head = malloc(sizeof(node));
        head -> val = s[i];
        if(s[i] >= '0' && s[i] <= '9')
        {
            head -> left = NULL;
            head -> right = NULL;
        }
        else
        {
            head -> right = stack[top--];
            head -> left = stack[top--];
        }
        stack[++top] = head;
        i++;
    }
    node *head = stack[top];
    printf("%d\n", value(head));
    infix(head);
}