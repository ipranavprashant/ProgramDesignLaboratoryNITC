#include <stdio.h>
int main ()
{
  int n, t, i, a[1000], flag = 1,flag1=0;
  scanf ("%d%d", &n, &t);
  for (int i = 0; i < n; i++)
    {
      scanf ("%d", &a[i]);
    }
  int high = n - 1, low = 0, mid;
  while (low <= high)
    {
      mid = (high + low) / 2;
      if (t == a[mid])
	{
	  flag = 1;
	  printf ("%d\n", mid);
	  break;
	}
      else if (t < a[mid])
	{
	  high = mid - 1;
	}
      else
	{
	  low = mid + 1;
	}
      flag = 0;

    }
  if (flag == 0)
    {
      printf ("-1\n");
      printf ("-1");
      return 0;
    }
  else
    {
      for (int i = 0; i < n; i++)
	{
	  if (a[i] > t)
        {
	        flag1 = 1;
		printf ("%d ", i);
	    }
    }
    }
      if (flag1 == 0)
	{
	  printf ("-1\n");
	}
      return 0;
}
