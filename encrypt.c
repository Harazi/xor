#include <stdlib.h>
#include "encrypt.h"

size_t keyPointer = 0;

char *encrypt(const char *message, const void *key, size_t messageLength, size_t keyLength)
{
	char *encrypted = calloc(sizeof(char), messageLength + 1); // (+ 1) for null byte

	for (size_t i = 0; i < messageLength; i++, keyPointer++)
	{
		if (keyPointer >= keyLength)
			keyPointer = 0;

		encrypted[i] = message[i] ^ *(char*)(key + keyPointer);
	}

	return encrypted;
}
