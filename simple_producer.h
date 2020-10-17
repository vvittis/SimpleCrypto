/**
 * INFO:      One-Time Pad (It read an input plaintext and generates a random secret key from /dev/urandom)
 * FUNCTIONS: 1. NAME:      one_time_pad_encryption
 *               INPUT:     input_plaintext, input_secret_key
 *               OUTPUT:    encrypted_message
 *            2. NAME:      one_time_pad_decryption
 *               INPUT:     encrypted_message,input_secret_key
 *               OUTPUT     decrypted_message
 */
char *one_time_pad_encryption(char *plaintext, const char *secret_key);

char *one_time_pad_decryption(char *encrypted_message, const char *secret_key);

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
char *ceasar_cipher_encryption(char *plainText, int key);

char *ceasar_cipher_decryption(char *encrypted_message, int key);

char *vigenere_cipher_encryption(char *plainText, char * key);

char *vigenere_cipher_decryption(char *encrypted_message, char * key);

void Vigenere_Cipher();

static char AlphabetWithDigits[62][1] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F",
                                         "G", "H", "I", "J", "K", "L", "M",
                                         "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "a", "b", "c",
                                         "d", "e", "f", "g", "h", "i", "j",
                                         "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y",
                                         "z"};