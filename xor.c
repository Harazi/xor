#include <stdio.h>
#include <stdlib.h>
#include "mince.h"

int main(int argc, char **argv)
{
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <encryption key>\n", argv[0]);
		return EXIT_FAILURE;
	}

	int hashSize;
	const unsigned char *hash = mince((unsigned char *)argv[1], &hashSize);

	char buf[BUFSIZ];
	size_t read;
	int hashPosition = 0;

	while ((read = fread(buf, sizeof(char), BUFSIZ, stdin))) {
		for (int i = 0; i < read; i++, hashPosition++) {
			if (hashPosition >= hashSize)
				hashPosition = 0;

			buf[i] = buf[i] ^ hash[hashPosition];
		}

		fwrite(buf, sizeof(char), read, stdout);
	}
	if (ferror(stdin)) {
		perror("stdin");
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
