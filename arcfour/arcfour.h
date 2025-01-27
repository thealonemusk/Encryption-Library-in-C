/* arcfour.h */
#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
#define export  __attribute__((visibility("default")))
#define rc4decrypt(x,y) rc4encrypt(x,y)
#define rc4uninit(x) free(x)

typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;

struct  s_arcfour
{
    int16 i,j,k; 
    int8 s[256];

};

typedef struct s_arcfour Arcfour;



export Arcfour *rc4init(int8*, int16);
int8 rc4byte(Arcfour*);

export int8 *rc4encrypt(Arcfour* , int8*, int16);




