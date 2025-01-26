/* example.c */

#include "arcfour.h"
#define F fflush(stdout)
int main (void);

// ef20 ac12

void printbin(int8 *input , const int16 size){
    int16 i;
    int8 *p;
    // i = 32 aa
    // i = 31 bb
    assert(size>0);

    for (i = size , p = input ; i ; i-- , p++){
        if(!((i+1) % 2 )){
            printf(" ");
        }
        printf("%.02x" , *p);
    }
    printf("\n");

    return; 
}
int main(){
    // Arcfour *rc4;
    int16 skey , stext;
    char *key , *from , *encrypted , *decrypted;
    
    key = from = encrypted = decrypted = 0 ; 

    from = key ; 

    skey= stext = 0 ; 

    key = "Julieus Ceaser"; /* 8 bits -> 2048 bits*/
    skey  =  strlen(key);
    from = "Et tu, Brute?";
    stext = strlen(from);

    printf("Inititalising encryption ..."); F;

    // rc4 = rc4init(key , skey );

    printf ("done\n");
    printf("'%s' \n ->" , from);

    // encrypted = rc4encrypt(from , stext);
    printbin((int8 *)key , skey);
    return 0 ; 
}

