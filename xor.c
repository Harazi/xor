#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "encrypt.h"


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

  char *line = NULL;
  size_t lineBuffer = 0;
  ssize_t lineLength = 0;

  while ((lineLength = getline(&line, &lineBuffer, stdin)) != -1)
  {
    char *encryptedLine = encrypt(line, key, lineLength, keyLength);
    printf("%s", encryptedLine);
    free(encryptedLine);
  }

  free(line);
  return 0;
}
