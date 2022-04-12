typedef struct node_t
{
    int key;
} node_t;

typedef struct result_t
{
    int *result_array;
    int tam;
} result_t;

int h1(int k);

int h2(int k);

void init_ht(node_t **hash_table);

void print_ht(node_t **hash_table);

void insert_node(node_t **hash_table, node_t **hash_table_2, int key);

void remove_node(node_t **hash_table, node_t **hash_table_2, int key);

int node_lookup(node_t **hash_table, node_t **hash_table_2, int key);

result_t *get_result(node_t **hash_table, node_t **hash_table_2);
