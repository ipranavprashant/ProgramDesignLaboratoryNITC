#include<stdio.h>
#include<stdlib.h>

struct node
{
    char data;
    struct node *next;
}*head=NULL;

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
    char x;
    struct node *ptr;
    ptr=head;
    x=head->data;
    head=head->next;
    free(ptr);
    printf("%c\n",x);
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


int list_search(struct node *head,char key)
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
}

struct node * list_insert_after(struct node *head,char k,char n)
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
    ptr1->next=ptr->next;
    ptr->next=ptr1;
    
    return head;
    
}

struct node * list_insert_before(struct node *head,char k,char n)
{
    struct node *ptr1;
    int ptr2;
    struct node *ptr;
    ptr=head;
    ptr1=(struct node *)malloc(sizeof(struct node));
    int i=0;
    
    ptr2=list_search(head,n);
    
    if(ptr2==1)
    {
      ptr1->next=head;
      head=ptr1;
    }
    else{
    while(i<(ptr2-1))
    {
        ptr=ptr->next;
        i++;
    }
    ptr1->data=k;
    ptr1->next=ptr->next;
    ptr->next=ptr1;
    }
    return head;
    
}

struct node * list_delete(struct node *head,char k)
{
    int index;
    index=list_search(head,k);

    struct node * q=head;
    struct node *p;
    if(index==0)
    {
        p=head;
        head=p->next;
         printf("%c\n",p->next->data);
         free(p);
    }
    else{
    for(int i=0;i<index-1;i++)
    {

        q=q->next;
    }
    p=q->next;
    q->next=p->next;
    printf("%c\n",p->next->data);
    free(p);
    }
    return head;

    
    
//     struct node *ptr1,*ptr2,*ptr3;
//     ptr1=head;
//     ptr2=head;
//     ptr3=head;
//    // int i=0;
//     for(int i=0;i<index-1;i++)
//     {
//       ptr1=ptr2;
//       ptr2=ptr2->next;
//     }
//     ptr1->next=ptr2->next;
//     ptr1->next=NULL;

   // printf("%d\n",index);
   // return head;


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
                 scanf(" %c",&k);
                 head=list_insert_front(head,k);
                 break;
                 
        case 't':scanf("\n");
                 scanf(" %c",&k);
                 head=list_insert_tail(head,k);
                 break;
                
        case 'i':head=list_delete_first(head);
                break;
                
        case 'l':head=list_delete_last(head);
                break;
                
                
        case 'a':scanf("\n");
                 scanf(" %c %c",&k,&n);
                 head=list_insert_after(head,k,n);
                 break;
                 
        case 'b':scanf("\n");
                 scanf(" %c %c",&k,&n);
                 head=list_insert_before(head,k,n);
                 break;
                 
        case 'p':display(head);
                 printf("\n");
                break;

        case 'd':scanf(" %c",&k);
                 head=list_delete(head,k);
                 break;                    
                 
        case 'e':return 0;
                
    }
    }while(ch!='\0');
    
    return 0;
}
