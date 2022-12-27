#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*front=NULL,*rear=NULL;


int isempty()
{
    if(front==NULL)
    printf("YES\n");
    else
    printf("NO\n");
}


void enqueue(int x)
{
    struct node *t;
    t=(struct node *)malloc(sizeof(struct node));
    if(t==NULL)
    printf("FULL\n");
    else
    {
        t->data=x;
        t->next=NULL;
        if(front==NULL)
        front=rear=t;
        else
        {
            rear->next=t;
            rear=t;
        }
    }
}

void dequeue()
{
    int x=-1;
    struct node *t;
    
    if(front==NULL)
    printf("Empty ");
    else
    {
        x=front->data;
        t=front;
        front=front->next;
        free(t);
        printf("%d ",x);
    }
}


int main()
{
    char ch;
    int x,k;
    do
    {
        scanf("%c",&ch);
        
        switch(ch)
        {
            case 'i':scanf("%d",&x);
                     enqueue(x);
                     break;
                     
            case 'd':scanf("%d",&k);
                     for(int i=0;i<k;i++)
                     {
                         dequeue();
                     }
                     printf("\n");
                     break;
                     
            case 'e':isempty();
                     break;
        }
    }while(ch!='t');
    return 0;
}


