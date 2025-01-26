# Implementation of Rc4 encryption algorithm as Library in C 



RC4 is a stream cipher designed by Ron Rivest in 1987. It has been widely used in various protocols and standards such as WEP, WPA, SSL/TLS, and Microsoft Office. However, multiple vulnerabilities have been discovered in RC4, rendering it insecure for modern use. Attacks on RC4 have shown that the initial bytes of the keystream are biased and can be used to recover the secret key, especially when the key is reused across multiple messages.

The RC4 algorithm works by initializing a 256-byte permutation array S based on the secret key, and then generating a keystream byte-by-byte by swapping elements in S. This keystream is then XORed with the plaintext to produce the ciphertext. However, the weak key schedule of RC4 allows attackers to exploit statistical biases in the initial keystream bytes to mount practical attacks, particularly on protocols like WEP that reuse the same key.

Due to these vulnerabilities, the use of RC4 has been prohibited in TLS/SSL by the IETF, and vendors like Microsoft and Mozilla have recommended disabling it. Several attempts have been made to strengthen RC4, such as RC4A, VMPC, and Spritz, but these variants have also been cryptanalyzed and shown to have weaknesses. As of 2015, there is speculation that state cryptologic agencies may have advanced attacks that can break RC4 even in the context of TLS, making it an insecure choice for modern cryptographic applications.



# main article used for reference "(https://en.wikipedia.org/wiki/RC4);