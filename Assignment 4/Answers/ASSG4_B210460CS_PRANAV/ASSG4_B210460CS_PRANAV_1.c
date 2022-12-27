#include<stdio.h>
#include<string.h>
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int main()
{
int n,flag;
char cr[30];
scanf("%d",&n);
int temp[n];
struct student
{
int mark;
char name[1000];
}s[n];
for(int i=0;i<n;i++)
{
    scanf("%s%d",s[i].name,&s[i].mark);
}
scanf("%s",cr);
for(int i=0;i<n;i++)
{
    if(strcmp(cr,s[i].name)==0)
    {
    flag=i;
    break;
    }
}
for(int i=0;i<n;i++)
{
    temp[i]=s[i].mark;
}

int pivot=temp[flag];
    int i = -1;
    for(int j=0;j<n;j++)
    {
        if(temp[j]<pivot)
        {
            i++;
            swap(&temp[i],&temp[j]);
        }
    }
    swap(&temp[i+1], &temp[flag]);

    printf("%d\n",pivot);


/*int pivot=s[flag].mark;
    int i = -1;
    for(int j=0;j<n;j++)
    {
        if(s[j].mark<pivot)
        {
            i++;
            swap(&s[i].mark,&s[j].mark);
        }
    }
    swap(&s[i+1].mark, &s[flag].mark);*/




for(int i=0;i<n;i++)
{
    for(int j=0;j<n;j++)
    {
        if(temp[i]==s[j].mark)
        {
            printf("%s ",s[j].name);
        }
    }
}
printf("\n");

return 0;
}