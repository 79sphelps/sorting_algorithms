#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>


int main()
{
	char s[] = {'z', 'y', 'x', 'w', 'v', 'u', 't', 's', 'r', 'q', 'p', 'o', 'n', 'm', 'l', 'k', 'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a', '\0'};	
	//int s[] = {0, 1, 3, 5, 7, 9, 2, 4, 6, 8, 10};	
	int i, j, m, tmp;
	char tmp2;
	m =  sizeof(s)/sizeof(s[0]);	

	
	//Radix sort  --> see the radix_sort.cpp and the radix_sort2.c file
	// http://austingwalters.com/radix-sort-in-c/
	// http://scanftree.com/programs/c/c-program-to-implement-radix-sort/
	
 	// Base 10 is used
	char semiSorted[m];
	int significantDigit = 1;
	//int largestNum = findLargestNum(array, size);
	int largestNum = -1;
	
	for(i = 0; i < m; i++){
	if(s[i] > largestNum)
	  largestNum = s[i];
	}  
	
	// Loop until we reach the largest significant digit
	while (largestNum / significantDigit > 0){
		//int bucket[10] = { 0 };
		char bucket[10] = { 0 };
		
		// Counts the number of "keys" or digits that will go into each bucket
		for (i = 0; i < m; i++)
		  bucket[(s[i] / significantDigit) % 10]++;
		
		
		// Add the count of the previous buckets,
		// Acquires the indexes after the end of each bucket location in the array
		// Works similar to the count sort algorithm
		 
		for (i = 1; i < 10; i++)
		  bucket[i] += bucket[i - 1];
		
		// Use the bucket to fill a "semiSorted" array
		for (i = m - 1; i >= 0; i--)
		  semiSorted[--bucket[(s[i] / significantDigit) % 10]] = s[i];
		
		for (i = 0; i < m; i++)
		  s[i] = semiSorted[i];
		
		// Move to next significant digit
		significantDigit *= 10;	
	}
	for(i=0; i<m; i++) printf("%c ", s[i]);
    
	//for(i = 0; i < m; i++) printf("%d\t", s[i]);
}

