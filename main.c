#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"

#define m 11

int cmpfunc(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    char op[1];
    int key;

    result_t *result;
    lookup_t *lookup;

    node_t *hash_table[m];
    node_t *hash_table_2[m];

    init_ht(hash_table);
    init_ht(hash_table_2);

    do
    {
        scanf("%s", op);
        switch (op[0])
        {
        case 'q':
            exit(0);
        case 'i':
            scanf("%d\n", &key);
            insert_node(hash_table, hash_table_2, key);
            break;
        case 'r':
            scanf("%d\n", &key);
            remove_node(hash_table, hash_table_2, key);
            break;
        default:
            break;
        }
    } while (!feof(stdin));

    result = get_result(hash_table, hash_table_2);

    qsort(result->result_array, result->tam, sizeof(int), cmpfunc);

    for (int i = 0; i < result->tam; i++) {
        lookup = node_lookup(hash_table, hash_table_2, result->result_array[i]);
        if (lookup && lookup != NULL) {
            printf("%d,T%c,%d\n", result->result_array[i], lookup->table, lookup->index);
        }
    }

    return 0;
}
