#include <stdio.h>
#include <string.h>
#include "simple_crypto.h"
#include "unistd.h"

int main() {

    if( !isatty(STDIN_FILENO) ){ 
    char *plaintext_otp = NULL;
    printf("[OTP] input: ");
    scanf("%m[^\n]", &plaintext_otp);
    printf("%s", plaintext_otp);
    printf("\n");

    int i;
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
    char *decrypted_message = one_time_pad_decryption(encrypted_message, secret_key);
//    printf("%s",decrypted_message);


    char *plaintext_ceasar = NULL;
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
    char *decrypted_message_ceasar  = ceasar_cipher_decryption(encrypted_message_ceasar, key);
//    printf("%s",decrypted_message_ceasar);

//    Vigenere_Cipher();
    char *plaintext_vigenere = NULL;
    printf("\n[Vigenere] input: ");
    scanf("%m[^\n]", &plaintext_vigenere);
    scanf("%*c");
    printf("%s",plaintext_vigenere);
    printf("\n");
    char *key_vigenere = NULL;
    printf("[Vigenere] key: ");

    scanf("%m[^\n]", &key_vigenere);
    printf("%s",key_vigenere);
    printf("\n");
    char *encrypted_message_vigenere = vigenere_cipher_encryption(plaintext_vigenere, key_vigenere);
    char * decrypted_message_vigenere  =  vigenere_cipher_decryption(encrypted_message_vigenere,key_vigenere);

    return 0;
    }
    else{
    }
    char *plaintext_otp = NULL;
    printf("[OTP] input: ");
    scanf("%m[^\n]", &plaintext_otp);

    int i;
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
    char *decrypted_message = one_time_pad_decryption(encrypted_message, secret_key);
//    printf("%s",decrypted_message);

    char *plaintext_ceasar = NULL;
    printf("\n[Caesar's] input: ");
    scanf("%m[^\n]", &plaintext_ceasar);
    int key;
    printf("[Caesar's] key: ");
    scanf("%d", &key);
    char *encrypted_message_ceasar  = ceasar_cipher_encryption(plaintext_ceasar, key);
    char *decrypted_message_ceasar  = ceasar_cipher_decryption(encrypted_message_ceasar, key);
//    printf("%s",decrypted_message_ceasar);

    /**
     * CEASAR'S CIPHER
     * IT READS AN INPUT PLAINTEXT AND AN INPUT KEY
     */
//    Vigenere_Cipher();
    char *plaintext_vigenere = NULL;
    printf("\n[Vigenere] input: ");
    scanf("%m[^\n]", &plaintext_vigenere);
    scanf("%*c");
    char *key_vigenere = NULL;
    printf("[Vigenere] key: ");

    scanf("%m[^\n]", &key_vigenere);
    char *encrypted_message_vigenere = vigenere_cipher_encryption(plaintext_vigenere, key_vigenere);
    char * decrypted_message_vigenere  =  vigenere_cipher_decryption(encrypted_message_vigenere,key_vigenere);

    return 0;
}
