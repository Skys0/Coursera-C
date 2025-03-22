#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"
#include "counts.h"
#include "outname.h"

counts_t * countFile(const char * filename, kvarray_t * kvPairs) {
  	FILE *f = fopen(filename, "r");
	if(f == NULL){
		fprintf(stderr, "Could not open the file.");
		exit(EXIT_FAILURE);
	}
	char *Line = NULL;
	size_t sz = 0;
	counts_t * c = createCounts();

	while(getline(&Line, &sz, f) != -1){
		Line[strcspn(Line, "\n")] = '\0';
		char * lookValue = lookupValue(kvPairs, Line);
		
		addCount(c, lookValue);
	}
	free(Line);

	if(fclose(f) != 0){
		fprintf(stderr, "Could not close the file...");
		exit(EXIT_FAILURE);
	}
	return c;
}

int main(int argc, char ** argv) {
 //read the key/value pairs from the file named by argv[1] (call the result kv)
	if(argc < 3){
		fprintf(stderr, "sage: ./count_value key-value.txt value1 ...");
		exit(EXIT_FAILURE);
	}
	kvarray_t * k = readKVs(argv[1]);

 //count from 2 to argc (call the number you count i)
	for(int i = 2;i < argc;i ++){
		char *outname = malloc((strlen(argv[i]) + 7 + 1) * sizeof(char));	
		strcpy(outname, argv[i]);
		strcat(outname, ".counts");
		FILE *f = fopen(outname, "w");
		counts_t * c = countFile(argv[i], k);		
		printCounts(c, f);
		freeCounts(c);
		free(outname);
		if(fclose(f) != 0){
			fprintf(stderr, "Could not close the file.");
			exit(EXIT_FAILURE);
		}
	}
	freeKVs(k);

    //count the values that appear in the file named by argv[i], using kv as the key/value pair
    //   (call this result c)

    //compute the output file name from argv[i] (call this outName)


    //open the file named by outName (call that f)

    //print the counts from c into the FILE f

    //close f

    //free the memory for outName and c



 //free the memory for kv

  return EXIT_SUCCESS;
}
