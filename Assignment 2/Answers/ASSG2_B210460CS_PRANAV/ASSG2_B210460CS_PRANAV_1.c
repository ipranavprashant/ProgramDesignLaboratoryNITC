#include<stdio.h>
int main()
{
    char str[1000];
    int i,count[1000]={0},n,prod=1;
    scanf("%s",str);

    for(i=0;str[i]!='\0';i++)
    {
            count[str[i]]++;
        
    }
    
    for(i=0;i<1000;i++)
    {
        if(count[i]!=0)
        {
        prod=prod*count[i];
        }
    }
    printf("%d",prod);
    return 0;
    
}
