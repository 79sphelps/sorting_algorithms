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

	// Selection Sort
	int min;
	for(i = 0; i < m-1; i++){
		min = i;
		for(j = i+1; j < m; j++){
			if(s[j] < s[min]){
				min = j;
			}
		}
		if (min != i){
			tmp = s[i];
			s[i] = s[min];
			s[min] = tmp;		
		}	
	}
	
	for(i = 0; i < m; i++) printf("%c ", s[i]);
}

