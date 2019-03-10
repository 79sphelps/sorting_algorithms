#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>


int main()
{
	char s[] = {'z', 'y', 'x', 'w', 'v', 'u', 't', 's', 'r', 'q', 'p', 'o', 'n', 'm', 'l', 'k', 'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a', '\0'};	
	int i, j, m, tmp;
	char tmp2;
	m =  sizeof(s)/sizeof(s[0]);	

	// Shell Sort
	// https://rosettacode.org/wiki/Sorting_algorithms/Shell_sort#C
    int h, t;
    for (h = m; h /= 2;) {
        for (i = h; i < m; i++) {
            t = s[i];
            for (j = i; j >= h && t < s[j - h]; j -= h) {
                s[j] = s[j - h];
            }
            s[j] = t;
        }
    }
	
	for(i = 0; i < m; i++) printf("%c ", s[i]);
}

