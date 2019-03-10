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
	//Pigeonhole sort ·
	// Good Resource: http://www.ccodechamp.com/c-program-for-pigeonhole-sort-algorithm-c-code-champ/
	 
    //#define MAX 11
    int min, max;

    min = s[0];
    max = s[0];
    for (i = 1; i < m; i++)
    {
        if (s[i] < min)
        {
            min = s[i];
        }
        if (s[i] > max)
        {
            max = s[i];
        }
    }	
	
    int size, count = 0;
    int *current;
    current = s;
    size = max - min + 1;
    int holes[size];
    for (i = 0; i < size; i++)
    {
        holes[i] = 0;
    }
    for (i = 0; i < size; i++, current++)
    {
        holes[*current-min] += 1;
    }
    for (count = 0, current = &s[0]; count < size; count++)
    {
        while (holes[count]-- > 0)
        {
            *current++ = count + min;
        }
    }	
    
	for(i = 0; i < m; i++) printf("%d\t", s[i]);
}

