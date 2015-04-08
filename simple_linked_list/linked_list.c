#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int data;
	struct _node* next;
} node;

typedef struct _list {
	int size;
	node* head;
} linked_list;

linked_list* create_list(void) {
	linked_list* new_list = malloc(sizeof(linked_list));
	new_list->head = NULL;
	new_list->size = 0;
	return new_list;
}

void add_node(linked_list * const list, const int data) {
	node* new_node = malloc(sizeof(node));
	new_node->data = data;
	new_node->next = list->head;
	list->head = new_node;
	list->size++;
	printf("Element added successfully!\n\n");
}

void remove_node(linked_list * const list, const int data) {
	if(list->head != NULL) {
		node* node_ptr = list->head;
		while(node_ptr->next != NULL) {
			if(node_ptr->next->data == data) {
				node* removed_node = node_ptr->next;
				node_ptr->next = node_ptr->next->next;
				list->size--;
				free(removed_node);
				printf("Element removed successfully!\n\n");
				return;
			}
			node_ptr = node_ptr->next;
		}
		printf("Element does not exist!\n\n");
	} else {
		printf("The list is empty!\n\n");
	}
}

void print_list(const linked_list * const list) {
	node* node_ptr = list->head;
	printf("List\n[");
	if(list->size > 0) {
		while(node_ptr->next != NULL) {
			printf("%d, ", node_ptr->data);
			node_ptr = node_ptr->next;
		}
		printf("%d]\n", node_ptr->data);
	} else {
			printf("] => empty list\n");
	}	
}

void free_resources(linked_list *list) {
	node* node_ptr = list->head;
	if(list->size > 0) {
		while(node_ptr != NULL) {
			node* removed_node = node_ptr;
			node_ptr = node_ptr->next;
			free(removed_node);
		}
	}
	free(list);
}

