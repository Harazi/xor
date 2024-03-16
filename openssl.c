#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include "mince.h"

unsigned char *mince(const unsigned char *data, int *size)
{
	*size = SHA512_DIGEST_LENGTH;
	unsigned char *hash = malloc(*size);
	SHA512(data, strlen((char *)data), hash);
	return hash;
}
