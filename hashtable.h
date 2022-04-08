typedef struct node_t
{
    int key;
} node_t;

int h1(int k);

int h2(int k);

void init_ht(node_t **hash_table);

void print_ht(node_t **hash_table);

void insert_node(node_t **hash_table, node_t **hash_table_2, int key);

void remove_node(int key);

int lookup(int key);
