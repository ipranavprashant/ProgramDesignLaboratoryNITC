#include<stdio.h>
#include<stdlib.h>

struct node
{
    char data;
    struct node *next;
};

struct node * list_insert_front(struct node *head,char key)
{
    struct node *ptr;
    ptr=(struct node *)malloc(sizeof(struct node));
    ptr->next=head;
    ptr->data=key;
    head=ptr;
    return head;
}


struct node * list_insert_tail(struct node *head,char key)
{
    if(head==NULL){
        struct node* temp = (struct node *)malloc(sizeof(struct node));
        temp->data = key;
        temp->next = NULL;
        head = temp;
        return head;
    }
    else
    {
    struct node *ptr;
    ptr=(struct node *)malloc(sizeof(struct node));
    struct node *p;
    p=head;
    
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->data=key;
    ptr->next=NULL;
    
    return head;
    }
}

struct node * list_delete_first(struct node *head)
{
    if(head==NULL)
    {
        printf("NULL\n");
    }
    else
    {
    char x;
    struct node *ptr;
    ptr=head;
    x=head->data;
    head=head->next;
    free(ptr);
    printf("%c\n",x);
    }
    return head;
}

struct node * list_delete_last(struct node *head)
{
    if(head==NULL)
    {
        printf("NULL\n");
    }
    else
    {
    char x;
    struct node *ptr,*q;
    ptr=head;
    q=head->next;
    
    while(q->next!=NULL)
    {
        q=q->next;
        ptr=ptr->next;
    }
    x=q->data;
    ptr->next=NULL;
    free(q);
    printf("%c\n",x);
    return head;
    }
    
}

void display(struct node *ptr)
{
    if(ptr==NULL)
    {
        printf("NULL");
    }
    else
    {
    while(ptr!=NULL)
    {
        printf("%c ",ptr->data);
        ptr=ptr->next;
    }
    }

    
}


int main()
{
    struct node *head;
    head=(struct node *)malloc(sizeof(struct node));
    head=NULL;
    char ch,k,n;
    
    do{
    scanf("%c",&ch);
    
    switch(ch)
    {
        case 'f':scanf("\n");
                 scanf("%c",&k);
                 head=list_insert_front(head,k);
                 break;
                 
        case 't':scanf("\n");
                 scanf("%c",&k);
                 head=list_insert_tail(head,k);
                 break;
                
        case 'i':head=list_delete_first(head);
                break;
                
        case 'l':head=list_delete_last(head);
                break;
                
        case 'p':display(head);
                 printf("\n");
                break;
                
                
        case 'e':return 0;
                
    }
    }while(ch!='\0');
    
    return 0;
}
