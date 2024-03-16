XOR
=====
Simple key-based encryption using XOR gate.

Building
---------
Although bitwise operations are built into C, you still need a cryptographic library for hashing the key to mitigate exploits for guessing the key length. The list of supported libraries are in the Makefile, choose one and build with it.

```sh
$ make openssl
```

Usage
-------
The only argument is the encryption key, stdin and stdout are utilized for reading and writing.

```sh
$ echo -n 1234567890 | xor test | xxd -p
# affc3b5aae9a7e27956c
```

Do the reverse for decrypting.

```sh
$ echo -n affc3b5aae9a7e27956c | xxd -p -r | xor test
# 1234567890
```
