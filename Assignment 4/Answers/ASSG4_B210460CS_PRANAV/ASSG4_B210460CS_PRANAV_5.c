#include<stdio.h>
int input(int a[],int l);
int sort(int a[],int n);
int main()
{
    char i,e,m,c,d,s,choice;
    
    int size=1000,p,k,l=0;
    int arr[size];
    int q=0;
    for(int i=0;i<size;i++)
    {
        arr[i]=0;
    }
do{
    scanf("%c",&choice);
    switch(choice)
    {
        case 'i':scanf("%d",&arr[l]);
                 l++;
        
                sort(arr,l);
        break;
        case 'e':if(l==0)
        {
            printf("-1\n");
        }
        else
        {
            printf("%d\n",arr[0]);
        if(l!=1)
        {
            int j=0;
            while(j<l-1)
            {
                arr[j]=arr[j+1];
                j++;
            }
        }
        l--;
        }
        break;

        case 'm':if(l==0)
        {
            printf("-1\n");
        }
        else
        {
            printf("%d\n",arr[0]);
        }
        break;
        case 'c':scanf("%d%d",&p,&k);
        for(int j=0;j<l;j++)
        {
            if(arr[j]==p)
            {
                arr[j]=k;
                break;
            }
        }
        sort(arr,l);
        break;

        case 'd':
        for(int i=0;i<l;i++)
        {
            printf("%d ",arr[i]);
        }
        break;

        case 's':return 0;


    }
}while(choice!='\0');
    return 0;
}

int sort(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
            int j=i-1;
            int key=a[i];
            while(j>-1 && a[j]>=key)
            {
                a[j+1]=a[j];
                j--;
            }
            a[j+1]=key;
    }
}