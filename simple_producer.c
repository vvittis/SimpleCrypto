#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>
#include "simple_producer.h"


char *one_time_pad_encryption(char *plaintext, const char *secret_key) {
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

char *one_time_pad_decryption(char *crypto, const char *secret_key) {
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

char *ceasar_cipher_decryption(char *crypto, int key) {
    //Decryption
    static char *cipher;
    cipher = malloc(strlen(crypto) * sizeof(char));
    printf("[Ceasars] decrypted: ");
    for (int i = 0; i < strlen(crypto); i++) {
        if (isalpha(crypto[i]) != 0) {
            if (islower(crypto[i]) != 0) {
                int lower_alpha_pos;
                // printf("Inside Lower\n");
                // printf("\n2 %d\n",( (int)plainText[i]- 48 ) );
                lower_alpha_pos = (int) crypto[i] - 61;
                cipher[i] = (char) AlphabetWithDigits[(lower_alpha_pos - key) % 62][0];
            } else if (isupper(crypto[i]) != 0) {
                int upper_alpha_pos;
                // printf("ALpha inside %c\n",AlphabetWithDigits[10][0] );
                upper_alpha_pos = (int) crypto[i] - 55;
                cipher[i] = (char) AlphabetWithDigits[(upper_alpha_pos - key) % 62][0];
            }
            // printf("\n1 %d\n",( (int)plainText[i] ));
        } else if (isdigit(crypto[i]) != 0) {
            int digit_pos;
            // printf("\n2 %d\n",( (int)plainText[i]- 48 ) );
            digit_pos = (int) crypto[i] - 48;
            // printf("HAH %d\n",( digit_pos + key) % 62 );

            // printf("ALpha inside %c\n",AlphabetWithDigits[7][0] );
            cipher[i] = (char) AlphabetWithDigits[(digit_pos - key) % 62][0];
        }
        printf("%c", cipher[i]);
    }
    scanf("%*c");
    return cipher;
}

void generateKey(char *str, char *key) {

    int x = strlen(str);
    int y = strlen(key);

    int j = 0;
    char value[strlen(str)];
    for (int i = 0; i < x; i++) {

        if (i >= y) {

            key[i] = key[j];

            j++;
            if (j == y) {
                j = 0;
            }
        } else {

            key[i] = key[i];
        }
        // printf("%c ",value[i] );
    }
    // printf("KEY: %s\n",key );
}


char * vigenere_cipher_encryption(char *plainText, char *key){

    int i;
    generateKey(plainText, key);
//    printf("[Vigenere] key1: %s\n", key);
    //print the encrypted plain text
    printf("[Vigenere] encrypted: ");
    static char *cipher;
    cipher = malloc(strlen(plainText) * sizeof(char));
    int cipherValue;
    int len = strlen(key);

    //Loop through the length of the plain text string
    for (i = 0; i < strlen(plainText); i++) {

        //if the character is lowercase, where range is [97 -122]
        cipherValue = ((int) plainText[i] - 65 + (int) toupper(key[i % len]) - 65) % 26 + 65;
        cipher[i] = (char) cipherValue;
        printf("%c",cipher[i]);

    }
    cipher[i] = '\0';
    printf("\n");
    return cipher;
}


char * vigenere_cipher_decryption(char *crypto, char *key){
    int len = strlen(key);
    int i;
    printf("[Vigenere] decrypted: ");
    char de;
    int decipherValue;
    crypto[i] = '\0';
    //Loop through the length of the plain text string
    for (i = 0; i < strlen(crypto); i++) {
        //if the character is lowercase, where range is [97 -122]
        if (islower(crypto[i])) {
            decipherValue = (((int) crypto[i] - 97) - ((int) tolower(key[i % len]) - 97) + 26) % 26 + 97;
            de = (char) decipherValue;

        } else // Else it's upper case, where letter range is [65 - 90]
        {
            decipherValue = (((int) crypto[i] - 65) - ((int) toupper(key[i % len]) - 65) + 26) % 26 + 65;
            de = (char) decipherValue;
        }

        //Print the ciphered character if it is alphanumeric (a letter)
        if (isalpha(crypto[i])) {
            printf("%c", de);
        } else //if the character is not a letter then print the character (e.g. space)
        {
            printf("%c", crypto[i]);
        }
    }

    printf("\n");

}
