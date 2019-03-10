#include <stdio.h>
#include <stdlib.h>

int main()
{
	char s[] = {'z', 'y', 'x', 'w', 'v', 'u', 't', 's', 'r', 'q', 'p', 'o', 'n', 'm', 'l', 'k', 'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a', '\0'};	
	int i, j, m, tmp;
	char tmp2;
	m =  sizeof(s)/sizeof(s[0]);	

	// Insertion Sort
	/*
	for (i = 1; i < m; i++){
		tmp = s[i];
		j = i - 1;
		while (j >= 0){
			if (tmp < s[j]){
				s[j+1] = s[j];
				s[j] = tmp;
				j = j - 1;
			} else {
				break;
			}
		}
	}
	*/
	for(i = 1; i < m; i++){
		tmp2 = s[i];
		for(j = i - 1; j >= 0; j--){
			if(tmp2 < s[j]){
				//printf("moving %c into %c spot\n", s[j], s[j+1]);
				s[j+1] = s[j];
				//printf("moving %c into %c spot\n", tmp2, s[j]);
				s[j] = tmp2;
				//for(tmp=0; tmp<m; tmp++) printf("%c ", s[tmp]);
				//printf("----\n");				
			}
		}
		//printf("=======\n");
	}	
	
	for(i = 0; i < m; i++) printf("%c ", s[i]);
}

