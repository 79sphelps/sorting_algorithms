// http://www.iti.fh-flensburg.de/lang/algorithmen/sortieren/networks/oemen.htm

// NOTE: The array size must be a power of 2.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>


void oddEvenMergeSort(int * s, int lo, int n){
	int i;
    if (n>1)
    {
        int m=n/2;
        oddEvenMergeSort(s, lo, m);
        oddEvenMergeSort(s, lo+m, m);     
        oddEvenMerge(s, lo, n, 1);
    }	
}

void oddEvenMerge(int * s, int lo, int n, int r)
{
    int m=r*2;
    if (m<n)
    {
        oddEvenMerge(s, lo, n, m);      // even subsequence
        oddEvenMerge(s, lo+r, n, m);    // odd subsequence
        int i;
		for (i=lo+r; i+r<lo+n; i+=m)
            compare(s, i, i+r);
    }
    else
        compare(s, lo, lo+r);
}

void compare(int * a, int i, int j)
{
    if (a[i]>a[j])
        exchange(a, i, j);
}

void exchange(int * a, int i, int j)
{
    int t=a[i];
    a[i]=a[j];
    a[j]=t;
}

int main()
{
	//NOTE: The array size must be a power of 2.
	
	//char s[] = {'z', 'y', 'x', 'w', 'v', 'u', 't', 's', 'r', 'q', 'p', 'o', 'n', 'm', 'l', 'k', 'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a', 'v', 't', 's', 'p', 'c', 'd'};	
	int s[] = {0, 1, 3, 5, 7, 9, 2, 4, 6, 8, 10, 11, 13, 15, 12, 14};	
	int i, j, m, tmp;
	char tmp2;
	m =  sizeof(s)/sizeof(s[0]);	

	// Batcher odd/even mergesort --> http://www.iti.fh-flensburg.de/lang/algorithmen/sortieren/networks/oemen.htm
	oddEvenMergeSort(s, 0, m);

	for(i = 0; i < m; i++) printf("%d\t", s[i]);
}

