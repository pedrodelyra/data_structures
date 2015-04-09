#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int data;
	struct _node *next;
	struct _node *previous;
} node;

typedef struct _list {
	int size;
	node *head;
	node *tail;
} circular_doubly_linked_list;

/*
	Cria e inicializa uma lista encadeada.
*/
circular_doubly_linked_list *create_list(void) {
	circular_doubly_linked_list* new_list = malloc(sizeof(circular_doubly_linked_list));
	new_list->size = 0;
	new_list->head = NULL;
	new_list->tail = NULL;
	return new_list;
}

/*
	Insere um dado na lista circular. Recebe como argumentos a lista e o dado a ser inserido. Lista orientada da head para o tail.
*/
void add_node(circular_doubly_linked_list * const list, const int data) {
	node* new_node = malloc(sizeof(node));
	new_node->data = data;
	
	// lista vazia
	if(!list->head) {
		list->head = list->tail = new_node;
		list->head->next = list->head->previous = list->head;
	} else {
		// lista com um ou mais elementos
		new_node->previous = list->tail;
		list->tail = new_node;
		new_node->next = list->head;
		new_node->previous->next = new_node;
		list->head->previous = new_node;
	}

 	printf("Element added successfully!\n\n");
		
	list->size++;
}

void remove_node(circular_doubly_linked_list * const list, const int data) {
	if(list->size > 0) {
		// caso em que a lista possui um único elemento
		if(list->head == list->tail) {
			if(list->head->data == data) {
				free(list->head);
				list->head = NULL;
				list->tail = NULL;
				printf("Element removed succesfully\n");
				list->size--;
				return;
			}
			printf("Element does not exist!\n");
		} else {
			// caso em que a lista possui múltiplos elementos
			node* node_ptr = list->head;

			do {
				// elemento encontrado
				if(node_ptr->data == data) {
					// caso em que o elemento é a cabeça
					if(node_ptr == list->head) {
						node_ptr->next->previous = list->tail;
						list->head = node_ptr->next;
						list->tail->next = list->head;
						free(node_ptr);
					// caso em que o elemento é o rabo
					} else if(node_ptr == list->tail) {
						node_ptr->previous->next = list->head;
						list->tail = node_ptr->previous;
						list->head->previous = list->tail;
						free(node_ptr);
					}	else {
						node_ptr->next->previous = node_ptr->previous;
						node_ptr->previous->next = node_ptr->next;
						free(node_ptr);
					}
					printf("Element removed succesfully\n");
					list->size--;
					return;
				}
				node_ptr = node_ptr->next;
			} while(node_ptr != list->head);
			printf("Element does not exist!\n");
		}
	}	else {
		printf("The list is empty!\n");
	}
}

/*
	Exibe os elementos que constituem a lista. Recebe a lista como primeiro argumento e um argumento que especifica se a lista deve ser exibida na ordem original (0) ou na ordem inversa (!= 0)
*/
void display_list(const circular_doubly_linked_list * const list, int displaying_order) {
	node* node_ptr = (!displaying_order) ? list->head : list->tail;
	void original_order(node **);
	void reverse_order(node **);
	void (*displaying_mode[])(node **) = {original_order, reverse_order};
	
	displaying_order = displaying_order != 0;

	printf("List\n[");

	if(list->size > 0) {
		
		(*displaying_mode[displaying_order])(&node_ptr);

		printf("%d]\n", node_ptr->data);
	} else {
		printf("] => empty list\n");
	}	
}


/*
	Libera a memória utilizada pela lista
*/
void free_resources(circular_doubly_linked_list *list) {
	node* node_ptr = list->head;
	if(list->size > 0) {
		while(node_ptr) {
			node* removed_node = node_ptr;
			node_ptr = node_ptr->next;
			free(removed_node);
		}
	}
	free(list);
}

/*
	Define a lógica de exibição dos elementos na ordem original
*/
void original_order(node **node_ptr) {
	node* head = *node_ptr;
	while((*node_ptr)->next != head) {
		printf("%d, ", (*node_ptr)->data);
		*node_ptr = (*node_ptr)->next;
	}
	
}

/*
	Define a lógica de exibição dos elementos na ordem inversa
*/
void reverse_order(node **node_ptr) {
	node* tail = *node_ptr;
	while((*node_ptr)->previous != tail) {
		printf("%d, ", (*node_ptr)->data);
		*node_ptr = (*node_ptr)->previous;
	}
}

