#include <stdlib.h>
#include <string.h>
#include <gnutls/crypto.h>
#include "mince.h"

unsigned char *mince(const unsigned char *data, int *size)
{
	*size = gnutls_hash_get_len(GNUTLS_DIG_SHA3_512);
	unsigned char *hash = malloc(*size);
	gnutls_hash_fast(GNUTLS_DIG_SHA3_512, data, strlen((char *)data), hash);
	return hash;
}
