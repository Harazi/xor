#include <stdlib.h>
#include "encrypt.h"

char *encrypt(const char *message, void *key, size_t messageLength, size_t keyLength)
{
  char *encrypted = calloc(sizeof(char), messageLength + 1); // (+ 1) for null byte
  size_t keyPointer = 0;

  for (size_t i = 0; i < messageLength; i++)
  {
    // will not encrypt the newline character
    if (message[i] == '\n') {
      encrypted[i] = message[i];
      continue;
    }

    if (keyPointer >= keyLength)
      keyPointer = 0;

    encrypted[i] = message[i] ^ *(char*)(key + keyPointer++);
  }

  return encrypted;
}
