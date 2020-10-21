#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "simple_crypto.h"
#include "unistd.h"

int main() {

    if( !isatty(STDIN_FILENO) ){ // if the input is from console

// One-time Pad
    char *plaintext_otp;
    plaintext_otp =(char *) malloc(sizeof(char) * 4096);
    printf("[OTP] input: ");
    scanf("%m[^\n]", &plaintext_otp);
    printf("%s", plaintext_otp);
    printf("\n");

    int i;
    int size_of_plaintext = strlen(plaintext_otp);
    char secret_key[strlen(plaintext_otp)];
    for (i = 0; i < strlen(plaintext_otp); i++) {
        char randomData;
        FILE *fp;
        fp = fopen("/dev/urandom", "r");
        ssize_t result = fread(&randomData, sizeof(randomData), 1, fp);
        if (result > 0) {
            secret_key[i] = randomData;
        }
    }
    secret_key[i] = '\0';

    char *encrypted_message = one_time_pad_encryption(plaintext_otp, secret_key);
    char *decrypted_message = one_time_pad_decryption(encrypted_message, secret_key,size_of_plaintext);
    printf("[OTP] decrypted: %s", decrypted_message);

// Ceasars Cipher
    char *plaintext_ceasar;
    plaintext_ceasar =(char *) malloc(sizeof(char) * 4096);
    printf("\n[Caesar's] input: ");
    scanf("%m[^\n]", &plaintext_ceasar);
    printf("%s",plaintext_ceasar);
    int key;
    printf("\n");
    printf("[Caesar's] key: ");
    scanf("%d", &key);
    printf("%d",key);
    printf("\n");
    char *encrypted_message_ceasar  = ceasar_cipher_encryption(plaintext_ceasar, key);
    printf("[Caesars] encrypted: %s\n",encrypted_message_ceasar);
    char *decrypted_message_ceasar  = ceasar_cipher_decryption(encrypted_message_ceasar, key);
    printf("[Caesars] decrypted: %s", decrypted_message_ceasar);

// Vigenere cipher
    char *plaintext_vigenere;
    plaintext_vigenere =(char *) malloc(sizeof(char) * 4096);
    printf("\n[Vigenere] input: ");
    scanf("%m[^\n]", &plaintext_vigenere);
    scanf("%*c");
    printf("%s",plaintext_vigenere);
    printf("\n");
    char *key_vigenere;
    key_vigenere =(char *) malloc(sizeof(char) * 4096);
    printf("[Vigenere] key: ");

    scanf("%m[^\n]", &key_vigenere);
    printf("%s",key_vigenere);
    printf("\n");
    char *encrypted_message_vigenere = vigenere_cipher_encryption(plaintext_vigenere, key_vigenere);
    printf("[Vigenere] encrypted: %s\n",encrypted_message_vigenere);
    char * decrypted_message_vigenere  =  vigenere_cipher_decryption(encrypted_message_vigenere,key_vigenere);
    printf("[Vigenere] decrypted: %s\n",decrypted_message_vigenere);

    }
    else{  // else the input is from text with redirect
//One-time Pad Cipher    
    char *plaintext_otp;
    plaintext_otp =(char *) malloc(sizeof(char) * 4096);
    printf("[OTP] input: ");
    scanf("%m[^\n]", &plaintext_otp);

    int i;
    char secret_key[strlen(plaintext_otp)];
    int size_of_plaintext = strlen(plaintext_otp);
    for (i = 0; i < strlen(plaintext_otp); i++) {
        char randomData;
        FILE *fp;
        fp = fopen("/dev/urandom", "r");
        ssize_t result = fread(&randomData, sizeof(randomData), 1, fp);
        if (result > 0) {
            secret_key[i] = randomData;
        }
    }
    secret_key[i] = '\0';
    char *encrypted_message = one_time_pad_encryption(plaintext_otp, secret_key);
    char *decrypted_message = one_time_pad_decryption(encrypted_message, secret_key,size_of_plaintext);
    printf("[OTP] decrypted: %s", decrypted_message);

// Ceasars Cipher
    char *plaintext_ceasar;
    plaintext_ceasar =(char *) malloc(sizeof(char) * 4096);
    printf("\n[Caesars] input: ");
    scanf("%m[^\n]", &plaintext_ceasar);
    int key;
    printf("[Caesars] key: ");
    scanf("%d", &key);
    char *encrypted_message_ceasar  = ceasar_cipher_encryption(plaintext_ceasar, key);
    printf("[Caesar's] encrypted: %s\n",encrypted_message_ceasar);
    char *decrypted_message_ceasar  = ceasar_cipher_decryption(encrypted_message_ceasar, key);
    printf("[Caesar's] decrypted: %s", decrypted_message_ceasar);

//    Vigenere_Cipher
    char *plaintext_vigenere;
    plaintext_vigenere =(char *) malloc(sizeof(char) * 4096);
    printf("\n[Vigenere] input: ");
    scanf("%m[^\n]", &plaintext_vigenere);
    scanf("%*c");
    char *key_vigenere;
    key_vigenere =(char *) malloc(sizeof(char) * 4096);
    printf("[Vigenere] key: ");

    scanf("%m[^\n]", &key_vigenere);
    char *encrypted_message_vigenere = vigenere_cipher_encryption(plaintext_vigenere, key_vigenere);
    printf("[Vigenere] encrypted: %s\n",encrypted_message_vigenere);
    char * decrypted_message_vigenere  =  vigenere_cipher_decryption(encrypted_message_vigenere,key_vigenere);
    printf("[Vigenere] decrypted: %s\n",decrypted_message_vigenere);

   
    }

    return 0;
}
