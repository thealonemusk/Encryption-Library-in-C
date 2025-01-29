/* arcfour.c */

#include "arcfour.h"

export Arcfour *rc4init(int8* key, int16 size) {
    int8 temp1, temp2;
    Arcfour *p;

    // Allocate memory for the Arcfour structure
    if (!(p = malloc(sizeof(struct s_arcfour)))) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    // Initialize state array
    for (int x = 0; x < 256; x++) {
        p->s[x] = x;
    }

    temp1 = temp2 = 0;
    p->i = p->j = 0;

    // Key-scheduling algorithm
    for (p->i = 0; p->i < 256; p->i++) {
        temp1 = p->i % size;
        temp2 = (p->j + p->s[p->i] + key[temp1]) % 256;
        p->j = temp2;

        // Swap p->s[p->i] and p->s[p->j]
        int8 temp = p->s[p->i];
        p->s[p->i] = p->s[p->j];
        p->s[p->j] = temp;
    }

    p->i = p->j = 0;
    return p;
}

int8 rc4byte(Arcfour *p) {
    p->i = (p->i + 1) % 256;
    p->j = (p->j + p->s[p->i]) % 256;

    // Swap p->s[p->i] and p->s[p->j]
    int8 temp = p->s[p->i];
    p->s[p->i] = p->s[p->j];
    p->s[p->j] = temp;

    return p->s[(p->s[p->i] + p->s[p->j]) % 256];
}

export int8 *rc4encrypt(Arcfour *p, int8* cleartext, int16 size) {
    int8 *ciphertext = malloc(size + 1);
    if (!ciphertext) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    for (int x = 0; x < size; x++) {
        ciphertext[x] = cleartext[x] ^ rc4byte(p);
    }

    return ciphertext;
}
