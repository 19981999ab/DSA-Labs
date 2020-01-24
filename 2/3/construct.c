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
    node* last=*head;
    if(*head==NULL)
    {
        *head=new_node;
    }
    else
    {
        while(last->next!=NULL)
            last=last->next;
        last->next=new_node;
    }
}

void reverse(node** head)
{
    node *next=NULL,*prev=NULL,*current=*head;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    *head=prev;
}

void insert(node**head, int data, int pos)
{
    node* current=*head;
    node* new_node=(node*)malloc(sizeof(node));
    new_node->data=data;
    if(pos==1)
    {
        new_node->next=*head;
        *head=new_node;
    }
    else
    {
        while(pos!=2)
        {
            current=current->next;
            pos--;
        }
        new_node->next=current->next;
        current->next=new_node;
    }
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
void fetch(node **head,int pos)
{
    node *current = *head;
    while(pos!=1)
    {
        current = current->next;
        pos--;
    }
    printf("%d\n",current->data);
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
        else if(s[0]=='f')
        {
            scanf("%d",&pos);
            fetch(&head,pos);
        }
        else if(s[2]=='v')
        {
            reverse(&head);
            traverse(&head);
        }
        
        else if(s[2]=='m')
        {
            int status;
            node *final=NULL;
            scanf("%d",&data);
            status=remove_node(&head,data,&final);
            if(status)
            {
                head=final;
                traverse(&head);
            }
            else
            {
                printf("ELEMENT NOT FOUND\n");
            }
                
        }
        else if(s[0]=='i')
        {
            scanf("%d %d",&data,&pos);
            insert(&head,data,pos);
            traverse(&head);
        }
        
    }

}