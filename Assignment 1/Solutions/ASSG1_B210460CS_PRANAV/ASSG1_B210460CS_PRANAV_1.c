#include <stdio.h>
#include<math.h>

int main()
{
    int n,p,rem,k,sum=0;
    scanf("%d",&n);
    scanf("%d",&p);
    while(n!=0)
    {
    rem=n%10;
    n=n/10;
    k=pow(rem,p);
    sum=sum+k;
    }
    printf("%d",sum);
       return 0;
}
