#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int front;
    int rear;
    int *Q;
};


void create(struct queue *q)
{
    scanf("%d",&q->size);
    q->Q=(int *)malloc(q->size*sizeof(int));
    q->front=-1;
    q->rear=-1;
}

void isfull(struct queue *q)
{
  if((q->rear+1)%q->size==q->front)
  printf("YES\n");
  else
  printf("NO\n");
}

void isempty(struct queue *q)
{
  if (q->front == q->rear)
  printf("YES\n");
  else
  printf("NO\n");
}


void enqueue(struct queue *q,int x)
{
    if((q->rear+1)%q->size==q->front)
    {
        printf("Full\n");
    }
    else
    {
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}

int dequeue(struct queue *q)
{
    int x=-1;
    if(q->front==q->rear)
    {
        printf("Empty ");
    }
    else
    {
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
        printf("%d ",x);
    }
}

void display(struct queue *q)
{
    for(int i=q->front+1;i<=q->rear;i++)
    {
        printf("%d ",q->Q[i]);
    }
}


int main()
{
    struct queue q;
    char ch;
    int x,k;
    create(&q);
    do
    {
        scanf("%c",&ch);
        
        switch(ch)
        {
            case 'i':scanf("%d",&x);
                     enqueue(&q,x);
                     break;
                     
            case 'd':scanf("%d",&k);
                     for(int i=0;i<k;i++)
                     {
                         dequeue(&q);
                     }
                     printf("\n");
                     break;
                     
            case 'e':isempty(&q);
                     break;
                     
            case 'f':isfull(&q);
                     break;
        }
    }while(ch!='t');
    return 0;
}





