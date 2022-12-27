#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    int *s;
}st;



void create(struct stack *st)
{
    scanf("Enter the size of the stack: ");
    scanf("%d",&st->size);
    st->top=-1;
    st->s=(int *)malloc(st->size*sizeof(int));
}

int isempty(struct stack st)
{
    if(st.top==-1)
    printf("YES\n");
    else
    printf("NO\n");
}

int isfull(struct stack st)
{
    if(st.top==st.size-1)
    printf("YES\n");
    else
    printf("NO\n");
}

void display(struct stack st)
{
    for(int i=st.top;i>=0;i--)
    {
        printf("%d \n",st.s[i]);
    }
}


void stackpush(struct stack *st,int x)
{
    if(st->top==st->size-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        st->top++;
        st->s[st->top]=x;
    }
}

int stackpop(struct stack *st)
{
    int x;
    if(st->top==-1)
    {
        printf("Empty ");
    }
    else
    {
        x=st->s[st->top];
        st->top--;
    printf("%d ",x);
    }
}



int main()
{
    char ch;
    int x,k;
    create(&st);
    do
    {
        scanf("%c",&ch);
        
        switch(ch)
        {
            case 'i':scanf("%d",&x);
                     stackpush(&st,x);
                     break;
                     
            case 'd':scanf("%d",&k);
                     for(int i=0;i<k;i++)
                     {
                         stackpop(&st);
                     }
                     printf("\n");
                     break;
                     
            case 'e':isempty(st);
                     break;
                     
            case 'f':isfull(st);
                     break;
        }
    }while(ch!='t');
    return 0;
}

