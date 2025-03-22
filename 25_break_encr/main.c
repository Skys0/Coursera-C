#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define eps 1e-7


void input(FILE * f,char *filename, int times[]){
	int c;
	while((c = fgetc(f)) != EOF){
		if(c >= 'a' && c <= 'z'){
			times[tolower(c) - 'a'] ++;
		}
	}
	return;
}


int Cal_Pro(int times[]){
	int pos = 0,max = times[0];
	for(int i = 0;i < 26;i ++){
		if(max < times[i]){
			max = times[i];
			pos = i;
		}
	}
	return pos;
}

int main(int argc,char *argv[])
{	
	if (argc != 2){
		fprintf(stderr, "Usage: ./breaker inputFileName\n");
		return EXIT_FAILURE;
	}
	FILE * f = fopen(argv[1], "r");
	if (f == NULL){
		fprintf(stderr, "Could not open file.\n");
		return EXIT_FAILURE;
	}

	int times[26] = {0};
	input(f,argv[1], times);
	
	int sign;
	sign = Cal_Pro(times);
	if(sign == -1){
		printf("Can not Find the E");
		return EXIT_FAILURE;
	}
	else{
		if(sign < 4)	printf("%d\n",26 - (4 -  sign));
		else if(sign == 4)	printf("0\n");
		else if(sign > 4)	printf("%d\n", sign - 4);
	}

	return EXIT_SUCCESS;
}
