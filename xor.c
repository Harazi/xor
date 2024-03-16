#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include "mince.h"

void error(char *msg)
{
	fprintf(stderr, "%s: %s\n", msg, strerror(errno));
	exit(EXIT_FAILURE);
}

int main(int argc, char **argv)
{
	if (argc < 2) {
		fprintf(stderr, "Usage: %s <encryption key>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if (argc > 2) {
		fprintf(stderr, "Too many arguments!\n");
		exit(EXIT_FAILURE);
	}

	int hashSize;
	const unsigned char *hash = mince((unsigned char *)argv[1], &hashSize);

	const size_t BUFFERSIZE = 4096;
	char s[BUFFERSIZE];
	ssize_t lineLen;
	int keyPointer = 0;

	while ((lineLen = read(STDIN_FILENO, s, BUFFERSIZE)) != 0)
	{
		if (lineLen == -1)
			error("Error while reading from stdin");

		for (int i = 0; i < lineLen; i++, keyPointer++)
		{
			if (keyPointer >= hashSize)
				keyPointer = 0;

			s[i] = s[i] ^ hash[keyPointer];
		}

		ssize_t written = write(STDOUT_FILENO, s, lineLen);

		if (written == -1)
			error("Error while calling write");
		if (written != lineLen) {
			fprintf(stderr, "write system call didn't write the exact amount of bytes:\nexpected %ld bytes\nwrote %ld bytes", lineLen, written);
			exit(EXIT_FAILURE);
		}
	}

	return 0;
}
