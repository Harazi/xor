#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "encrypt.h"

char *message = "This is a secret message.";

int main(void)
{
  char *key = "69";

  char *sec = encrypt(message, key, strlen(message), 2);
  char *dec = encrypt(sec, key, strlen(message), 2);

  // for (size_t i = 0; i < strlen(message); i++)
  //   printf("%d %d\n", message[i], sec[i]);

  printf("Original: %s\n", message);
  printf("Encrypted: %s\n", sec);
  printf("Decrypted: %s\n", dec);
}
