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

	// Cocktail Sort (basically Bubblesort coming from both directions)
	bool swapped;
	do{
		swapped = false;
		for(i = 0; i < m - 1; i++){
			if(s[i+1] < s[i]){
				tmp2 = s[i+1];
				s[i+1] = s[i];
				s[i] = tmp2;
				swapped = true;
			}
		}
		if(swapped == false){
			break;
		}
		swapped = false;
		for(j=m-2; j >= 0; j--){
			if(s[j+1] < s[j]){
				tmp2 = s[j+1];
				s[j+1] = s[j];
				s[j] = tmp2;
				swapped = true;
			}			
		}
	} while (swapped == true);
	
	for(i = 0; i < m; i++) printf("%c ", s[i]);
}

/* FOR LOOP Version
	bool swapped;
	for(swapped = false; swapped != true; swapped = false){
		for(i = 0; i < m - 1; i++){
			if(s[i+1] < s[i]){
				tmp2 = s[i+1];
				s[i+1] = s[i];
				s[i] = tmp2;
				swapped = true;
			}
		}
		if(swapped == false) break;
		
		for(j = m - 2; j >= 0; j--){
			if(s[j+1] < s[j]){
				tmp2 = s[j+1];
				s[j+1] = s[j];
				s[j] = tmp2;
				swapped = true;
			}
		}
	}
*/
