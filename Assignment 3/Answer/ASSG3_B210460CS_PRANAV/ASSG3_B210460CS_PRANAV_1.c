#include <stdio.h>
float insertionsort(float arr[],int size);

int main()
{
    float a[1000],temp[1000];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
    scanf("%f",&a[i]);
    }
    for(int i=0;i<n;i++)
    {
        temp[i]=a[i];
    }
    insertionsort(temp,n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i]==temp[j])
            printf("%d ",j);
        }
    }
    printf("\n");
    return 0;
}
float insertionsort(float arr[],int size)
{
    int count[1000];
    for(int i=1;i<size;i++)
    {
        int j=i-1;
        float key=arr[i];
        while(j>-1 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

        
