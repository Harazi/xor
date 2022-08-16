#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "encrypt.h"


int main(int argc, char **argv)
{
  if (argc < 2) {
    fprintf(stderr, "there is no key passed as an argument\n");
    return 1;
  }

  char *key = argv[1];
  size_t keyLength = strlen(key);

  char *encrypted = calloc(sizeof(char), 1);
  size_t encryptedLength = 0;

  char *line = NULL;
  size_t lineBuffer = 0;
  ssize_t lineLength = 0;

  while ((lineLength = getline(&line, &lineBuffer, stdin)) != -1)
  {
    char *encryptedLine = encrypt(line, key, lineLength, keyLength);
    encryptedLength += lineLength + 1;

    char *p = realloc(encrypted, encryptedLength);
    if (!p)
    {
      fprintf(stderr, "Failed to realloc: %s\n", strerror(errno));
      exit(EXIT_FAILURE);
    }
    encrypted = p;

    strncat(encrypted, encryptedLine, lineLength);
    free(encryptedLine);
  }

  free(line);
  printf("%s", encrypted);
  free(encrypted);
  return 0;
}
