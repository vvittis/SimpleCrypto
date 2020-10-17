#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>
#include "simple_producer.h"


char *one_time_pad_encryption(char *plaintext, char *secret_key) {
    static char *crypto;
    crypto = malloc(strlen(plaintext) * sizeof(char));
    int i;
    for (i = 0; i < strlen(plaintext); i++) {
        crypto[i] = plaintext[i] ^ secret_key[i];
    }
    crypto[i] = '\0';
    printf("[OTP] encrypted: ");
    int j;
    for (j = 0; j < strlen(plaintext); j++) {
        char crypto_temp;
        crypto_temp = crypto[j];
        if (isprint(crypto_temp) == 0) {
            printf("$");
        } else {
            printf("%c", crypto_temp);
        }
    }
    printf("\n");
    return crypto;

}

char *one_time_pad_decryption(char *crypto, char *secret_key) {
    int i;
    static char *decrypted_message;
    decrypted_message = malloc(strlen(crypto) * sizeof(char));
    for (i = 0; i < strlen(crypto); i++) {
        decrypted_message[i] = crypto[i] ^ secret_key[i];
    }
    decrypted_message[i] = '\0';
    printf("[OTP] decrypted: %s", decrypted_message);
    scanf("%*c");
    return decrypted_message;
}

char *ceasar_cipher_encryption(char *plainText, int key) {
    //Print the ciphered text
    int i;
//    char cipher[strlen(plainText)];

    static char *cipher;
    cipher = malloc(strlen(plainText) * sizeof(char));
    //Encryption
    printf("[Ceasars] encrypted: ");
    plainText[strlen(plainText)] = '\0';

    for (i = 0; i < strlen(plainText); i++) {
        // printf("%d\n",(int)plainText[i] );
        //if the character is lowercase, where range is [97 -122]
        if (isalpha(plainText[i]) != 0) {
            if (islower(plainText[i]) != 0) {
                int lower_alpha_pos;
                // printf("Inside Lower\n");
                // printf("\n2 %d\n",( (int)plainText[i]- 48 ) );
                lower_alpha_pos = (int) plainText[i] - 61;
                cipher[i] = (char) AlphabetWithDigits[(lower_alpha_pos + key) % 62][0];
            } else if (isupper(plainText[i]) != 0) {
                int upper_alpha_pos;
                // printf("ALpha inside %c\n",AlphabetWithDigits[10][0] );
                upper_alpha_pos = (int) plainText[i] - 55;
                cipher[i] = (char) AlphabetWithDigits[(upper_alpha_pos + key) % 62][0];
            }
            // printf("\n1 %d\n",( (int)plainText[i] ));
        } else if (isdigit(plainText[i]) != 0) {
            int digit_pos;
            // printf("\n2 %d\n",( (int)plainText[i]- 48 ) );
            digit_pos = (int) plainText[i] - 48;
            // printf("HAH %d\n",( digit_pos + key) % 62 );

            // printf("ALpha inside %c\n",AlphabetWithDigits[7][0] );
            cipher[i] = (char) AlphabetWithDigits[(digit_pos + key) % 62][0];
        }
        printf("%c", cipher[i]);


    }
    printf("\n");
    return cipher;

}


char *ceasar_cipher_decryption(char *plainText, int key) {
    //Decryption
    static char *cipher;
    cipher = malloc(strlen(plainText) * sizeof(char));
    printf("[Ceasars] decrypted: ");
    for (int i = 0; i < strlen(plainText); i++) {
        if (isalpha(plainText[i]) != 0) {
            if (islower(plainText[i]) != 0) {
                int lower_alpha_pos;
                // printf("Inside Lower\n");
                // printf("\n2 %d\n",( (int)plainText[i]- 48 ) );
                lower_alpha_pos = (int) plainText[i] - 61;
                cipher[i] = (char) AlphabetWithDigits[(lower_alpha_pos - key) % 62][0];
            } else if (isupper(plainText[i]) != 0) {
                int upper_alpha_pos;
                // printf("ALpha inside %c\n",AlphabetWithDigits[10][0] );
                upper_alpha_pos = (int) plainText[i] - 55;
                cipher[i] = (char) AlphabetWithDigits[(upper_alpha_pos - key) % 62][0];
            }
            // printf("\n1 %d\n",( (int)plainText[i] ));
        } else if (isdigit(plainText[i]) != 0) {
            int digit_pos;
            // printf("\n2 %d\n",( (int)plainText[i]- 48 ) );
            digit_pos = (int) plainText[i] - 48;
            // printf("HAH %d\n",( digit_pos + key) % 62 );

            // printf("ALpha inside %c\n",AlphabetWithDigits[7][0] );
            cipher[i] = (char) AlphabetWithDigits[(digit_pos - key) % 62][0];
        }
        printf("%c", cipher[i]);
    }
    return cipher;
}