#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

string cipher(string plaintext, int rotation);

const string alphabetUpper[26] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
const string alphabetLower[26] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};

int main(int argc, string argv[])
{
    if (argc!=2)
    {
        printf("Usage: ./ceasar key\n");
        return 1;
    }

    string keyString = argv[1];
    int key = atoi(keyString);

    string plaintext = get_string("plaintext: ");

    string ciphertext = cipher(plaintext, key);

    printf("ciphertext: %s\n", ciphertext);

}

string cipher(string plaintext, int key)
{
    //continue working on cipher
    string ciphered = plaintext;

    for (int i = 0; i < strlen(plaintext); i++)
    {
        char letter = plaintext[i];
        if (isalpha(letter))
        {
            if (islower(letter))
            {
                int alphabetLowerIndex = letter-97;
                int caesarNum = (alphabetLowerIndex+key)%26;
                char caesarChar = caesarNum+97;
                ciphered[i] = caesarChar;
            }

            if (isupper(letter))
            {
                int alphabetUpperIndex = letter-65;
                int caesarNum = (alphabetUpperIndex+key)%26;
                char caesarChar = caesarNum+65;
                ciphered[i] = caesarChar;
            }
        }

        if (isdigit(letter))
        {
            ciphered[i] = letter;
        }

        if (!isalnum(letter))
        {
            ciphered[i] = letter;
        }
    }

    return ciphered;

}
