#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>


int main()
{
	//char s[] = {'z', 'y', 'x', 'w', 'v', 'u', 't', 's', 'r', 'q', 'p', 'o', 'n', 'm', 'l', 'k', 'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a', '\0'};	
	int s[] = {0, 1, 3, 5, 7, 9, 2, 4, 6, 8, 10};	
	int i, j, m, tmp;
	char tmp2;
	m =  sizeof(s)/sizeof(s[0]);	

	// NUMBERS ONLY 
	//Bucket sort
	int count[m];
 
	for(i=0; i < m; i++)
	{
		count[i] = 0;
	}

	for(i=0; i < m; i++)
	{
		(count[s[i]])++;
	}

	for(i=0,j=0; i < m; i++)
	{
		for(; count[i] > 0; (count[i])--)
		{
			s[j++] = i;
		}
	}	
	
	for(i = 0; i < m; i++) printf("%d ", s[i]);
}

