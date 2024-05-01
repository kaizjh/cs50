// Implements a dictionary's functionality

// Get some help from https://github.com/DrewStanger/pset5-speller/blob/master/dictionary.c (only in function "unsigned int hash(const char *word)")
// And, with one day, about 7-10 hours' efforts, finally, I made it. And I think "hash" should be the first function to implement, then "load" ...
// But it still not so perfect
// And I learned that hash-function is a powerful tool, if we can make a good hash function:
// "A good hash function reduces 'collisions' and has a (mostly!) even distribution across hash table 'buckets'".

#include <ctype.h>
#include "dictionary.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int TABLE_SIZE = 10000;

// Hash table
node *table[TABLE_SIZE];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int hashvalue = hash(word);
    // Function strcasecmp() is case-insensitive
    for (node *ptr = table[hashvalue]; ptr != NULL; ptr = ptr->next)
    {
        if (strcasecmp(word, ptr->word) == 0)
            return true;
    }
    return false;
}

// Hashes word to a number
// I think this function should be the first one to implement, then load( ) --Irving
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    // Hashing by word's length and ascii values
    unsigned int hashvalue = 0;
    unsigned int n = strlen(word);
    for (int i = 0; i < n; i++)
    {
        hashvalue += tolower(word[i]);
    }

    return hashvalue * n % TABLE_SIZE;
}

// Loads dictionary into memory, returning true if successful, else false
int words = 0;
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
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        table[i] = NULL;
    }

    // Read each word in the input file
    char word[LENGTH + 1];
    while(fscanf(input, "%s", word) != EOF)
    {
        // Creat a new node to store the word
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            printf("Memory allocation failed\n");
            return false;
        }
        strcpy(new_node->word, word);
        new_node->next = NULL;

        // Add new node(word) to the hashtable
        int hashvalue = hash(word);
        if (table[hashvalue] == NULL)
        {
            table[hashvalue] = new_node;
        }
        else
        {
            // Using link list if there is a "collision"
            node *ptr = table[hashvalue];
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = new_node;
        }
        // Counting the words in the memory
        words++;
    }

    fclose(input);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return words;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < TABLE_SIZE; i++)
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
