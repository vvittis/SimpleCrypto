#include <stdio.h>
#include <string.h>
#include "simple_producer.h"

int main() {
    /**
     * INFO:      One-Time Pad (It read an input plaintext and generates a random secret key from /dev/urandom)
     * FUNCTIONS: 1. NAME:      one_time_pad_encryption
     *               INPUT:     input_plaintext, input_secret_key
     *               OUTPUT:    encrypted_message
     *            2. NAME:      one_time_pad_decryption
     *               INPUT:     encrypted_message,input_secret_key
     *               OUTPUT     decrypted_message
     */
//    char *plaintext_otp = NULL;
//    printf("[OTP] input: ");
//    scanf("%m[^\n]", &plaintext_otp);
//
//    int i;
//    char secret_key[strlen(plaintext_otp)];
//    for (i = 0; i < strlen(plaintext_otp); i++) {
//        char randomData;
//        FILE *fp;
//        fp = fopen("/dev/urandom", "r");
//        ssize_t result = fread(&randomData, sizeof(randomData), 1, fp);
//        if (result > 0) {
//            secret_key[i] = randomData;
//        }
//    }
//    secret_key[i] = '\0';
//    char *encrypted_message = one_time_pad_encryption(plaintext_otp, secret_key);
//    char *decrypted_message = one_time_pad_decryption(encrypted_message, secret_key);
//    printf("%s",decrypted_message);

    /**
     * INFO: Caesar's Cipher (It reads an input plaintext and a positive key)
     * FUNCTIONS: 1. NAME:      ceasar_cipher_encryption
     *               INPUT:     plaintext_ceasar, key
     *               OUTPUT:    encrypted_message_ceasar
     *            2. NAME:      ceasar_cipher_decryption
     *               INPUT:     encrypted_message_ceasar,key
     *               OUTPUT     decrypted_message_ceasar
     *
     */

//    char *plaintext_ceasar = NULL;
//    printf("\n[Caesar's] input: ");
//    scanf("%m[^\n]", &plaintext_ceasar);
//    int key;
//    printf("[Caesar's] key: ");
//    scanf("%d", &key);
//    char *encrypted_message_ceasar  = ceasar_cipher_encryption(plaintext_ceasar, key);
//    char *decrypted_message_ceasar  = ceasar_cipher_decryption(encrypted_message_ceasar, key);
//    printf("%s",decrypted_message_ceasar);

    /**
     * CEASAR'S CIPHER
     * IT READS AN INPUT PLAINTEXT AND AN INPUT KEY
     */
    Vigenere_Cipher();


    return 0;
}
