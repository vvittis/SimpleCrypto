#include <stdio.h>
#include <string.h>
#include "simple_producer.h"

int main() {
    /**
     * ONE-TIME PAD ALGORITHM
     * IT READS AN INPUT PLAINTEXT
     * AND GENERATES A RANDOM SECRET KEY FROM /dev/urandom
     */
    char *plaintext = NULL;
    printf("[OTP] input: ");
    scanf("%m[^\n]", &plaintext);
    int i;
    char secret_key[strlen(plaintext)];

    for (i = 0; i < strlen(plaintext); i++) {
        char randomData;
        FILE *fp;
        fp = fopen("/dev/urandom", "r");
        ssize_t result = fread(&randomData, sizeof(randomData), 1, fp);
        if (result > 0) {
            secret_key[i] = randomData;
            // printf("%d\n",key[i] );
            // printf("%c\n",(char)(key[i]) );
            // something went wrong
        }
    }
    secret_key[i] = '\0';
    One_Time_Pad(plaintext,secret_key);

    return 0;
}
