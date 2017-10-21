#include "linkedlist.h"



list *	allocNode(int val){
	list *node = malloc(sizeof(list));
	node -> next = NULL;
	node -> prev = NULL;
	node -> val = val;

	return node;
}



list *	addNode(list **root, int val){
	list *temp = *root;
	if(*root == NULL){
		*root = allocNode(val);
		return (*root);
	}
	else{
		while(temp -> next != NULL){
			temp = temp -> next;
		}

		temp -> next = allocNode(val);
		temp -> next -> prev = temp;
	}

	return temp->next;

}



list *	searchList(list *root, int val){
	if(root == NULL){
		return NULL;
	}
	else{
		while(root != NULL){
			if(root -> val == val){
				return root;
			}
			root = root -> next;
		}
	}

	return NULL;
}



void	deleteNode(list **root, int val){
	// deleting root
	if((*root)-> val == val){
		(*root) = (*root) -> next;
		free((*root) -> prev);
		(*root) -> prev = NULL;
	}
	else{
		// find it
		list *temp = searchList(*root, val);
		if(temp){
			temp -> prev -> next = temp -> next;
			if(temp -> next){
				temp -> next -> prev = temp -> prev;
			}
			free(temp);
		}
	}

	return;

}

void	printList(list *root){
	if(root == NULL){
		return;
	}
	printf("%d\n", root -> val);

	while(root -> next != NULL){
		root = root -> next;
		printf("%d\n", root -> val);
	}

	return;
}



void	freeList(list *root){
	if(root == NULL){
		return;
	}
	list *prev = root;

	while(root -> next != NULL){
		root = root -> next;
		free(prev);
		prev = root;
	}
	free(root);

	return;

}
