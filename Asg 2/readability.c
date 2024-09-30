#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");

    // Count the number of letters, words, and sentences in the text
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Compute L and S
    float L = ((float) letters / words) * 100;   // Average letters per 100 words
    float S = ((float) sentences / words) * 100; // Average sentences per 100 words

    // Compute the Coleman-Liau index
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // Print the grade level
    if (index < 1)
    {
        printf("Grade Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

    return 0;
}

int count_letters(string text)
{
    int count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i])) // Check if the character is a letter
        {
            count++;
        }
    }
    return count;
}

int count_words(string text)
{
    int count = 0;
    bool in_word = false; // Track whether we are inside a word
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isspace(text[i])) // If we hit a space
        {
            in_word = false; // We're not in a word anymore
        }
        else if (!in_word) // If we're not in a word and hit a non-space
        {
            count++;        // Count a new word
            in_word = true; // Now we're in a word
        }
    }
    return count; // Just return the count
}

int count_sentences(string text)
{
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            count++; // Count the sentence
        }
    }
    return count; // Return the count directly
}
