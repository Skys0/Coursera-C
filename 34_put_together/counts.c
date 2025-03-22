#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counts.h"


counts_t * createCounts(void) {
	counts_t * counts = malloc(sizeof(counts_t));
	counts->size = 1;
	counts->count = malloc(sizeof(one_count_t));
	counts->count[0].key = NULL;
	counts->count[0].value = 0;
	return counts;
}


void addCount(counts_t * c, const char * name) {
	int sign = 0;
	if(name == NULL){
		c->count[0].value ++;
		return;
	}
	for(int i = 1;i < c->size;i ++){
		if(strcmp(name, c->count[i].key) == 0){
			c->count[i].value ++;
			sign = 1;
			break;
		}
	}
	if(sign == 0){
		c->size ++;
		c->count = realloc(c->count, c->size * sizeof(one_count_t));
		c->count[c->size - 1].key = malloc((strlen(name) + 1)* sizeof(char));
		strcpy(c->count[c->size - 1].key, name);
		c->count[c->size - 1].value = 1;	
	}
}

void printCounts(counts_t * c, FILE * outFile) {
	for(int i = 1;i < c->size;i ++){
		fprintf(outFile, "%s: %ld\n",c->count[i].key, c->count[i].value);
	}
	if(c->count[0].value != 0)
		fprintf(outFile, "<unknown>: %ld\n",c->count[0].value);
}

void freeCounts(counts_t * c) {
	for(int i = 0;i < c->size;i ++){
		free(c->count[i].key);
	}
	free(c->count);
	free(c);
}
