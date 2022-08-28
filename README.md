XOR
=====
Simple key-based encrytpion using XOR gate.

Building
---------
You need GNU Make and GCC installed for building.

```bash
# make install clean
```

The binary will be copied into `/usr/local/bin` directory with the name `xor`.

Usage
-------
```bash
~$ xor <encryption key>
```
The programm will encrypt line by line reading from `stdin` and writing to `stdout`.

you need to redirect the input and output if you want to encrypt files

```bash
~$ xor "test key" < samplefile.txt > samplefile.txt.xor
```

and for decrypting, simply reverse the input and output with the same encryption key

```bash
~$ xor "test key" < samplefile.txt.xor > samplefile.txt
```
