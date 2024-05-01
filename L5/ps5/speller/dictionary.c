// Implements a dictionary's functionality
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        return true;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function

    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // Open the input file, which is dictionary
    FILE *input = fopen(dictionary, "r");
    if (input == NULL)
    {
        printf("Can not open the dictionary\n");
        return 1;
    }
    // Initialize hash table
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    // Read each word in the input file
    char c, word[LENGTH + 1];
    int index = 0;
    while (fread(&c, sizeof(char), 1, input))
    {
        if (c == '\n')
        {
            // Add each word to the hash table
            node *new_node = malloc(sizeof(node));
            if (new_node == NULL)
            {
                printf("Memory allocation failed\n");
                return false;
            }
            strcpy(new_node->word, word);
            new_node->next = NULL;

            int n = word[0] - 'a';
            if (table[n] == NULL)
            {
                table[n] = new_node;
            }
            else
            {
                node *ptr = table[n];
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = new_node;
            }

            for (int i = 0; i < index; i++)
            {
                word[i] = '\0';
            }
            index = 0;
        }
        else
        {
            word[index] = c;
            index++;
        }
    }
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
