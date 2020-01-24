#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
    int data;
    struct Node* next;
};

void push(struct Node** head,int data)
{
    struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
    struct Node* last=*head;
    new_node->data=data;
    new_node->next=NULL;
    if(*head==NULL)
    {
        *head=new_node;
        // return;
    }
    else
    {   
        while(last->next!=NULL)
            last=last->next;
    
    last->next=new_node;
    }
    // return;
}

int main()
{
    struct Node* head=NULL; 
    struct Node* last;
    int count=1;
    char c;
    
    while(c!='\n')
    {
        int d;
        scanf("%d",&d);
        push(&head,d);
        c=getchar(); 
    }

    last=head;

    do
    {
        if(last->data==last->next->data)
        {
            last->next=last->next->next;

        }
        else
        {
            last=last->next;
            count++;
        }
    }
    while(last->next!=NULL);

    printf("%d\n ",count);
    
    while(1)
    {
        printf("%d ",head->data);
        if(head->next==NULL)
            break;
        head=head->next;
    }
    
}