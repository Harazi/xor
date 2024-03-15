#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <openssl/sha.h>
#include "encrypt.h"

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

	char *key = argv[1];
	size_t keyLength = strlen(key);

	unsigned char hash[SHA512_DIGEST_LENGTH];
	SHA512((u_char*)key, keyLength, hash);

	const size_t BUFFERSIZE = 4096;
	char s[BUFFERSIZE];
	ssize_t lineLen;

	while ((lineLen = read(STDIN_FILENO, s, BUFFERSIZE)) != 0)
	{
		if (lineLen == -1)
			error("Error while reading from stdin");

		char *encryptedLine = encrypt(s, hash, lineLen, SHA512_DIGEST_LENGTH);

		ssize_t written = write(STDOUT_FILENO, encryptedLine, lineLen);

		if (written == -1)
			error("Error while calling write");
		if (written != lineLen) {
			fprintf(stderr, "write system call didn't write the exact amount of bytes:\nexpected %ld bytes\nwrote %ld bytes", lineLen, written);
			exit(EXIT_FAILURE);
		}

		free(encryptedLine);
	}

	return 0;
}
