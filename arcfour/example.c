/* example.c */

#include "arcfour.h"

void printbin(int8 *input, const int16 size) {
    for (int16 i = 0; i < size; i++) {
        if (i > 0 && i % 2 == 0) {
            printf(" ");
        }
        printf("%.02x", input[i]);
    }
    printf("\n");
}

int main() {
    Arcfour *rc4;
    int16 skey, stext;
    char *key = "Julieus Ceaser";
    char *from = "Et tu, Brute?";
    int8 *encrypted, *decrypted;

    skey = strlen(key);
    stext = strlen(from);

    printf("Initializing encryption...\n");
    rc4 = rc4init((int8*)key, skey);

    printf("'%s' \n -> ", from);
    encrypted = rc4encrypt(rc4, (int8*)from, stext);
    printbin(encrypted, stext);

    rc4uninit(rc4);

    printf("Initializing decryption...\n");
    rc4 = rc4init((int8*)key, skey);

    decrypted = rc4decrypt(rc4, encrypted, stext);
    printf("Decrypted -> '%s'\n", decrypted);

    free(encrypted);
    free(decrypted);
    rc4uninit(rc4);

    return 0;
}
