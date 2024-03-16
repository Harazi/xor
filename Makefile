.POSIX:
.SUFFIXES:

CC            = gcc
CFLAGS        = -march=native -O3 -pipe -Wall -Werror -s

# GNU Make will evaluate $^, while BSD Make will evaluate ${.ALLSRC}
prerequisites = $^ ${.ALLSRC}

nettle: xor.c nettle.c
	$(CC) $(CFLAGS) -o xor $(prerequisites) -lnettle

openssl: xor.c openssl.c
	$(CC) $(CFLAGS) -o xor $(prerequisites) -lcrypto

gnutls: xor.c gnutls.c
	$(CC) $(CFLAGS) -o xor $(prerequisites) -lgnutls
