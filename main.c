#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"

#define m 11

int main()
{
    char op[1];
    int key;

    node_t *hash_table[m];
    node_t *hash_table_2[m];

    init_ht(hash_table);
    init_ht(hash_table_2);

    printf("table1:\n");
    print_ht(hash_table);
    printf("table2:\n");
    print_ht(hash_table_2);

    do
    {
        scanf("%s", op);
        switch (op[0])
        {
        case 'q':
            exit(0);
        case 'i':
            scanf("%d\n", &key);
            printf("insert %d\n", key);
            insert_node(hash_table, hash_table_2, key);
            break;
        case 'r':
            scanf("%d\n", &key);
            printf("delete %d\n", key);
            remove_node(hash_table, hash_table_2, key);
            break;
        default:
            break;
        }
    } while (!feof(stdin));

    printf("\nafter ops:\n");
    printf("table1:\n");
    print_ht(hash_table);
    printf("table2:\n");
    print_ht(hash_table_2);

    return 0;
}