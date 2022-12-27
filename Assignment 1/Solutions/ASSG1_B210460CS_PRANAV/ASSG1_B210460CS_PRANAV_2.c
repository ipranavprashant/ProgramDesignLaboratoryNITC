#include<stdio.h>

int main ()
{
  int n, arr[1000], rot, i = 0,temp[1000],j=0;
  printf ("Enter the no of elements of the array\n");
  scanf ("%d", &n);
  printf ("Enter the elements of the array\n");
  for (i = 0; i < n; i++)
    {
      scanf ("%d", &arr[i]);
    }
  printf ("Enter the no of rotations\n");
  scanf ("%d", &rot);
  for (int i = rot; i <n; i++)
  {
      temp[j]=arr[i];
      j++;
  }
  for(int i=0;i<rot;i++)
  {
      temp[j]=arr[i];
      j++;
  }
  for (i = 0; i < n; i++)
    {
      arr[i]=temp[i];
    }
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
  return 0;
}