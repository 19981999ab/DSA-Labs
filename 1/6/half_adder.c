#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define limit 100000

typedef struct Node{
        int data;
        struct Node* next;
    }node;

void push(node** head,int data)
{
    node* new_node=(node*)malloc(sizeof(node));
    new_node->data=data;
    new_node->next=*head;
    *head=new_node;
}

int main()
{
    char s1[limit],s2[limit];

    node* head1=NULL;
    node* head2=NULL;
    node* head3=NULL;
    fgets(s1,limit,stdin);
    fgets(s2,limit,stdin);
    for(int i=0;s1[i]!='\n';i++)
    {
        push(&head1,s1[i]-'0');
    }
    for(int i=0;s2[i]!='\n';i++)
    {
        push(&head2,s2[i]-'0');
    }
    int addition=0;
    int carry=0;
    while(1)
    {
        if(head1!=NULL&&head2!=NULL)
        {
            addition=head1->data^head2->data^carry;
            carry=head1->data&head2->data|head2->data&carry|head1->data&carry;
            head1=head1->next;
            head2=head2->next;
        }
        else if(head1==NULL && head2!=NULL)
        {
            addition=head2->data^carry;
            carry=head2->data&carry;
            head2=head2->next;
            
        }
        else if(head2==NULL&&head1!=NULL)
        {
            addition=head1->data^carry;
            carry=head1->data&carry;
            head1=head1->next;
        }
        else if(head1==NULL&&head2==NULL)
        {
            if(carry)
                push(&head3,carry);
            break;
                
        }
        push(&head3,addition);
 
    }
    while(1)
    {
        printf("%d",head3->data);
        if(head3->next==NULL)
            break;
        head3=head3->next;
    }
    
}