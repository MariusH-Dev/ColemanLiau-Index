#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void count_char_word_sentence(const char *text, int *char_count, int *word_count, int *sentence_count);
double calculation_of_average_letters(int char_count, int word_count);
double calculation_of_average_sentence(int word_count, int sentence_count);
void coleman_liau_index(int char_count, int word_count, int sentence_count);

int main()
{
    // Allocate memory for user input and prompt for text input
    char text[1000];
    printf("Text: ");
    fgets(text, sizeof(text), stdin); // Reads a line of input from the user

    // Initialize counters for characters, words, and sentences
    int char_count = 0, word_count = 0, sentence_count = 0;

    // Function to count characters, words, and sentences
    count_char_word_sentence(text, &char_count, &word_count, &sentence_count);

    // Calculate and print the Coleman-Liau Index
    coleman_liau_index(char_count, word_count, sentence_count);

    return 0;
}

// Function to count the number of characters, words, and sentences in the text
void count_char_word_sentence(const char *text, int *char_count, int *word_count, int *sentence_count)
{
    bool in_word = false;

    // Traverse through the text
    for (int i = 0; i < strlen(text); i++)
    {
        // Count alphabetic characters
        if (isalpha(text[i]))
        {
            (*char_count)++;

            // Count words, triggered when we are at the start of a new word
            if (!in_word)
            {
                (*word_count)++;
                in_word = true;
            }
        }

        // End of word when a space is found
        if (isspace(text[i]))
        {
            in_word = false;
        }

        // Count sentences based on punctuation marks
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            (*sentence_count)++;
        }
    }
}

// Function to calculate the average number of letters per 100 words
double calculation_of_average_letters(int char_count, int word_count)
{
    if (word_count == 0)
        return 0.0;
    return ((double) char_count / word_count) * 100;
}

// Function to calculate the average number of sentences per 100 words
double calculation_of_average_sentence(int word_count, int sentence_count)
{
    if (word_count == 0)
        return 0.0;
    return ((double) sentence_count / word_count) * 100;
}

// Function to calculate and display the Coleman-Liau Index
void coleman_liau_index(int char_count, int word_count, int sentence_count)
{
    // Calculate the average letters and sentences per 100 words
    double l = calculation_of_average_letters(char_count, word_count);
    double s = calculation_of_average_sentence(word_count, sentence_count);

    // Compute the Coleman-Liau index
    int index = round((0.0588 * l) - (0.296 * s) - 15.8);

    // Display the grade level based on the index
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}