#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int is_sorted(char * a, int n);
	
// Returns 1 if sorted; 0, otherwise
int is_sorted(char *a, int n){
    while (--n >= 1)
    {
        if (a[n] < a[n - 1])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
	//char s[] = {'z', 'y', 'x', 'w', 'v', 'u', 't', 's', 'r', 'q', 'p', 'o', 'n', 'm', 'l', 'k', 'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a', '\0'};	
	char s[] = {'z', 'y', 'x', 'w'};
	int i, j, m;
	char tmp2;
	m =  sizeof(s)/sizeof(s[0]);	

	// Bogo Sort, bogosort (also permutation sort, stupid sort, slowsort, shotgun sort or monkey sort) 
	// --> is a highly ineffective sorting algorithm based on the generate and test paradigm. 
	
	while (!is_sorted(s, m)){
		// shuffling procedure
		int t, temp;

		for (i = 0;i < m;i++)
		{
			t = s[i];
			temp = rand() % m;    // Shuffles the given array using Random function
			s[i] = s[temp];
			s[temp] = t;
		}
	}
	
	for(i = 0; i < m; i++) printf("%c ", s[i]);
}

