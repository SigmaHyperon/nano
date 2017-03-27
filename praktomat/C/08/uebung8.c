#include <stdio.h>
#include <stdlib.h>
#include "uebung8.h"

struct list_head* list_new(void){
	struct list_head *head = malloc(sizeof(struct list_head));
	if(!head){
		return NULL;
	}
	head->front = head->end = NULL;
	return head;
}

struct list_element* list_insert(struct list_head* head,struct list_element* element){
	if(!head){
		return NULL;
	}
	static int counter = 0;
	struct list_element *newElement = malloc(sizeof(struct list_element));
	if(!newElement){
		return NULL;
	}
	newElement->value = counter;
	counter++;
	if(element != NULL){
		newElement->next = element->next;
		element->next = newElement;
	}else{
		newElement->next = head->front;
		head->front = newElement;
	}
	if(newElement->next == NULL){
		head->end = newElement;
	}
	return newElement;
}

uint32_t list_length(struct list_head* head){
	if(!head || !head->front){
		return 0;
	}
	struct list_element *element = head->front;
	int length = 1;
	while(element->next){
		length++;
		element = element->next;
	}
	return length;
}

struct list_element* list_push(struct list_head* head){
	return list_insert(head,NULL);

}
struct list_element* list_append(struct list_head* head){
	if(!head){
		return NULL;
	}
	return list_insert(head,head->end);
}

struct list_element* list_remove(struct list_head* head,struct list_element* element){
	if(!head || !element || head->front == NULL){
		return NULL;
	}
	struct list_element *prev = head->front;
	if(head->front == element){
		head->front = element->next;
		if(head->end == element){
			head->end = NULL;
		}
		return element;
	}
	while(prev->next != element){
		prev = prev->next;
	}
	prev->next = element->next;
	if(head->end == element){
		head->end = prev;
	}
	return element;
}

struct list_element* list_pop(struct list_head* head){
	return list_remove(head, head->front);
}

struct list_element* list_get_next(struct list_head* head,struct list_element* element){
	if(!head || head->front == NULL){
		return NULL;
	}
	if(!element){
		return head->front;
	}
	return element->next;
}

void list_free(struct list_head** head){
	if(!head || !(*head)){
		return;
	}
	while((*head)->end){
		free(list_remove(*head, (*head)->end));
	}
	free(*head);
	*head = NULL;
}
