#include <stdio.h>
#include <stdlib.h>

int main()
{
	char s[] = {'z', 'y', 'x', 'w', 'v', 'u', 't', 's', 'r', 'q', 'p', 'o', 'n', 'm', 'l', 'k', 'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a', '\0'};	
	int i, j, m;
	char tmp2;
	m =  sizeof(s)/sizeof(s[0]);	

	// Bubble Sort
	for(i = 0; i < m-1; i++) {
		for(j = 0; j < m-1-i; j++){
			if (s[j+1] < s[j]) {
				tmp2 = s[j+1];
				s[j+1] = s[j];
				s[j] = tmp2;
			}
		}
	}
	
	for(i = 0; i < m; i++) printf("%c ", s[i]);
}

/* Bubble Sort (starting from opposite end)
	for(i = m-1; i >= 0; i--){
		for(j = m-2; j >= 0; j--){
			if(s[j-1] > s[j]){
				tmp2 = s[j-1];
				s[j-1] = s[j];
				s[j] = tmp2;
			}
		}
	}
*/
