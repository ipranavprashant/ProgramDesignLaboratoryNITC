#include <stdio.h>
int main(){
    int n;
    int k, m,x,a[1000],count=0,flag;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    m=n/k;
    int i,j;
    scanf("%d",&x);
    i = 0;
    while(i<m){
        j = 0;
        while(j<k){
            if(a[j+(k*i)]==x){
                count++;
                break;
            }
            j++;
        }
        i++;
    }
    printf("%d",count);
    return 0;
}