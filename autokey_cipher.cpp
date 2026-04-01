#include <iostream>
#include <string>
using namespace std;

// Function to convert to uppercase
string toUpperCase(string text)
{
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            text[i] = text[i] - 'a' + 'A'; // Convert to uppercase using ASCII logic
        }
    }
    return text;
}

// Encryption Function
string autoKeyEncrypt(string plaintext, string key)
{
    string finalKey = key;

    // Extend key using plaintext
    for (int i = 0; finalKey.length() < plaintext.length(); i++)
    {
        finalKey += plaintext[i];
    }

    string ciphertext = "";

    for (int i = 0; i < plaintext.length(); i++)
    {
        char p = plaintext[i];
        char k = finalKey[i];

        if (p >= 'A' && p <= 'Z')
        {
            char c = ((p - 'A') + (k - 'A')) % 26 + 'A'; // Ci = (Pi + Ki) mod 26
            ciphertext += c;
        }
    }

    return ciphertext;
}

// Decryption Function
string autoKeyDecrypt(string ciphertext, string key)
{
    string plaintext = "";

    for (int i = 0; i < ciphertext.length(); i++)
    {
        char k;

        if (i < key.length())
        {
            k = key[i];
        }
        else
        {
            k = plaintext[i - key.length()];
        }

        char c = ciphertext[i];

        char p = ((c - 'A') - (k - 'A') + 26) % 26 + 'A';
        plaintext += p;
    }

    return plaintext;
}

int main()
{
    int choice;
    string text, key;

    cout << "\n--- Auto Key Cipher ---\n";
    cout << "1. Encryption\n";
    cout << "2. Decryption\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1)
    {
        cout << "Enter Plaintext: ";
        cin >> text;

        cout << "Enter Key: ";
        cin >> key;

        text = toUpperCase(text);
        key = toUpperCase(key);

        string cipher = autoKeyEncrypt(text, key);
        cout << "Ciphertext: " << cipher << endl;
    }
    else if (choice == 2)
    {
        cout << "Enter Ciphertext: ";
        cin >> text;

        cout << "Enter Key: ";
        cin >> key;

        text = toUpperCase(text);
        key = toUpperCase(key);

        string plain = autoKeyDecrypt(text, key);
        cout << "Decrypted Plaintext: " << plain << endl;
    }
    else
    {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}