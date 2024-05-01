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

int words = 0;
bool loaded = true;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    // Turn word into all-lowercase
    int n = strlen(word);
    char s[n];
    for (int i = 0; i < n; i++)
    {
        s[i] = tolower(word[i]);
    }

    int i = hash(word);
    node *ptr = table[i];
    while (strcmp(s, ptr->word) != 0)
    {
        if (ptr->next == NULL)
            return false;
        else
            ptr = ptr->next;
    }
    return true;
}

// Hashes word to a number
// I think this function should be the first one to implement, then load( ) --Irving
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int n = strlen(word)
    for (int i = 0; i < n; i++)
    {
        hashvalue += tolower(word[i]);
    }
    hashvalue = hashvalue
    return hashvalue;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // Open the input file
    FILE *input = fopen(dictionary, "r");
    if (input == NULL)
    {
        printf("Can not open the dictionary\n");
        return false;
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

            words++;
            index = 0;
        }
        else
        {
            word[index] = c;
            index++;
        }
    }

    fclose(input);
    return loaded;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if (loaded)
        return words;
    else
        return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *ptr = table[i];
        while (ptr != NULL)
        {
            table[i] = table[i]->next;
            free(ptr);
            ptr = table[i];
        }
    }
    return true;
}
