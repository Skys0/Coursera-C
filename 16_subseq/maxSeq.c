#include<stdio.h>
#include<stdlib.h>

size_t maxSeq(int * array, size_t n){
	if(n == 0)		return 0;
	if(n == 1)		return 1;
	int t = 1;
	int ans = 1;
	for(int i = 1;i < n;i ++){
		if(array[i] > array[i-1]){
			t ++;
			if(ans < t)		ans = t;
		}
		else
			t = 1;
	}
	return ans;
}
