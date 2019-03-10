#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// Java Implementation: https://github.com/phishman3579/java-algorithms-implementation/blob/master/src/com/jwetherell/algorithms/sorts/AmericanFlagSort.java

//int max_value(int * a_list);

int get_radix_val(int x, int digit, int radix){
	int temp = (int)pow((double) radix, digit);
	int temp2 = floor(x / temp);
	int result = (int)(temp2) % radix;
	return result;
}

/*
	def get_radix_val(x, digit, radix):
		return int(floor(x / radix**digit)) % radix
*/

int * compute_offsets(int * a_list, int start, int end, int digit, int radix){
	int counts[end];
	int i;
	for(i = 0; i < end; i++) counts[i] = i;
	for(i = start; i < end; i++){
		int val = get_radix_val(a_list[i], digit, radix);
		counts[val] += 1;
	}
	static int offsets[10];
	for(i = 0; i < end; i++) offsets[i] = i;
	int sum = 0;
	for(i = 0; i < 10; i++){
		offsets[i] = sum;
		sum += counts[i];
	}
	//for(i = 0; i < (sizeof(counts)/counts[0]); i++) printf("%d ", counts[i]);
	return offsets;
}

/*
	def compute_offsets(a_list, start, end, digit, radix):
		counts = [0 for _ in range(radix)]
		for i in range(start, end):
			val = get_radix_val(a_list[i], digit, radix)
			counts[val] += 1
		offsets = [0 for _ in range(radix)]
		sum = 0
		for i in range(radix):
			offsets[i] = sum
			sum += counts[i]
		return offsets
*/

void swap(int * a_list, int * offsets, int start, int end, int digit, int radix){
	printf("in swap...\n");
	printf("start: %d\n", start);
	printf("end: %d\n", end);
	printf("radix: %d\n", radix);
	
	printf("a_list (swap): \n");
	int u, v;
	for(u = 0; u < end; u++) printf("%d ", a_list[u]);
	printf("\n");
	printf("offsets (swap): \n");
	for(v = 0; v < end; v++) printf("%d ", offsets[v]);
	printf("\n");
	
	int i = start;
	int next_free[end];
	int j;
	for(j = 0; j < end; j++){
		next_free[j] = offsets[j];
	}
	
	printf("next_free (swap): \n");
	for(v = 0; v < end; v++) printf("%d ", next_free[v]);
	printf("\n");
	
	int cur_block = 0;
	
	
	printf("cur_block: %d radix-1: %d\n", cur_block, radix-1);
	
	while(cur_block < radix-1){
		printf("cur_block: %d radix-1: %d\n", cur_block, radix-1);
		
		int t = start + offsets[cur_block+1];
		printf("i: %d\n", i);
		printf("t: %d\n", t);
		if(i >= t){
			cur_block += 1;
			continue;
		}
		printf("digit: %d radix: %d\n", digit, radix);
		int radix_val = get_radix_val(a_list[i], digit, radix);
		printf("radix_val: %d\n", radix_val);
		//printf("here4b\n");
		if(radix_val == cur_block){
			i += 1;
			continue;
		}
		//printf("here4c\n");
		int swap_to = next_free[radix_val];
		//printf("here4d\n");
		int tmp = a_list[i];
		a_list[i] = a_list[swap_to];
		a_list[swap_to] = tmp;
		//printf("here4e\n");
		next_free[radix_val] += 1;
	}
	printf("here5\n");
}
/*
	def swap(a_list, offsets, start, end, digit, radix):
		i = start
		next_free = copy(offsets)
		cur_block = 0
		while cur_block < radix-1:
			if i >= start + offsets[cur_block+1]:
				cur_block += 1
				continue
			radix_val = get_radix_val(a_list[i], digit, radix)
			if radix_val == cur_block:
				i += 1
				continue
			swap_to = next_free[radix_val]
			a_list[i], a_list[swap_to] = a_list[swap_to], a_list[i]
			next_free[radix_val] += 1
*/

void american_flag_sort_helper(int * a_list, int start, int end, int digit, int radix){
	//int * temp = compute_offsets(a_list, start, end, digit, radix);
	//int offsets[end];
	//size_t dest_size = sizeof(offsets);
	//strncpy(offsets, temp, dest_size);
	
	int * offsets = compute_offsets(a_list, start, end, digit, radix);

	printf("offsets (american_flag_sort_helper): \n");
	int r;
	for(r = 0; r < end; r++) printf("%d ", offsets[r]);
	printf("\n");
	
	
	
	swap(a_list, offsets, start, end, digit, radix);
	
	printf("here2");
	
	if(digit == 0){
		return;
	}
	int i;
	for(i = 0; i < 10 - 1; i++){
		american_flag_sort_helper(a_list, offsets[i], offsets[i+1], digit-1, radix);
	}
}

/*
	def american_flag_sort_helper(a_list, start, end, digit, radix):
		offsets = compute_offsets(a_list, start, end, digit, radix)
		swap(a_list, offsets, start, end, digit, radix)
		if digit == 0:
			return
		for i in range(len(offsets)-1):
			american_flag_sort_helper(a_list, offsets[i], offsets[i+1], digit-1, radix)
*/

int max_value(int * a_list){
	int max = 0;
	int i;
	for(i = 0; i < 10; i++){
		printf("comparing '%d' with '%d'\n", a_list[i], max);
		if(a_list[i] > max){
			max = a_list[i];
		}
	}
	
	printf("returning: %d\n", max);
	return max;
}

void american_flag_sort(int * a_list, int size, int radix){
	//int x;
	//for(x = 0; x < sizeof(a_list)/a_list[0]; x++){
	//	if(typeof(x) == int) {
	//		
	//	}
	//}
	

	int max_val = max_value(a_list);
	printf("max_val: %d\n", max_val);
	
	int temp2 = log(max_val);
	int temp3 = log(radix);
	double temp = temp2/temp3;
	int max_digit = (int)(floor(temp));
	printf("max_digit: %d\n", max_digit);
	american_flag_sort_helper(a_list, 0, size, max_digit, radix);
}

/*
	def american_flag_sort(a_list, radix):
		for x in a_list:
			assert(type(x) == int)
		max_val = max(a_list)
		max_digit = int(floor(log(max_val, radix)))
		american_flag_sort_helper(a_list, 0, len(a_list), max_digit, radix)
		
*/

int main()
{
	//char s[] = {'z', 'y', 'x', 'w', 'v', 'u', 't', 's', 'r', 'q', 'p', 'o', 'n', 'm', 'l', 'k', 'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a', '\0'};	
	int s[] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
	int i, j, m, tmp;
	char tmp2;
	m =  sizeof(s)/sizeof(s[0]);	
	

	//for(j = 0; j < m; j++) printf("%d ", s[j]);	
	
	// Insertion Sort
	//int result = (int) pow((double) 2,2);
	//printf("%d", result);
	
	//printf("m: %d\n", m);
	int radix = m;
	american_flag_sort(s, m, radix);
	
	for(i = 0; i < m; i++) printf("%d ", s[i]);
}

