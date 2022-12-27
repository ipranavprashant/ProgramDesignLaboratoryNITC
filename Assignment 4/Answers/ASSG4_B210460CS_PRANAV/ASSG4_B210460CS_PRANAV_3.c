#include<stdio.h>
int main()
{
    int n,k,m;
    scanf("%d%d",&n,&k);
    m=n/k;
    float height[m][k];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<k;j++)
        {
        scanf("%f",&height[i][j]);
        }
    }

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<k;j++)
        {
            int l=j-1;
            float key=height[i][j];
            while(l>-1 && height[i][l]>key)
            {
                height[i][l+1]=height[i][l];
                l--;
            }
            height[i][l+1]=key;
        }
    }
    for(int i=0;i<m;i++)
    {
            printf("%0.2f ",height[i][k-1]);
    }
    printf("\n");

    return 0;
}