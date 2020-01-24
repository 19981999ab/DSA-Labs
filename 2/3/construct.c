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
        while(--pos!=1)
        {
            current=current->next;
        }
        new_node->next=current->next;
        current->next=new_node;
    }
}
node* remove_node(node *head,node *node)
{
    struct Node *temp = head;
    struct Node *prev = NULL;
    if(head==node)
    {
        head = head->next;
        return head;
    }
    while(temp->next==node)
    {
        if(temp->next == node)
        {
            temp->next = node->next;
            return head;
        }
    }
}
int remove_(struct Node *head,int val)
{
    struct Node *node = head;
    struct Node *first = NULL;
    struct Node *second = NULL;
    struct Node *track = NULL;
    while(node!=NULL)
    {
        if(node->data == val)
        {   
            if(node->data==val)
            {
                if(first)
                    second = node;
                else
                    first = node;
            }
            node = node->next;
        }
        node=node->next;
    }
    if(!first&&!second)
    {   return 0;}
    else{
        if(first==second)
            head = remove_node(head,first);
        else
        {
            head = remove_node(head,first);
            head = remove_node(head,second);
        }
        return 1;
    }

}

void fetch(node** head,int pos)
{
    node* current=*head;
    while(current!=NULL)
    {
        if(pos==1)
        {
            printf("%d\n",current->data);
        }
        current=current->next;
        pos--;
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
            scanf("%d",&data);
            remove_node(&head,data);
            traverse(&head);
        }
        else if(s[0]=='i')
        {
            scanf("%d %d",&data,&pos);
            insert(&head,data,pos);
            traverse(&head);
        }
        
    }

}