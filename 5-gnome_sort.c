#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main()
{
	char s[] = {'z', 'y', 'x', 'w', 'v', 'u', 't', 's', 'r', 'q', 'p', 'o', 'n', 'm', 'l', 'k', 'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a', '\0'};	
	int i, j, m;
	char tmp2;
	m =  sizeof(s)/sizeof(s[0]);	

	// Gnome Sort 
	int pos = 0;
	
	// Non-optimized Gnome Sort
	while(pos < m){
		if((pos == 0) || s[pos] >= s[pos-1]){
			pos = pos + 1;
		} else {
				tmp2 = s[pos];
				s[pos] = s[pos-1];
				s[pos-1] = tmp2;	
				pos = pos - 1;
		}
	}
	/*
	// Optimized Gnome Sort 
	for(pos = 1; pos < m; pos++){
		i = pos;
		while(pos > 0 && s[pos-1] > s[pos]){
				tmp2 = s[pos];
				s[pos] = s[pos-1];
				s[pos-1] = tmp2;	
				pos = pos - 1;			
		}
	}
	*/
	for(i = 0; i < m; i++) printf("%c ", s[i]);
}