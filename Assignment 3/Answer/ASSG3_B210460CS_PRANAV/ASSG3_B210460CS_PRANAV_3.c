#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int
main () 
{
  
char name[100][100], temp[100];
  
int i, j, n;
  
scanf ("%d", &n);
  
for (i = 0; i < n; i++)
    
scanf (" %[^\n]s", name[i]);
  
for (i = 1; i < n; i++)
    
    {
      
for (j = 1; j < n; j++)
	
	{
	  
if (strcmp (name[j - 1], name[j]) > 0)
	    
	    {
	      
strcpy (temp, name[j - 1]);
	      
strcpy (name[j - 1], name[j]);
	      
strcpy (name[j], temp);
	    
}
	
}
    
}
  
//printf ("\n");
  
for (i = 0; i < n; i++)
    
    {
      
printf ("%s\n", name[i]);
    
}
  
return 0;

}
