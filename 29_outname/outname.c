#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outname.h"

char * computeOutputFileName(const char * inputName) {
	char *outFileName = malloc(strlen(inputName) + 7 + 1 * sizeof(*outFileName));
	strcpy(outFileName, inputName);
	strcat(outFileName, ".counts");
	return outFileName;
}
