#include<stdio.h>
#include<stdlib.h>
#include<string.h>


char * getKey(char * t){
	char * its = strchr(t, '=');
	
	size_t key_len = its - t;
	char * key = malloc((key_len + 1) * sizeof(char));

	strncpy(key, t, key_len);

	key[key_len] = '\0';
	return key;
}

int main()
{
	printf("%s\n",getKey("a=rwerioewru"));
	return EXIT_SUCCESS;
}
