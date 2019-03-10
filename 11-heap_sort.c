#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

//void heapsort(char a[], int length);
void buildheap(char a[], int length);
void satisfyheap(char a[], int i, int heapsize);


void heapsort(char a[], int length){
  buildheap(a, length);
  int heapsize, i, temp;
  heapsize = length - 1;
  for( i=heapsize; i >= 0; i--)
  {
    temp = a[0];
    a[0] = a[heapsize];
    a[heapsize] = temp;
    heapsize--;
    satisfyheap(a, 0, heapsize);
  }
}

void buildheap(char a[], int length){
  int i, heapsize;
  heapsize = length - 1;
  for( i=(length/2); i >= 0; i--)
  {
    satisfyheap(a, i, heapsize);
  } 	
}

void satisfyheap(char a[], int i, int heapsize){
  int l, r, largest, temp;
  l = 2*i;
  r = 2*i + 1;
  if(l <= heapsize && a[l] > a[i])
  {
    largest = l;
  }
  else
  {
    largest = i;
  }
  if( r <= heapsize && a[r] > a[largest])
  {
    largest = r;
  }
  if(largest != i)
  {
    temp = a[i];
    a[i] = a[largest];
    a[largest] = temp;
    satisfyheap(a, largest, heapsize);
  }	
}

int main()
{
	char s[] = {'z', 'y', 'x', 'w', 'v', 'u', 't', 's', 'r', 'q', 'p', 'o', 'n', 'm', 'l', 'k', 'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a', '\0'};	
	int i, j, m;
	char tmp2;
	m =  sizeof(s)/sizeof(s[0]);	

	// Heap Sort 

	//buildheap(s, m);
	int heapsize;
	heapsize = m - 1;
	for(i=(m/2); i >= 0; i--)
	{
		satisfyheap(s, i, heapsize);
	} 
	
	int temp;
	heapsize = m - 1;
	for(i=heapsize; i >= 0; i--)
	{
		temp = s[0];
		s[0] = s[heapsize];
		s[heapsize] = temp;
		heapsize--;
		satisfyheap(s, 0, heapsize);
	}	
	
	for(i = 0; i < m; i++) printf("%c ", s[i]);
}

