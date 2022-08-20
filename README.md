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

Warning
--------
The encryption model for this programm is newline terminated, newline characters should be the same amount in both original and encrypted files and in the same locations.

if you were to compute the XOR of two characters thar result in newline character it will cause the encrypted file to have more newline characters and in wrong places, for example the letter 'e' with the decimal value 101 XORed with the letter 'o' (111) will result in newline character (010).

use with caution until i solve this issue.
