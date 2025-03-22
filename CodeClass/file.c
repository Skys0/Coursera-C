#include<stdio.h>
#include<stdlib.h>

int main()
{
	//broken
	FILE * f = fopen("input.in", "r");
	if (f == NULL) { /* error handling code omitted */ }
	int c;
	while ( (c=fgetc(f)) != EOF ) {
  		printf("%c",c);
	}
}
