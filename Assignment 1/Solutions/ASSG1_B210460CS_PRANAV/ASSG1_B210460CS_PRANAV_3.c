#include <stdio.h>
int main()
{
    char word[100000];
    int length,flag=0,i=0;
    scanf("%s", word);
    for(int i=0;word[i]!='\0';i++)
    {
        length++;
    }
    for(i=0;i<length;i++){
        if(word[i]>=65 && word[i]<=90){
         word[i]+=32;
     }
    }
    for(i=0; i<length;i++){
        if(word[i]!=word[length-i-1])
        {
        flag=1;
        break;
        }
    }
if(flag)
{
    printf("NO\n");
}
else
{
    printf("YES\n");
}
    return 0;
}