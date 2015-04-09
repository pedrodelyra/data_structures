typedef struct _node {
	int data;
	struct _node *next;
	struct _node *previous;
} node;

typedef struct _list {
	int size;
	node *head;
	node *tail;
} double_linked_list;

double_linked_list *create_list(void);

void add_node(double_linked_list * const list, const int data);

void remove_node(double_linked_list * const list, const int data);

void display_list(const double_linked_list * const list, int displaying_order);

void free_resources(double_linked_list * const list);

