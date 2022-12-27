#include <stdio.h>
int read_and_store(int arr[],int size);
int print(int arr[],int size);
int digit_sum(int p);
int digit_sort(int arr[],int size);
int main()
{
    int A[1000],n,i;
    char r,p,d,s,t,choice;
   
    do{
    scanf("%c",&choice);
   
    switch(choice)
    {
        case 'r':scanf("%d",&n);
                 read_and_store(A,n);
        break;
        case 'p':print(A,n);
        break;
        case 'd':scanf("%d",&i);
                 printf("%d",digit_sum(A[i]));
                 printf("\n");
        break;
        case 's':digit_sort(A,n);
        break;
        case 't':printf("-1");
                 return 0;
        break;
    }
    }while(choice!='\0');
    return 0;
}

int read_and_store(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
}

int print(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int digit_sum(int p)
{
    int sum=0;
    while(p!=0)
    {
    int r;
    r=p%10;
    p=p/10;
    sum=sum+r;
    }
    return sum;
}

int digit_sort(int arr[],int size)
{
    for(int i=1;i<size;i++)
    {
        int num=arr[i];
        int key=digit_sum(num);
       
        int j=i-1;
        while(j>-1 && digit_sum(arr[j])>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=num;
    }

}