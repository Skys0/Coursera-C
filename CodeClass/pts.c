#include<stdio.h>
#include<stdlib.h>

int main()
{
	const char * words2[] = {"A", "cat", "likes", "sleeping.", NULL};
	const char ** ptr = words2;
	while (*ptr != NULL) {
  		printf("%s ", *ptr);
  		ptr++;
	}
	printf("\n");
	return EXIT_SUCCESS;
}
