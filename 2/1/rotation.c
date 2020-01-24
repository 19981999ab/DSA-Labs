#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{   
    struct Node* next;
    struct Node* prev;
    int data;
}node;

void push(node** head,int data)
{
    node* new_node=malloc(sizeof(node));
    new_node->data=data;
    new_node->next=NULL;
    node* last=*head;
    if(last==NULL)
    {
        new_node->prev=NULL;
        *head=new_node;
        return;
    }
        
    while(last->next!=NULL)
    {
        last=last->next;
    }
    last->next=new_node;
    new_node->prev=last;
    return;
}

void traverse(node** head)
{
    node* current=*head;
    while(current!=NULL)
    {
        printf("%d ",current->data);
        current=current->next;
    }
        
}

void rotation(node** head,int jump)
{
    node* last=*head;
    node* current=*head;
    while(last->next!=NULL)
        last=last->next;
    int count=0;
    while(current!=NULL)
    {
        if(count==jump)
        {
            current->prev->next=NULL;
            current->prev=NULL;
            last->next=*head;
            *head=current;
            break;
        }
        current=current->next;
        count++;
    }
}
int main()
{
    node* head=NULL;
    int d,length=0;
    char c='a';
    while(c!='\n')
    {
        scanf("%d",&d);
        c=getchar();
        push(&head,d);
        length++;
    }
    
    int rot;
    char ch;
    scanf("%d %c",&rot,&ch);

    int jump;
    jump=rot%length;
    if(ch=='R')
    {
        jump=length-jump;
    }
        
    rotation(&head,jump);
    traverse(&head); 
    
}