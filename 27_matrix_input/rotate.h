#include<stdio.h>
#include<stdlib.h>


void rotate(char (*matrix)[10]) {
	char mat[10][10];
	for(int i = 0;i < 10;i ++)
		for(int j = 0;j < 10;j ++){
			mat[j][9 - i] = matrix[i][j];
		}

	for(int i = 0;i < 10;i ++)
		for(int j = 0;j < 10 ;j ++)
			matrix[i][j] = mat[i][j];
}
