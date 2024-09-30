#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int score(string word);
    // Get input for Player 1
    string a = get_string("Player 1: ");

    // Get input for Player 2
    string b = get_string("Player 2: ");

    // Calculate scores for both players
    int score_a = score(a);
    int score_b = score(b);

    // Print scores for debugging (optional)
    printf("Player 1 score: %d\n", score_a);
    printf("Player 2 score: %d\n", score_b);

    // Determine the winner based on scores
    if (score_a > score_b)
    {
        printf("Player 1 wins!\n");
    }
    else if (score_b > score_a)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("It's a tie!\n");
    }

    return 0;
}

int score(string word)
{
    int score = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        char letter = tolower(word[i]);
        switch (letter)
        {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'l':
            case 'n':
            case 's':
            case 't':
            case 'r':
                score += 1;
                break;
            case 'd':
            case 'g':
                score += 2;
                break;
            case 'b':
            case 'c':
            case 'm':
            case 'p':
                score += 3;
                break;
            case 'f':
            case 'h':
            case 'v':
            case 'w':
            case 'y':
                score += 4;
                break;
            case 'k':
                score += 5;
                break;
            case 'j':
            case 'x':
                score += 8;
                break;
            case 'q':
            case 'z':
                score += 10;
                break;
            default:
                break; // Ignore non-alphabetic characters
        }
    }
    return score;
}
