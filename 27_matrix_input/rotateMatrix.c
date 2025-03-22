#include<stdio.h>
#include<stdlib.h>
#include "rotate.h"

int main(int args,char *argv[])
{
	if(args != 2){
		fprintf(stderr, "Usage: ./rotateMatrix.c inputFileName\n");
		return EXIT_FAILURE;
	}
	FILE *f = fopen(argv[1], "r");
	if(f == NULL){
		fprintf(stderr, "Could not open file\n");
		return EXIT_FAILURE;
	}

	char matix[10][10];
	int c;
	int i = 0,j = 0;
	while((c = fgetc(f)) != EOF){
		if(i > 9){fclose(f);fprintf(stderr, "File contains more than 10 lines.\n");return EXIT_FAILURE;}
		if(j <= 9){
			if(c == '\n'){
				fclose(f);
				fprintf(stderr, "One line not reach 10.\n");
				return EXIT_FAILURE;
			}
			matix[i][j] = c;
			j ++;
		}
		else{
			if(c == '\n'){
				i ++;
				j = 0;
			}
			else{
				fclose(f);
				fprintf(stderr, "One line out of 10.\n");
				return EXIT_FAILURE;
			}
		}
	}

	if(i < 10){fclose(f);fprintf(stderr,"Too short Line.\n");return EXIT_FAILURE;}
	fclose(f);
	
	rotate(matix);
	
	for(int i = 0;i < 10;i ++){
		for(int j = 0;j < 10;j ++)
			printf("%c",matix[i][j]);
		printf("\n");
					
	}
	return EXIT_SUCCESS;
}
