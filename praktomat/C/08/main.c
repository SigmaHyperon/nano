#include <stdio.h>
#include "uebung8.h"

void traverse(struct list_head* head);

int main(){
	struct list_head *head = list_new();
	list_push(head);
	list_append(head);
	list_push(head);
	list_push(head);
	list_append(head);
	traverse(head);
	list_free(&head);
	return 0;
}

void traverse(struct list_head* head){
	if(!head){
		return;
	}
	struct list_element* element = head->front;
	while(element){
		printf("%i\n", element->value);
		element = element->next;
	}
}
