#include<stdio.h>
int merge(int a1[1000],int b1[1000],int x,int y,int t);
int main()
{
    int m,n,a[1000],b[1000],target;
    scanf("%d%d",&m,&n);
    for(int i=0;i<m;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
    }
    scanf("%d",&target);
    merge(a,b,m,n,target);
    return 0;
    
}
int merge(int a1[],int b1[],int x,int y,int t)
{
    int i,j,k,c[1000],flag=0;
    i=j=k=0;
    while(i<x && j<y)
    { 
        if(a1[i]<b1[j])
        c[k++]=a1[i++];
        else
        c[k++]=b1[j++];
    }
    for(;i<x;i++)
    c[k++]=a1[i];
    for(;j<y;j++)
    c[k++]=b1[j];
    for(int i=0;i<x+y;i++)
     {
         if(c[i]==t)
         {
             flag=1;
         printf("%d",i);
         }
     }
     if(flag==0)
     {
         printf("-1");
     }
}