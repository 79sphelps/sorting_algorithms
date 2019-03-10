#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main()
{
	char s[] = {'z', 'y', 'x', 'w', 'v', 'u', 't', 's', 'r', 'q', 'p', 'o', 'n', 'm', 'l', 'k', 'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a', '\0'};	
	int i, j, m;
	char tmp2;
	m =  sizeof(s)/sizeof(s[0]);	

	// Odd-even Sort
    for (i = 0; i < m; i++)
    {
         if (i & 1) // 'i' is odd
         {
             for (j = 2; j < m; j += 2)
             {     
                  if (s[j] < s[j-1]){
						tmp2 = s[j-1];
						s[j-1] = s[j];
						s[j] = tmp2;
				  }
             }
          }
          else
          {  
              for (j = 1 ; j < m ; j += 2)
              {
                  if (s[j] < s[j-1]){
						tmp2 = s[j-1];
						s[j-1] = s[j];
						s[j] = tmp2;
				  }
              } 
          }
    }	
	
	for(i = 0; i < m; i++) printf("%c ", s[i]);
}
