GCCFLAGS = -Wall -Werror

all: xor

encrypt.o: encrypt.c
	gcc $(GCCFLAGS) -c encrypt.c

xor.o: xor.c encrypt.h
	gcc $(GCCFLAGS) -c xor.c

xor: xor.o encrypt.o
	gcc $(GCCFLAGS) xor.o encrypt.o -o xor

debug:
	gcc $(GCCFLAGS) -g -c encrypt.c
	gcc $(GCCFLAGS) -g -c xor.c
	gcc $(GCCFLAGS) xor.o encrypt.o -o xor

install: xor
	cp xor /usr/local/bin/

clean:
	rm encrypt.o xor.o xor
