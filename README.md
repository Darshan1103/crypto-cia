# Auto Key Cipher

## Objective

To implement the **Auto Key Cipher** in C++ for performing both **encryption, hashing and decryption**, and to understand the working of classical cryptographic techniques.


## Theory

The **Auto Key Cipher** is a type of polyalphabetic substitution cipher. It is an improvement over the Vigenère Cipher because it avoids repeating the key.

In this method:

* A short key is initially provided
* The plaintext is appended to the key to generate a longer key
* This reduces repetition and increases security

In addition to encryption, a hash function is used to ensure data integrity. A hash function converts the ciphertext into a fixed-size numerical value (hash). In this program, a custom hash function based on multiplication and XOR operations is used.


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



## Custom Hash Function

A modified polynomial hash with XOR operation is used.

### Formula:

Hash = ((Hash × 41) XOR character) mod 100057

### Description:

* Initial hash value is 13
* Each character is processed using multiplication and XOR
* XOR increases randomness and reduces collisions
* Produces a fixed-size hash value

### Code Logic:

```cpp id="j6shm5"
hash = ((hash * 41) ^ c) % 100057;
```



## ⚙️ Working

### Encryption:

1. Convert plaintext and key to uppercase
2. Encrypt using Auto Key Cipher
3. Generate hash of ciphertext
4. Display ciphertext and hash

### Decryption:

1. Enter ciphertext and key
2. Verify hash
3. Decrypt ciphertext to original plaintext



## Program Description

The program is menu-driven and provides two options:

1. Encryption
2. Decryption

### Functions Used:

* `toUpperCase()` → Converts input to uppercase
* `autoKeyEncrypt()` → Performs encryption
* `autoKeyDecrypt()` → Performs decryption
* `int polyHash()` → Performs hashing



## Sample Input and Output

### Encryption

```id="j9j14g"
--- Auto Key Cipher ---
1. Encryption
2. Decryption
Enter your choice: 1
Enter Plaintext: INSTAGRAM
Enter Key: META
Ciphertext: URLTITJTM
Hash Value: 71617
```

### Decryption

```id="4i3ds7"
--- Auto Key Cipher ---
1. Encryption
2. Decryption
Enter your choice: 2
Enter Ciphertext: URLTITJTM
Enter Key: META
Decrypted Plaintext: INSTAGRAM
```

## Conclusion

The Auto Key Cipher provides better security than repeating-key ciphers by using plaintext to extend the key. This program demonstrates encryption, hashing, and decryption processes and helps in understanding the fundamentals of classical cryptography and data integrity.


