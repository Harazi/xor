#include <stdlib.h>
#include <string.h>
#include <nettle/sha3.h>
#include "mince.h"

unsigned char *mince(const unsigned char *data, int *size)
{
	*size = SHA3_512_DIGEST_SIZE;
	unsigned char *hash = malloc(*size);
	struct sha3_512_ctx ctx;
	sha3_512_init(&ctx);
	sha3_512_update(&ctx, strlen((char *)data), data);
	sha3_512_digest(&ctx, *size, hash);
	return hash;
}
