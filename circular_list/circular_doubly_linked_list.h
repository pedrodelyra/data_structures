typedef struct _node {
	int data;
	struct _node* next;
} node;

typedef struct _list {
	int size;
	node* head;
} circular_doubly_linked_list;

circular_doubly_linked_list* create_list(void);

void add_node(circular_doubly_linked_list * const list, const int data);

void remove_node(circular_doubly_linked_list * const list, const int data);

void print_list(circular_doubly_linked_list * const list);

void free_resources(circular_doubly_linked_list *list);
