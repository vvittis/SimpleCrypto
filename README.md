# SimpleCrypto

This projects implements 3 crypto algorithms

1. One-time Pad
2. Caesar's Cipher
3. Vigenere's Cipher

## One-Time Pad
The OTP algorithm is a very simple but yet very strong algorithm in the sense that it can not be cracked even 
with post-quantum techniques.

In case of non printable characters, the One-Time Pad prints $

```
INFO:      One-Time Pad (It read an input plaintext and generates a random secret key from /dev/urandom)
FUNCTIONS: 1. NAME:      one_time_pad_encryption
              INPUT:     input_plaintext, input_secret_key,size_of_input
              OUTPUT:    encrypted_message
           2. NAME:      one_time_pad_decryption
              INPUT:     encrypted_message,input_secret_key
              OUTPUT     decrypted_message
```
In the one_time_pad_decryption function is necessary to add the size_of_plaintext because if the output of XOR produces the character '\' the key will not end

## Caesar's Cipher
This technique is one of the simplest and most widely known encryption techniques.
```
INFO: Caesar's Cipher (It reads an input plaintext and a positive key)
FUNCTIONS: 1.  NAME:      ceasar_cipher_encryption
               INPUT:     plaintext_ceasar, key
               OUTPUT:    encrypted_message_ceasar
            2. NAME:      ceasar_cipher_decryption
               INPUT:     encrypted_message_ceasar,key
               OUTPUT     decrypted_message_ceasar
```
## Vigenere's Cipher
The Vigenere's cipher encrypts an alphabetic plaintext using a series of interwoven Caesar's ciphers.
```
INFO: Vigenere's Cipher (It reads an input plaintext and a key text)
FUNCTIONS: 1. NAME:      vigenere_cipher_encryption
            INPUT:     plaintext_ceasar, key
            OUTPUT:    encrypted_message_ceasar
         2. NAME:      vigenere_cipher_decryption
            INPUT:     encrypted_message_ceasar,key
            OUTPUT     decrypted_message_ceasar
```

## Demo.c

There is an extra implementation in demo.c which takes into consideration the cases of ./demo < test.xt and ./demo
