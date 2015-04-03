#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main(void) {
	linked_list* list = create_list();
	int user_option = 0;
	int input_buffer = 0;

	do {
		printf("Please, select your option\n");
		printf("1. Add a new element\t2. Remove an element\t3. Print list\t0. Exit\n");
		scanf("%d", &user_option);
		system("clear");
		switch(user_option) {
			case 0:
				printf("Bye!\n");
				exit(EXIT_SUCCESS);
			case 1:
				printf("Enter the new element: ");
				scanf("%d", &input_buffer);
				add_node(list, input_buffer);
				break;
			case 2:
				printf("Enter the element to be removed: ");
				scanf("%d", &input_buffer);
				remove_node(list, input_buffer);
				break;
			case 3:
				print_list(list);
				break;
			default:
				printf("Invalid option!\n");
		}
		getchar();
		printf("Press enter to return to the menu\n");
		getchar();
		system("clear");
	} while(user_option != 0);
	free_resources(list);
	return 0;
}
