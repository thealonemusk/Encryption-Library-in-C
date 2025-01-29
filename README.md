# RC4 Encryption Library

This repository contains a simple implementation of an RC4 encryption library written in C. It provides functions for initializing the RC4 cipher, encrypting plaintext, and decrypting ciphertext using the same function due to the symmetric nature of the RC4 algorithm.

---

## Features
- **RC4 Initialization**: Sets up the key schedule.
- **RC4 Encryption/Decryption**: Performs encryption and decryption using XOR-based stream generation.
- **Shared Library**: The library is compiled into a shared object file (`libarcfour.so`) for easy reuse.
- **Example Program**: A simple example program (`example.c`) demonstrates the library in action.

---

## Requirements
- GCC (GNU Compiler Collection)
- Linux or Unix-based system

---

## File Structure
- `arcfour.c`: Contains the implementation of the RC4 cipher.
- `arcfour.h`: The header file defining the RC4 functions and data structures.
- `example.c`: A demonstration of the library's usage.
- `Makefile`: Automates the build process for the library and example program.

---

## Usage

### Step 1: Clone the Repository
```bash
git clone <repository-url>
cd <repository-directory>
```

### Step 2: Build the Library and Example Program
Run the following command:
```bash
make
```
This will generate:
- `libarcfour.so`: The shared library.
- `example`: The example program.

### Step 3: Run the Example Program
Set the library path to include the current directory:
```bash
export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
```
Run the program:
```bash
./example
```

The program will:
1. Encrypt a hardcoded plaintext string.
2. Print the encrypted text in hexadecimal format.
3. Decrypt the encrypted text and print the original plaintext.

---

## Functions

### `Arcfour *rc4init(int8 *key, int16 size)`
Initializes the RC4 cipher with the given key.
- **Parameters**:
  - `key`: Pointer to the key.
  - `size`: Size of the key in bytes.
- **Returns**: A pointer to the initialized RC4 structure.

### `int8 rc4byte(Arcfour *p)`
Generates the next byte in the RC4 keystream.
- **Parameters**:
  - `p`: Pointer to the RC4 structure.
- **Returns**: The next byte in the keystream.

### `int8 *rc4encrypt(Arcfour *p, int8 *cleartext, int16 size)`
Encrypts or decrypts data using the RC4 cipher.
- **Parameters**:
  - `p`: Pointer to the RC4 structure.
  - `cleartext`: Pointer to the data to encrypt or decrypt.
  - `size`: Size of the data.
- **Returns**: Pointer to the encrypted/decrypted data.

### Macro: `rc4decrypt`
Defined as:
```c
#define rc4decrypt(rc4, data, size) rc4encrypt(rc4, data, size)
```
Decrypts data using the same function as encryption.

### Macro: `rc4uninit`
Frees the memory allocated for the RC4 structure.
- **Usage**:
```c
rc4uninit(rc4);
```

---

## Example Output
```
Inititalising encryption ... done
'Et tu, Brute?' 
 -> 4f 5d 6a 31 2b 7e 63 50 28 4c 6f 7d 0a
Inititalising encryption ... done
'   ->   Et tu, Brute?'
```

---

## Cleaning Up
To clean up the compiled files:
```bash
make clean
```
This removes all object files, the shared library, and the example program.

---

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

---

## Acknowledgments
- The RC4 algorithm is attributed to Ron Rivest and was a widely used stream cipher in the past.
- Special thanks to contributors who help improve this implementation.

