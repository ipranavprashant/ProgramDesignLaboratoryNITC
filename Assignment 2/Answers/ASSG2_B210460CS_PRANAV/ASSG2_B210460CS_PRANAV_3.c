#include<stdio.h>
int swap(int *x,int *y);
int main()
{
    int arr[1000],n,i,j,temp[1000];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        temp[i]=arr[i];
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(arr[j]<arr[j+1])
            {
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(temp[i]!=arr[1])
        {
            printf("%d ",temp[i]);
        }
        else if(arr[0]==arr[1])
        {
             printf("%d ",temp[i]);
        }
    }
    return 0;
}
    int swap(int *x,int *y)
    {
        int temp;
        temp=*x;
        *x=*y;
        *y=temp;
    }