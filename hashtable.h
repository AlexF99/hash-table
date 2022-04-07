typedef struct node_t {
    int key;
    int value;
    struct node_t *next;
} node_t;

typedef struct arrayitem_t {
    node_t *head;
    node_t *tail;
} arrayitem_t;

int h1(int k);

int h2(int k);

void insert(int key, int value);
