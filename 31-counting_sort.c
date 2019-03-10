#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>


int main()
{
	//char s[] = {'z', 'y', 'x', 'w', 'v', 'u', 't', 's', 'r', 'q', 'p', 'o', 'n', 'm', 'l', 'k', 'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a', '\0'};	
	//int s[] = {0, 1, 3, 5, 7, 9, 2, 4, 6, 8, 10};	
	int i, j, m, tmp;
	//char tmp2;
	//m =  sizeof(s)/sizeof(s[0]);	

	// NUMBERS ONLY 
	// Counting Sort 
	//int i, j;	
	int n = 11;
	char A[12] = {0, 1, 3, 5, 7, 9, 2, 4, 6, 8, 10, '\0'};
	int k = 11;
	int B[15], C[100];
 
	for(i = 0; i <= k; i++)
		C[i] = 0;
 
	for(j =1; j <= n; j++)
		C[A[j]] = C[A[j]] + 1;
 
	for(i = 1; i <= k; i++)
		C[i] = C[i] + C[i-1];
 
	for(j = n; j >= 1; j--)
	{
		B[C[A[j]]] = A[j];
		C[A[j]] = C[A[j]] - 1;
	}

	for(i=1;i<=n;i++)
	{
		printf("\t");
		printf("%d",B[i]);
	}
	
	//for(i = 0; i < m; i++) printf("%d ", s[i]);
}

