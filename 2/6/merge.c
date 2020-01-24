#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    struct Node* next;
    struct Node* prev;
    int data;
}node;

void push(node** head,int data)
{
    node* new_node=(node*)malloc(sizeof(node));
    new_node->data=data;
    new_node->next=NULL;
    node* last=*head;
    if(*head==NULL)
    {
        new_node->prev=NULL;
        *head=new_node;
    }
    else
    {
        while(last->next!=NULL)
            last=last->next;
        last->next=new_node;
        new_node->prev=last;
    }
}
void traverse(node **head)
{
    printf("Traverse\n");
    node* current=*head;
    while(current!=NULL)
    {
        printf("%d ",current->data);
        current=current->next;
    }
}
void merge(node** head1, node** head2, node** head3)
{
    node *cur1=*head1,*cur2=*head2,*cur3=*head3;
    while(cur2!=NULL && cur1!=NULL)
    {
        while(cur1->data<=cur2->data)
            {
                push(head3,cur1->data);
                cur1=cur1->next;
                if(cur1==NULL)
                    break;
                
            }
        if(cur1==NULL)
        {
            while(cur2!=NULL)
            {
                push(head3,cur2->data);
                cur2=cur2->next;
            }
            return;
        }
        while(cur2->data<=cur1->data)
            {
                push(head3,cur2->data);
                cur2=cur2->next;
                if(cur2==NULL)
                    break;
            }
            if(cur2==NULL)
            {
                while(cur1!=NULL)
                {
                    push(head3,cur1->data);
                    cur1=cur1->next;
                }
                return;
            }
    }
}


int main()
{
    char c='a';
    int d;
    node *head1=NULL,*head2=NULL,*head3=NULL;
    while(c!='\n')
    {
        scanf("%d",&d);
        push(&head1,d);
        c=getchar();
    }
    c='a';
    while(c!='\n')
    {
        scanf("%d",&d);
        push(&head2,d);
        c=getchar();
    }
    merge(&head1,&head2,&head3);
    traverse(&head3);
}