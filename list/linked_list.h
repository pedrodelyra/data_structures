#ifndef LIST_H
#define LIST_H

typedef struct _node {
	int data;
	struct _node* next;
} node;

typedef struct _list {
	int size;
	node* head;
} linked_list;

linked_list* create_list(void);

void add_node(linked_list * const list, const int data);

void remove_node(linked_list * const list, const int data);

void print_list(linked_list * const list);

#endif
