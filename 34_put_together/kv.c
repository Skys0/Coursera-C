#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"


char * getKey(char * t){
	if(t == NULL || *t == '\0'){
		return NULL;
	}

	char * its = strchr(t, '=');
	if(*its == '\0'){
		return NULL;
	}

	size_t key_len = its - t;
	char * key = malloc((key_len + 1) * sizeof(char));

	strncpy(key, t, key_len);
	if(key == NULL){
		fprintf(stderr, "Please check the file.Fail to identify.");
		exit(EXIT_FAILURE);
	}
	key[key_len] = '\0';
	return key;
}

char * getValue(char * t){
	
	if(t == NULL || *t == '\0'){
		return NULL;
	}

	char * its = strchr(t, '=');
	char * end = strchr(t, '\0');

	size_t value_len = end - (its + 1) - 1;
	
	char * value = malloc((value_len + 1) * sizeof(char));

	strncpy(value, its + 1, value_len);
	if(value == NULL){
		fprintf(stderr, "Please check the file.Fail to identify.");
		exit(EXIT_FAILURE);
	}

	value[value_len] = '\0';
	return value;
}


kvarray_t * readKVs(const char * fname) {
	FILE *f = fopen(fname, "r");
	if(f == NULL){
		fprintf(stderr, "Could not open the file.");
		exit(EXIT_FAILURE);
	}

	kvarray_t * keyarray = malloc(sizeof(kvarray_t));
	if(keyarray == NULL){
		fprintf(stderr, "Memory allocation failed.");
		exit(EXIT_FAILURE);
	}
	
	keyarray->array = NULL;
	keyarray->size = 0;
	char* line = NULL;
	size_t sz = 0;
	while(getline(&line, &sz, f) != -1){
		keyarray->size ++;
		char *key = getKey(line);
		char *value = getValue(line);
		keyarray->array = realloc(keyarray->array, keyarray->size * sizeof(kvpair_t));
		keyarray->array[keyarray->size - 1].key = key;
		
		keyarray->array[keyarray->size - 1].value = value;
	}
	free(line);
	if(fclose(f) != 0){
		fprintf(stderr, "Could not close the file.");
		exit(EXIT_FAILURE);
	}
	return keyarray;
}

void freeKVs(kvarray_t * pairs) {
	for(int i = 0;i < pairs->size;i ++){
		free(pairs->array[i].key);
		free(pairs->array[i].value);
	}
	free(pairs->array);
	free(pairs);
}


void printKVs(kvarray_t * pairs) {
	for(int i = 0;i < pairs->size; i ++){
		printf("key = '%s' value = '%s'\n",pairs->array[i].key, pairs->array[i].value);
	}
}

char * lookupValue(kvarray_t * pairs, const char * key) {
	for(int i = 0;i < pairs->size;i ++){
		if(strcmp(key, pairs->array[i].key) == 0){
			return pairs->array[i].value;
		}
	}
	return NULL;
}
