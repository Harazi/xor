#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "encrypt.h"


int main(int argc, char **argv)
{
  char *message = "This is a sec\nret message.";

  if (argc < 2) {
    fprintf(stderr, "there is no key passed as an argument\n");
    return 1;
  }

  char *key = argv[1];
  size_t keyLength = strlen(key);

  char *sec = encrypt(message, key, strlen(message), keyLength);
  char *dec = encrypt(sec, key, strlen(message), keyLength);

  // for (size_t i = 0; i < strlen(message); i++)
  //   printf("%d %d\n", message[i], sec[i]);

  printf("Original: %s\n", message);
  printf("Encrypted: %s\n", sec);
  printf("Decrypted: %s\n", dec);
}
