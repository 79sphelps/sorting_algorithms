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

	// Quick Sort
	/* Algorithm
	algorithm quicksort(A, lo, hi) is
		if lo < hi then
			p := partition(A, lo, hi)
			quicksort(A, lo, p – 1)
			quicksort(A, p + 1, hi)

	algorithm partition(A, lo, hi) is
		pivot := A[hi]
		i := lo     // place for swapping
		for j := lo to hi – 1 do
			if A[j] = pivot then
				swap A[i] with A[j]           
				i := i + 1
		swap A[i] with A[hi]
		return i
	*/
	
	// Non-recursive Quick Sort (no fail version) (http://alienryderflex.com/quicksort/)
	#define  MAX_LEVELS  300

	int  piv, beg[MAX_LEVELS], end[MAX_LEVELS], L, R, swap;
	i = 0;
	beg[0] = 0; 
	end[0] = m;
	while (i >= 0) {
		 L = beg[i]; 
		 R = end[i] - 1;
		 if (L < R) {
			   piv = s[L];
			   while (L < R) {
					 while (s[R] >= piv && L < R){
						 R--;
					 }		
					 if (L < R){ 
						 s[L++] = s[R];
					 }
					 while (s[L] <= piv && L < R){
						 L++; 
					 }
					 if (L<R){ 
						 s[R--] = s[L];
					 }
			   }
			   s[L] = piv; 
			   beg[i+1] = L+1; 
			   end[i+1] = end[i]; 
			   end[i++] = L;
			   
			   // below is added in the 'no fail' version but abscent, otherwise
			   if (end[i] - beg[i] > end[i-1] - beg[i-1]) {
				 swap = beg[i]; 
				 beg[i] = beg[i-1]; 
				 beg[i-1] = swap;
				 swap = end[i]; 
				 end[i] = end[i-1]; 
				 end[i-1] = swap; 
			   }
		 } else {
		   i--; 
		 }
	}
	
	for(i = 0; i < m; i++) printf("%c ", s[i]);
}
