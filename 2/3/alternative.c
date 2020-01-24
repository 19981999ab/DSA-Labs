#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node{
    int data;
    struct Node *next;
};
struct Node *create(int a)
{
    struct Node *t;
    t = (struct Node*)malloc(sizeof(struct Node));
    t->data = a;
    t->next = NULL;
    return t;
}
int fetch_(struct Node *head,int pos)
{
    struct Node *temp = head;
    int cnt = 1;
    while(pos>=cnt)
    {
        if(pos==cnt)
            return temp->data;
        temp = temp->next;
        cnt++;
    }
}
struct Node *reverse_(struct Node *head)
{
    struct Node *prev = NULL;
    struct Node *curr = NULL;
    struct Node *n = head;
    curr = n;
    while(curr!=NULL)
    {
        n = curr->next;
        curr->next = prev;
        prev = curr;
        curr = n;
    }
    head = prev;
    return head;
}
struct Node *remove_node(struct Node *head,struct Node *node)
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
void append(struct Node **head, int x)
{
    struct Node *new_node = NULL;
    struct Node *temp = *head;
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
void insert_(struct Node **head,int val,int pos)
{
    struct Node *temp = *head;
    struct Node *new_node = create(val);
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
void display(struct Node *head)
{
    struct Node * t = head;
    while(t!=NULL)
    {
        printf("%d ",t->data);
        t=t->next;
    }    
}
int main(){
    int N;
    scanf("%d",&N);
    struct Node *head=NULL;
    struct Node *temp=NULL;
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