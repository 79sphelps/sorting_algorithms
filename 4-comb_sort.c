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

	// Comb Sort 
	int gap = m;
	double shrink = 1.3;
	bool sorted = false;
	
	/*
	while(sorted == false){
		gap = floor(gap / shrink);
		if(gap > 1){
			sorted = false;
		} else {
			gap = 1;
			sorted = true;
		}
		
		i = 0;
		while((i + gap) < m){
			if(s[i] > s[i+gap]){
				tmp2 = s[i];
				s[i] = s[i+gap];
				s[i+gap] = tmp2;
				sorted = false;
			}
			i = i+1;
		}
	}
	*/
	
	// Using 'for' loops instead
	for(sorted = false; sorted == false; ){
		gap = floor(gap/shrink);
		if(gap > 1){
			sorted = false;
		} else {
			gap = 1;
			sorted = true;
		}
		
		for(i = 0; i+gap < m; i++){
			if(s[i] > s[i+gap]){
				tmp2 = s[i];
				s[i] = s[i+gap];
				s[i+gap] = tmp2;
				sorted = false;				
			}
		}
	}
	
	for(i = 0; i < m; i++) printf("%c ", s[i]);
}