# Auto Key Cipher

## Objective

To implement the **Auto Key Cipher** in C++ for performing both **encryption and decryption**, and to understand the working of classical cryptographic techniques.

## Theory

The **Auto Key Cipher** is a type of polyalphabetic substitution cipher. It is an improvement over the Vigenère Cipher because it avoids repeating the key.

In this method:

- A short key is initially provided
- The plaintext is appended to the key to generate a longer key
- This reduces repetition and increases security

## Encryption

### Formula:

Ci = (Pi + Ki) mod 26

### Steps:

1. Convert plaintext and key to uppercase
2. Extend the key using plaintext
3. Apply the formula to each character
4. Generate ciphertext

## Decryption

### Formula:

Pi = (Ci - Ki + 26) mod 26

### Steps:

1. Convert ciphertext and key to uppercase
2. Use the original key for initial characters
3. Use decrypted plaintext to extend the key
4. Recover the original plaintext

## Program Description

The program is menu-driven and provides two options:

1. Encryption
2. Decryption

### Functions Used:

- `toUpperCase()` → Converts input to uppercase
- `autoKeyEncrypt()` → Performs encryption
- `autoKeyDecrypt()` → Performs decryption

## Sample Input and Output

### Encryption

Enter Plaintext: instagram
Enter Key: rot
Ciphertext: ZBLBNYKAS

### Decryption

```
Enter Ciphertext: ZBLBNYKAS
Enter Key: rot
Decrypted Plaintext: INSTAGRAM
```

## Conclusion

The Auto Key Cipher provides better security than repeating-key ciphers by using plaintext to extend the key. This program demonstrates both encryption and decryption processes and helps in understanding the fundamentals of classical cryptography.
