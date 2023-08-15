#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

string cipher(string plaintext,string key);
int argmax(char letter);

const string alphabetUpper[26] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
//const string alphabetLower[26] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};

int main(int argc, string argv[])
{

    string plaintext = get_string("Plaintext: ");
    string key = get_string("Key: ");
    string ciphertext = cipher(plaintext,key);

    //printf("Ciphertext: %s\n", ciphertext);
    return 0;
}


string cipher(string plaintext, string key)
{
    string ciphered = plaintext;


    //makes an array of characters
    //where each element is a character from the key
    char keyLetters[strlen(key)]; // works
    for (int i = 0; i < strlen(key); i++) //for loop works
    {
        char c = key[i]; //works
        keyLetters[i] = c; //works
    }

    //performs the cipher
    for (int i = 0; i < strlen(plaintext); i++)
    {
        printf("plaintext: %s at %i\n", plaintext, i);
        //why does the 'O' change to an 'H'?
        char letter = plaintext[i];

        int alphabetIndex = argmax(letter);

        for (int j = 0; j < strlen(key); j++)
        {

            if (alphabetIndex == j)
            {
                ciphered[j] = keyLetters[j];
                break;
            }
        }


    }

    return ciphered;
}

//this function returns the argmax of the alphabet arrays
int argmax(char letter) //works
{
    int alphabetUpperLen = sizeof(alphabetUpper)/sizeof(alphabetUpper[0]);
    int index = -1;

    for (int i = 0; i < alphabetUpperLen; i++)
    {
        if (*alphabetUpper[i]==letter)
        {
            index = i;
            break;
        }
    }

    //printf("%c is at index %i \n", letter, index);
    return index;
}