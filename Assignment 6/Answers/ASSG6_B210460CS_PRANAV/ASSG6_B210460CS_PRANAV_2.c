#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*top=NULL;



int isempty()
{
    if(top==NULL)
    printf("YES\n");
    else
    printf("NO\n");
}


void stackpush(int x)
{
   struct node *ptr;
   ptr=(struct node *)malloc(sizeof(struct node));
   if(ptr==NULL)
   {
       printf("FULL\n");
   }
   else
   {
   ptr->data=x;
   ptr->next=top;
   top=ptr;
   }
}

int stackpop()
{
    int x=-1;
    if(top==NULL)
    {
        printf("Empty ");
    }
    else
    {
    struct node *ptr;
    ptr=top;
    x=ptr->data;
    top=top->next;
    free(ptr);
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
                     stackpush(x);
                     break;
                     
            case 'd':scanf("%d",&k);
                     for(int i=0;i<k;i++)
                     {
                         stackpop();
                     }
                     printf("\n");
                     break;
                     
            case 'e':isempty();
                     break;
        }
    }while(ch!='t');
    return 0;
}

