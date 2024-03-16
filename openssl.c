#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include "mince.h"

unsigned char *mince(const unsigned char *data, int *size)
{
	unsigned char *hash = malloc(EVP_MD_get_size(EVP_get_digestbyname("sha3-512")));
	EVP_Q_digest(NULL, "sha3-512", NULL, data, strlen((char *)data), hash, (size_t *)size);
	return hash;
}
