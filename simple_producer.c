#include <stdio.h>
#include <string.h>
#include <ctype.h>

void One_Time_Pad(char *plaintext, char *secret_key) {
    char crypto[strlen(plaintext)];
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
    for (i = 0; i < strlen(plaintext); i++){
        plaintext[i] = crypto[i] ^ secret_key[i];
    }
    plaintext[i] = '\0';
    printf("[OTP] decrypted: %s", plaintext);

}