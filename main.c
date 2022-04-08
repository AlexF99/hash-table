#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"

#define LENGTH 1024
#define m 11

int main()
{
    char op[1];
    char line[LENGTH];
    int chave;

    node_t *hash_table[m];

    scanf("%s", op);
    if (op[0] == 'q')
        exit(0);

    scanf("%d", &chave);

    while (fgets(line, 1024, stdin) != NULL)
    {
        scanf("%s", op);
        switch (op[0])
        {
        case 'q':
            exit(0);
        case 'i':
            scanf("%d", &chave);
            insert_node(chave);
            break;
        case 'r':
            scanf("%d", &chave);
            // exclui nodo
            break;
        default:
            break;
        }
    }
    return 0;
}