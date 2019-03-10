#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

void slowsort(char * s, int i, int j);
void slowsort(char * s, int i, int j){
	if(i >= j){
		return;
	}
	int m = (i+j)/2;
	slowsort(s, i, m);
	slowsort(s, m+1, j);
	if(s[j] < s[m]){
		char tmp = s[j];
		s[j] = s[m];
		s[m] = tmp;
	}
	slowsort(s, i, j-1);
}

int main()
{
	char s[] = {'z', 'y', 'x', 'w', 'v', 'u', 't', 's', 'r', 'q', 'p', 'o', 'n', 'm', 'l', 'k', 'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a', '\0'};	
	int i, j, m;
	char tmp2;
	m =  sizeof(s)/sizeof(s[0]);	

	// Slow Sort (Recursive)(It is of humorous nature and not useful. --> even best case is worse than BubbleSort!)
	/*	
	 procedure slowsort(A,i,j)                            // sorts Array A[i],...,A[j]
	   if i >= j then return
	   m := ?(i+j)/2?                            
	   slowsort(A,i,m)                                    // (1.1)
	   slowsort(A,m+1,j)                                  // (1.2)
	   if A[j] < A[m] then swap A[j] and A[m]             // (1.3)
	   slowsort(A,i,j-1)                                  // (2)	
	*/
	
	slowsort(s, i, m);
	
	for(i = 0; i < m; i++) printf("%c ", s[i]);
}

