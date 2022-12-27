#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
}*head=NULL;

//struct node *create_node(int data)
//{
//    struct node *t;
//    t=(struct node *)malloc(sizeof(struct node));
//    t->data=data;
//    t->next=NULL;
//    t->prev=NULL;
//    return t;
//}

struct node * list_insert_front(struct node *head,int key)
{
    struct node *ptr;
    ptr=(struct node *)malloc(sizeof(struct node));
    ptr->next=NULL;
    ptr->data=key;
    ptr->prev=NULL;
    if(head==NULL)
    {
        head=ptr;
        ptr->next=NULL;
     
    }
    else
    {
        ptr->next=head;
        head->prev=ptr;
        head=ptr;
    }
    return head;
}


struct node * list_insert_tail(struct node *head,int key)
{
    struct node *ptr;
    struct node *ptr1;
    ptr1=head;
    ptr=(struct node *)malloc(sizeof(struct node));
    ptr->next=NULL;
    ptr->data=key;
    ptr->prev=NULL;
    if(head==NULL)
    {
        head=ptr;
        ptr->next=NULL;
    }
    else
    {
        while(ptr1->next!=NULL)
            ptr1=ptr1->next;
        ptr->prev=ptr1;
        ptr1->next=ptr;
    }
    
    return head;
    }

struct node * list_delete_first(struct node *head)
{
    if(head==NULL)
    {
        printf("NULL\n");
    }
    else if(head->next==NULL)
    {
        printf("%d\n",head->data);
        struct node *q;
        q=head;
        head=head->next;
        free(q);
    }
    else
    {
    int x;
    struct node *ptr;
    ptr=head;
    x=head->data;
    head=head->next;
    head->prev=NULL;
    free(ptr);
    printf("%d\n",x);
   // return head;
    }
    return head;
}

struct node * list_delete_last(struct node *head)
{
    if(head==NULL)
    {
        printf("NULL\n");
    }
   else if(head->next==NULL)
    {
        printf("%d\n",head->data);
        struct node *q;
        q=head;
        head=head->next;
        free(q);
    }
    else
    {
    int x;
    struct node *ptr,*pt1;
    ptr=head;
    while(ptr->next!=NULL)
    {   pt1=ptr;
        ptr=ptr->next;
    }
    x=ptr->data;
        pt1->next=NULL;
        ptr=NULL;
//    tail=tail->prev;
//    free(ptr);
    printf("%d\n",x);
   // return head;
    }
    return head;
}


int list_search(struct node *head,int key)
{
    struct node *ptr=NULL;
    ptr=head;
    int index=0;
    while(ptr!=NULL)
    {
        if(key==ptr->data)
        return index;
        ptr=ptr->next;
        ++index;
    }
    return -1;
}

struct node * list_search1(struct node *head,int key)
{
    struct node *ptr=NULL;
    ptr=head;
    while(ptr!=NULL)
    {
        if(key==ptr->data)
        return ptr;
        ptr=ptr->next;
    }
    return NULL;
}

struct node * list_insert_after(struct node *head,int k,int n)
{
    if(head==0)
        printf("NULL\n");
    else
    {
    struct node *ptr1;
    int ptr2;
    struct node *ptr;
    ptr=head;
    ptr1=(struct node *)malloc(sizeof(struct node));
    int i=0;
    
    ptr2=list_search(head,n);
    
    while(i<ptr2)
    {
        ptr=ptr->next;
        i++;
    }
    ptr1->data=k;
    ptr1->prev=ptr;
    ptr1->next=ptr->next;
    ptr->next=ptr1;
    ptr1->next->prev=ptr1;
    }
    return head;
    
}

struct node * list_insert_before(struct node *head,int k,int n)
{
    struct node *ptr1;
    int ptr2;
    struct node *ptr;
    ptr=head;
    ptr1=(struct node *)malloc(sizeof(struct node));
    ptr1->data=k;
    int i=0;
    ptr2=list_search(head,n);
    if(head==NULL)
    {
        printf("NULL\n");
    }
    else if(ptr2==-1)
    {
        printf("ABSENT\n");
    }
   else if(ptr2==0)
    {
        ptr1->next=head;
        ptr1->prev=NULL;
        head->prev=ptr1;
        head=ptr1;
    }
    else
    {
    while(i<(ptr2-1))
    {
        ptr=ptr->next;
        i++;
    }
  //  ptr1->data=k;
    ptr1->prev=ptr;
    ptr1->next=ptr->next;
    ptr->next=ptr1;
    ptr1->next->prev=ptr1;
    }
    return head;
    
}
int count(struct node *p)
{
    int i=0;
    while(p)
    {
        p=p->next;
        i++;
    }
    return i;
}

struct node * list_delete(struct node *head,int k)
{
    int index;
    index=list_search(head,k);
   
    struct node * q=head;
    struct node *p;
    if(index==0)
    {
        p=head;
        head=p->next;
        printf("FIRST\n");
        free(p);
    }
//    else if(index==(count(head)
//    {
//        struct node *q;
//        q=head;
//        head=head->next;
//        free(q);
//    }
    else
    {
    for(int i=0;i<index;i++)
    {
         p=q;
         q=q->next;
    }
        
    printf("%d\n",q->next->data);
        p->next=q->next;
        q->next->prev=p;
    free(q);
    }
    return head;
}

void display(struct node *ptr)
{
    
    if(ptr==NULL)
    {
        printf("NULL\n");
    }
    else
    {
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    }
}

void printreverse(struct node *head,int k)
{
    
    struct node *ptr=head,*t;
    t=list_search1(ptr,k);
    while(ptr!=t)
    {
        ptr=ptr->next;
    }
    while(ptr!=NULL)
    {
    printf("%d ",ptr->data);
    ptr=ptr->prev;
}
}


int main()
{
    struct node *head,*tail;
    head=(struct node *)malloc(sizeof(struct node));
    head=NULL;
    char ch;
    int k,n;
    
    while(1)
    {
    scanf("%c",&ch);
    
    switch(ch)
    {
        case 'f':scanf("\n");
                 scanf(" %d",&k);
                 head=list_insert_front(head,k);
                 break;
                 
        case 't':scanf("\n");
                 scanf(" %d",&k);
                 head=list_insert_tail(head,k);
                 break;
                
        case 'i':head=list_delete_first(head);
                break;
                
        case 'l':head=list_delete_last(head);
                break;
                
                
        case 'a':scanf("\n");
                 scanf(" %d %d",&k,&n);
                 head=list_insert_after(head,k,n);
                 break;
                 
        case 'b':scanf("\n");
                 scanf(" %d %d",&k,&n);
                 head=list_insert_before(head,k,n);
                 break;
                 
        case 'p':display(head);
                 printf("\n");
                break;

        case 'd':scanf(" %d",&k);
                 head=list_delete(head,k);
                 break;
        case 'r':
            scanf(" %d",&k);
            printreverse(head,k);
            printf("\n");
            break;
        case 'e': return -1;
                
    }
    }
    return 0;
}