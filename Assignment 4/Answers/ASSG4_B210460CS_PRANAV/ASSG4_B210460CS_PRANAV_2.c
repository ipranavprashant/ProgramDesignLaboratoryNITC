#include<stdio.h>
#include<math.h>
#include<string.h>
int maxheap(int a[],int start,int end);
int heapsort(int a[],int size);
int maxheapify(int a[],int f,int size);
int count=0;
int main()
{
    int m;
    scanf("%d",&m);
    int arr[m];
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&arr[i]);
    }
    maxheap(arr,0,m);
    heapsort(arr,m);
    for(int i=1;i<=m;i++)
    {
        printf("%d ",arr[i]);
    }

    printf("\n");
    printf("%d",count);
    printf("\n");
    return 0;
}

int heapsort(int a[], int size)
{
	int temp;
	for(int i = size; i>=2; i--)
	{
		temp = a[1];
		a[1] = a[i];
		a[i] = temp;
		maxheapify(a, 1, i-1);
	}
}

int maxheap(int a[], int start, int end)
{
	for(int i = end/2; i>start; i--)
	{
		maxheapify(a, i, end);
	}
}


int maxheapify(int a[], int f, int size)
{
	int max = f, l = f*2, r = f*2 +1, temp;
	if(l<=size && a[l]>a[max])
	{
		max = l;
	}
    if(l<=size)
    {
        count++;
    }	
    if(r<=size && a[r]>a[max])
	{
		max = r;
	}
    if(r<=size)
    {
        count++;
    }
	if(f!=max)
	{
		temp = a[f];
		a[f] = a[max];
		a[max] = temp;
		maxheapify(a, max, size);
	}
}




