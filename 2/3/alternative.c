#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node{
    int data;
    struct Node *next;
}node;
node *create(int a)
{
    node *t;
    t = (node*)malloc(sizeof(node));
    t->data = a;
    t->next = NULL;
    return t;
}
int fetch_(node *head,int pos)
{
    node *temp = head;
    int cnt = 1;
    while(pos>=cnt)
    {
        if(pos==cnt)
            return temp->data;
        temp = temp->next;
        cnt++;
    }
}
node *reverse_(node *head)
{
    node *prev = NULL;
    node *curr = NULL;
    node *temp = head;
    curr = temp;
    while(curr!=NULL)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    head = prev;
    return head;
}

void append(node **head, int x)
{
    node *new_node = NULL;
    node *temp = *head;
    new_node = create(x);
    if(*head==NULL)
    {
        *head = new_node;
        return; 
    }else{
        while(temp->next!=NULL)
            temp=temp->next;   
        temp->next = new_node;
        return ;
    }

}
node *remove_node(node *head,node *node)
{
    node *temp = head;
    node *prev = NULL;
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
int remove_(node *head,int val)
{
    node *node = head;
    node *first = NULL;
    node *second = NULL;
    node *track = NULL;
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
void insert_(node **head,int val,int pos)
{
    node *temp = *head;
    node *new_node = create(val);
    int cnt=1;
    int flag=1;
    if(pos==1)
        {
            new_node->next = temp;
            *head = new_node;
            return ;
        }
    while(flag)
    {
        if(cnt==pos-1)
        {
            new_node->next = temp->next;
            temp->next = new_node;
            break;
        }
        temp=temp->next;
        cnt++;
    }
}
void display(node *head)
{
    node * t = head;
    while(t!=NULL)
    {
        printf("%d ",t->data);
        t=t->next;
    }    
}
int main(){
    int N;
    scanf("%d",&N);
    node *head=NULL;
    node *temp=NULL;
    head = temp;
    char c[1000],add[]="add",insert[]="insert",remove[]="remove",reverse[]="reverse",fetch[]="fetch";
    int X,Y;
    while(N--)
    {
        scanf("%s",c);
        if(!strcmp(c,add))
        {
            scanf("%d",&X);
            append(&head,X);
            display(head);
        }
        else if(!strcmp(c,insert))
        {
            scanf("%d %d",&X,&Y);
            insert_(&head,X,Y);
            display(head);
        }
        else if(!strcmp(c,remove))
        {   scanf("%d",&Y);
            int flag = remove_(head,Y);
            if(flag)
                display(head);
            else
                printf("NO ELEMENT");
        }
        else if(!strcmp(c,reverse))
        {
            head = reverse_(head);
            display(head);
        }
        else if(!strcmp(c,fetch))
        {
            scanf("%d",&X);
            printf("%d",fetch_(head,X));
        }
    }
}