/*****Please include following header files*****/
// https://www.programmingalgorithms.com/algorithm/smooth-sort?lang=C
// string.h
/***********************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
Smooth sort is a comparison-based sorting algorithm. A variant of heap sort, it was invented 
and published by Edsger Dijkstra in 1981. Like heap sort, smooth sort is an in-place algorithm 
with an upper bound of O(n log n), but it is not a stable sort. The advantage of smooth sort is 
that it comes closer to O(n) time if the input is already sorted to some degree, whereas heap 
sort averages O(n log n) regardless of the initial sorted state.
*/

// (https://www.programmingalgorithms.com/algorithm/smooth-sort?lang=C)	
// (https://en.wikibooks.org/wiki/Algorithm_Implementation/Sorting/Smoothsort)	
		

typedef char* String;

#define IsAscending(A,B) (strcmp(A,B) <= 0)

#define UP(IA,IB) temp = IA; IA += IB + 1; IB = temp;
#define DOWN(IA,IB) temp = IB; IB = IA - IB - 1; IA = temp;

int q, r, p, b, c, r1, b1, c1;
String* A;

void Sift()
{
	int r0, r2, temp;
	String t;
	r0 = r1;
	t = A[r0];

	while (b1 >= 3)
	{
		r2 = r1 - b1 + c1;

		if (!IsAscending(A[r1 - 1], A[r2]))
		{
			r2 = r1 - 1;
			DOWN(b1, c1);
		}

		if (IsAscending(A[r2], t))
		{
			b1 = 1;
		}
		else
		{
			A[r1] = A[r2];
			r1 = r2;
			DOWN(b1, c1);
		}
	}

	if (r1 - r0)
		A[r1] = t;
}

void Trinkle()
{
	int p1, r2, r3, r0, temp;
	String t;
	p1 = p;
	b1 = b;
	c1 = c;
	r0 = r1;
	t = A[r0];

	while (p1 > 0)
	{
		while ((p1 & 1) == 0)
		{
			p1 >>= 1;
			UP(b1, c1)
		}

		r3 = r1 - b1;

		if ((p1 == 1) || IsAscending(A[r3], t))
		{
			p1 = 0;
		}
		else
		{
			--p1;

			if (b1 == 1)
			{
				A[r1] = A[r3];
				r1 = r3;
			}
			else
			{
				if (b1 >= 3)
				{
					r2 = r1 - b1 + c1;

					if (!IsAscending(A[r1 - 1], A[r2]))
					{
						r2 = r1 - 1;
						DOWN(b1, c1);
						p1 <<= 1;
					}
					if (IsAscending(A[r2], A[r3]))
					{
						A[r1] = A[r3]; r1 = r3;
					}
					else
					{
						A[r1] = A[r2];
						r1 = r2;
						DOWN(b1, c1);
						p1 = 0;
					}
				}
			}
		}
	}

	if (r0 - r1)
		A[r1] = t;

	Sift();
}

void SemiTrinkle() {
	String T;
	r1 = r - c;

	if (!IsAscending(A[r1], A[r]))
	{
		T = A[r];
		A[r] = A[r1];
		A[r1] = T;
		Trinkle();
	}
}

void SmoothSort(String Aarg[], const int N) {
	int temp;
	A = Aarg;
	q = 1;
	r = 0;
	p = 1;
	b = 1;
	c = 1;

	while (q < N) {
		r1 = r;
		if ((p & 7) == 3)
		{
			b1 = b;
			c1 = c;
			Sift();
			p = (p + 1) >> 2;
			UP(b, c);
			UP(b, c);
		}
		else if ((p & 3) == 1) {
			if (q + c < N)
			{
				b1 = b;
				c1 = c;
				Sift();
			}
			else
			{
				Trinkle();
			}

			DOWN(b, c);
			p <<= 1;

			while (b > 1)
			{
				DOWN(b, c);
				p <<= 1;
			}

			p++;
		}

		q++;
		r++;
	}

	r1 = r;
	Trinkle();

	while (q > 1)
	{
		--q;

		if (b == 1)
		{
			r--;
			p--;

			while ((p & 1) == 0)
			{
				p >>= 1;
				UP(b, c);
			}
		}
		else
		{
			if (b >= 3) {
				p--;
				r = r - b + c;
				if (p > 0)
					SemiTrinkle();

				DOWN(b, c);
				p = (p << 1) + 1;
				r = r + c;
				SemiTrinkle();
				DOWN(b, c);
				p = (p << 1) + 1;
			}
		}
	}
}

int main(){
	//char s[] = {'z', 'y', 'x', 'w', 'v', 'u', 't', 's', 'r', 'q', 'p', 'o', 'n', 'm', 'l', 'k', 'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a', '\0'};	
	char* s[5] = { "Hello", "World", "Computer", "VB.Net", "PHP" };

	int i, j, m;
	char tmp2;
	m =  sizeof(s)/sizeof(s[0]);
	
	SmoothSort(s, m);
	for(i = 0; i < m; i++) printf("%s ", s[i]);	
}
