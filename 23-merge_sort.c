#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define max 26

/*
void merging(char * s, char * t, int low, int mid, int high);
void merging(char * s, char * t, int low, int mid, int high){
	int l1, l2, i;
	for(l1 = low, l2 = mid+1, i = low; l1 <= mid && l2 <= high; i++){
		if(s[l1] < s[l2]){
			t[i] = s[l1++];
		} else {
			t[i] = s[l2++];
		}
	}
	
	while(l1 <= mid)
		t[i++] = s[l1++];
		
	while(l2 <= high)
		t[i++] = s[l2++];
		
	for(i = low; i <= high; i++)
		s[i] = t[i];
}

void mergesort(char * s, char * t, int low, int high){
	int mid;
	if(low < high){
		mid = (low+high)/2;
		mergesort(s, t, low, mid);
		mergesort(s, t, mid+1, high);
		merging(s, t, low, mid, high);
	} else {
		return;
	}
}

int main(){
	char t[m-1];
	mergesort(s, t, 0, m);
	return 0;
}

*/



char a[] = {'z', 'y', 'x', 'w', 'v', 'u', 't', 's', 'r', 'q', 'p', 'o', 'n', 'm', 'l', 'k', 'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a'};	
char b[26];	

void merging(int low, int mid, int high) {
   int l1, l2, i;

   for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
      if(a[l1] <= a[l2])
         b[i] = a[l1++];
      else
         b[i] = a[l2++];
   }
   
   while(l1 <= mid)    
      b[i++] = a[l1++];

   while(l2 <= high)   
      b[i++] = a[l2++];

   for(i = low; i <= high; i++)
      a[i] = b[i];
}

void mergesort(int low, int high) {
   int mid;
   
   if(low < high) {
      mid = (low + high) / 2;
      mergesort(low, mid);
      mergesort(mid+1, high);
      merging(low, mid, high);
   } else { 
      return;
   }   
}

int main() { 
	//char s[] = {'z', 'y', 'x', 'w', 'v', 'u', 't', 's', 'r', 'q', 'p', 'o', 'n', 'm', 'l', 'k', 'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a', '\0'};	
	int i, j, m, tmp;
	char tmp2;
	m =  sizeof(a)/sizeof(a[0]);	

    mergesort(0, max);

    for(i = 0; i < m; i++) printf("%c ", a[i]);   
}



