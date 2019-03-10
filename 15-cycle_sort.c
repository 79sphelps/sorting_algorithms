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

	//Cycle sort · 

	int writes = 0;
	int cycleStart; 
	
	//# Loop through the array to find cycles to rotate.
	for(cycleStart = 0; cycleStart < m-1; cycleStart++){
		char item = s[cycleStart];
		char swap_tmp;

		//# Find where to put the item.
		int pos = cycleStart;
		for(i = cycleStart + 1; i < m; i++){
		  if(s[i] < item){
			pos += 1;
		  }
		}
		
		//# If the item is already there, this is not a cycle.
		if(pos == cycleStart){
		  continue;
		}

		//# Otherwise, put the item there or right after any duplicates.
		while(item == s[pos]){
		  pos += 1;
		}
		swap_tmp = s[pos];
		s[pos] = item;
		item = swap_tmp;
		writes += 1;

		//# Rotate the rest of the cycle.
		while(pos != cycleStart){
		  //# Find where to put the item.
		  pos = cycleStart;
		  for(i = cycleStart + 1; i < m; i++){
			if(s[i] < item){
			  pos += 1;
			}
		  }
		  
		  //# Put the item there or right after any duplicates.
		  while(item == s[pos]){
			pos += 1;
		  }
		  swap_tmp = s[pos];
		  s[pos] = item;
		  item = swap_tmp;
		  writes += 1;
		}  
    }
    
	for(i = 0; i < m; i++) printf("%c ", s[i]);
}

