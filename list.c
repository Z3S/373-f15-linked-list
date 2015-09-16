#include <assert.h>
#include <stdlib.h>

#include "list.h"

// Takes a valid, sorted list starting at `head` and adds the element
// `new_element` to the list. The list is sorted based on the value of the
// `index` member in ascending order. Returns a pointer to the head of the list
// after the insertion of the new element.
list_t* insert_sorted(list_t* head, list_t* new_element) {
	assert(head != NULL);
	assert(new_element != NULL);
	struct list_t * current_pointer = head;
	struct list_t * last_pointer;

	if(new_element->index < current_pointer->index){
		new_element->next = head;
		head = new_element;
	} else {
		while((current_pointer != NULL) && (new_element->index > current_pointer->index)) {
			last_pointer = current_pointer;
			current_pointer = current_pointer->next;
			if((current_pointer == NULL) || (new_element->index < current_pointer->index)) {
				new_element->next = current_pointer;
				last_pointer->next = new_element;
			}
		}
	}

	return head;
}

// Reverses the order of the list starting at `head` and returns a pointer to
// the resulting list. You do not need to preserve the original list.
list_t* reverse(list_t* head) {
	assert(head != NULL);

	return head;
}

