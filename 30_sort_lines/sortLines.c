#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//This function is used to figure out the ordering
//of the strings in qsort.  You do not need
//to modify it.
int stringOrder(const void * vp1, const void * vp2) {
  const char * const * p1 = vp1;
  const char * const * p2 = vp2;
  return strcmp(*p1, *p2);
}
//This function will sort and print data (whose length is count).
void sortData(char ** data, size_t count) {
  qsort(data, count, sizeof(char *), stringOrder);
}

int main(int argc, char ** argv) {
  
  //WRITE YOUR CODE HERE!
	if(argc == 1){
		char * line = NULL;
		size_t sz = 0;
		char **data = NULL;
		size_t n = 0;
		while(getline(&line, &sz, stdin) != -1){
			if(*line == '\n')	break;
			n ++;
			data = realloc(data, n * sizeof(data));
			data[n-1] = line;			
			line = NULL;
		}
		free(line);
		sortData(data, n);
		for(size_t i = 0;i < n;i ++){
			printf("%s", data[i]);
			free(data[i]);
		}
		free(data);
	}
	if(argc > 1){
		char *line = NULL;
		char **data = NULL;
		size_t sz = 0;
		size_t n = 0;
		for(int i = 1;i < argc;i ++){
			FILE *f = fopen(argv[i], "r");
			if(f == NULL){
				fprintf(stderr, "Could not open the file.\n");
				free(data);free(line);
				return EXIT_FAILURE;
			}
			while(getline(&line, &sz, f) != -1){
				n ++;
				data = realloc(data, n * sizeof(data));
				data[n-1] = line;
				line = NULL;
			}
			if(fclose(f) != 0){
				fprintf(stderr,"Could not close the file.\n");
				for(int j = 0;j < n;j ++)	free(data[j]);
				free(data);
				free(line);
				return EXIT_FAILURE;
			}
			sortData(data, n);
			for(int i = 0;i < n;i ++){
				printf("%s",data[i]);
				free(data[i]);
			}
			n = 0;
		}
		free(data);
		free(line);	
	}	
	return EXIT_SUCCESS;
}
