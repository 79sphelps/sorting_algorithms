#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

void stoogesort(char * s, int i, int j);
void stoogesort(char * s, int i, int j){
	if(s[j] < s[i]){
		char tmp = s[j];
		s[j] = s[i];
		s[i] = tmp;
	}
	if((j - i + 1) > 2){
		int t = (j - i + 1) / 3;
		stoogesort(s, i, j-t);
		stoogesort(s, i+t, j);
		stoogesort(s, i, j-t);
	}
}

int main()
{
	char s[] = {'z', 'y', 'x', 'w', 'v', 'u', 't', 's', 'r', 'q', 'p', 'o', 'n', 'm', 'l', 'k', 'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a', '\0'};	
	int i, j, m;
	char tmp2;
	m =  sizeof(s)/sizeof(s[0]);	

	// Stooge Sort (Recursive) ( worst case performance of time complexity of O(n^log 3 / log 1.5 ) = O(n^2.7095))
	/*
	 function stoogesort(array L, i = 0, j = length(L)-1)
		 if L[j] < L[i] then
			 swap(L[i], L[j])
		 if (j - i + 1) > 2 then
			 t = (j - i + 1) / 3
			 stoogesort(L, i  , j-t)
			 stoogesort(L, i+t, j  )
			 stoogesort(L, i  , j-t)
		 return L	
	*/
	
	stoogesort(s, i, m);
	
	for(i = 0; i < m; i++) printf("%c ", s[i]);
}

