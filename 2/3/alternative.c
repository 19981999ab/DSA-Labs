#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    struct Node* next;
    int data;
}node;

void add(node** head,int data)
{
    node* new_node=(node*)malloc(sizeof(node));
    new_node->data=data;
    new_node->next=NULL;
    if(*head==NULL)
    {
        *head=new_node;
    }
    else
    {
        node* last=*head;
        while(last->next!=NULL)
            last=last->next;
        last->next=new_node;
    }
}
void traverse(node** head)
{
    node* current=*head;
    while(current!=NULL)
    {
        printf("%d ",current->data);
        current=current->next;
    }
        
    printf("\n");
}
int remove_node(node** head,int data, node** final)
{
    node *current=*head;
    node *first=NULL,*last=NULL;
    while(current!=NULL)
    {
        if(current->data==data)
        {
            if(first==NULL)
                first=current;
            else
                last=current;
        }
        current=current->next;
    }
    current=*head;
    if(first==NULL)
        return 0;
    else
    {
        while(current!=NULL)
        {
            if(current!=first&&current!=last)
                add(final,current->data);
            current=current->next;
        }
        return 1;
    }
}
int main()
{
    int t;
    node* head=NULL;
    scanf("%d",&t);
    char s[20];
    int data,pos;
    while(t--)
    {
        scanf("%s",&s);
        if(s[0]=='a')
        {
            scanf("%d",&data);
            add(&head,data);
            traverse(&head);
        }
        else if(s[2]=='m')
        {
            int status;
            node *final=NULL;
            scanf("%d",&data);
            status=remove_node(&head,data,&final);
            head=final;
            if(status)
                traverse(&head);
            else
                printf("ELEMENT NOT FOUND\n");
        }
        
    }

}