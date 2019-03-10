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

	//Bead sort (Gravity Sort)
	int max, sum;
	unsigned char* beads;

	for (i = 1, max = s[0]; i < m; ++i)
		if (s[i] > max)
			max = s[i];

	beads = (unsigned char*)calloc(1, max * m);

	for (i = 0; i < m; ++i)
		for (j = 0; j < s[i]; ++j)
			beads[i * max + j] = 1;

	for (j = 0; j < max; ++j)
	{
		for (sum = i = 0; i < m; ++i)
		{
			sum += beads[i * max + j];
			beads[i * max + j] = 0;
		}

		for (i = m - sum; i < m; ++i)
			beads[i * max + j] = 1;
	}

	for (i = 0; i < m; ++i)
	{
		for (j = 0; j < max && beads[i * max + j]; ++j);
		s[i] = j;
	}

	free(beads);
	
	for(i = 0; i < m; i++) printf("%c ", s[i]);
}

