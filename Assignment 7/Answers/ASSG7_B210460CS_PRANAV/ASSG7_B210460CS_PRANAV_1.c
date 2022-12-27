#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

char pranav[1000000];
int top = -1;

char
pop ()
{
  if (top == -1)
    return -1;
  else
    return pranav[top--];
}

void
push (char x)
{
  pranav[++top] = x;
}



int
xyz123 (char x)
{
  if (x == '(')
    {
      return 0;
    }
  if (x == '+' || x == '-')
    {
      return 1;
    }
  if (x == '*' || x == '/')
    {
      return 2;
    }
  return 0;
}

int
main ()
{
  char infix[100];
  char *e, x;
  int n;
  scanf ("%d", &n);
  while (n--)
    {
      scanf ("%s", infix);
      e = infix;

      while (*e != '\0')
	{
	  if (isalnum (*e))
	    printf ("%c", *e);
	  else if (*e == '(')
	    push (*e);
	  else if (*e == ')')
	    {
	      while ((x = pop ()) != '(')
		printf ("%c", x);
	    }
	  else
	    {
	      while (xyz123 (pranav[top]) >= xyz123 (*e))
		printf ("%c", pop ());
	      push (*e);
	    }
	  e++;
	}

      while (top != -1)
	{
	  printf ("%c", pop ());
	}
      printf ("\n");
    }
  return 0;
}


