#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

bool only_digit(string s);
char rotate(char c, int key);

int main(int argc, string argv[])
{
    // Check the number of command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1; // Exit with error
    }

    // Check if the key is a number
    if (!only_digit(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1; // Exit with error
    }

    // Convert the key to an integer
    int key = atoi(argv[1]);

    // Get the plaintext input from the user
    string plaintext = get_string("Plain text: ");
    printf("You have entered: %s\n", plaintext); // Added newline for clarity

    printf("ciphertext: "); // Prepare for ciphertext output

    // Encrypt the plaintext
    for (int i = 0; plaintext[i] != '\0'; i++)
    {
        char ciphertext_char = rotate(plaintext[i], key);
        printf("%c", ciphertext_char); // Print each character of the ciphertext
    }

    printf("\n"); // Newline at the end for clean output
    return 0;     // Exit successfully
}

bool only_digit(string s)
{
    // Check if each character is a digit
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] < '0' || s[i] > '9')
        {
            return false; // Found a non-digit character
        }
    }
    return true; // All characters are digits
}

char rotate(char c, int key)
{
    // Rotate uppercase letters
    if (c >= 'A' && c <= 'Z')
    {
        return 'A' + (c - 'A' + key) % 26;
    }
    // Rotate lowercase letters
    if (c >= 'a' && c <= 'z')
    {
        return 'a' + (c - 'a' + key) % 26;
    }
    return c; // Non-alphabetical characters are unchanged
}
