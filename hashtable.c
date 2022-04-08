#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "hashtable.h"

#define m 11

int h1(int k)
{
    return k % m;
}

int h2(int k)
{
    return floor(m * ((k * 0.9) - floor(k * 0.9)));
}

void init_ht(node_t **hash_table)
{
    int i;
    for (i = 0; i < m; i++)
        hash_table[i] = NULL;
}

void print_ht(node_t **hash_table)
{
    int i;
    for (i = 0; i < m; i++)
    {
        if (hash_table[i] != NULL)
            printf("%d:\t%d\n", i, hash_table[i]->key);
        else
            printf("%d:\t--\n", i);
    }
}

void insert_node(node_t **hash_table, node_t **hash_table_2, int key)
{
    int j;

    j = h1(key);
    if (hash_table[j] == NULL)
    {
        hash_table[j] = malloc(sizeof(node_t));
        hash_table[j]->key = key;
        return;
    }
    else
    {
        j = h2(key);
        if (hash_table_2[j] == NULL)
        {
            hash_table_2[j] = malloc(sizeof(node_t));
            hash_table_2[j]->key = key;
            return;
        }
    }
    return;
}

void remove_node(int key)
{
    return;
}

int lookup(int key)
{
    return 1;
}