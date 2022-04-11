#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "hashtable.h"

#define m 11
#define DELETED (node_t*)(0xFFFFFFFFFFFFFFFFUL)

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
        if (hash_table[i] == NULL)
            printf("%d:\t--\n", i);
        else if (hash_table[i] == DELETED)
            printf("%d:\t-DELETED-\n", i);
        else
            printf("%d:\t%d\n", i, hash_table[i]->key);
    }
}

void insert_node(node_t **hash_table, node_t **hash_table_2, int key)
{
    int j;

    j = h1(key);
    if (hash_table[j] == NULL || hash_table[j] == DELETED)
    {
        hash_table[j] = malloc(sizeof(node_t));
        hash_table[j]->key = key;
        return;
    }
    else
    {
        j = h2(key);
        if (hash_table_2[j] == NULL || hash_table_2[j] == DELETED)
        {
            hash_table_2[j] = malloc(sizeof(node_t));
            hash_table_2[j]->key = key;
            return;
        }
    }
    return;
}

void remove_node(node_t **hash_table, node_t **hash_table_2, int key)
{
    int i = h1(key);

    if (hash_table[i] == NULL)
        return;

    if (hash_table[i]->key == key)
    {
        hash_table[i] = DELETED;
        return;
    }

    i = h2(key);

    if (hash_table_2[i] != NULL && hash_table_2[i] != DELETED && hash_table_2[i]->key == key)
    {
        hash_table_2[i] = DELETED;
        return;
    }
}

int node_lookup(node_t **hash_table, node_t **hash_table_2, int key)
{
    int i = h1(key);

    if (hash_table[i] == NULL)
        return -1;

    if (hash_table[i]->key == key)
        return i;

    i = h2(key);

    if (hash_table_2[i] != NULL && hash_table_2[i] != DELETED && hash_table_2[i]->key == key)
        return i;

    return -1;
}