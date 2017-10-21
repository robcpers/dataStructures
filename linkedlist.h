#ifndef	LINKEDLIST
#define LINKEDLIST


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


typedef struct listStruct{
	int val;
	struct listStruct *next;
	struct listStruct *prev;
}list;


list *	allocNode(int val);
list *	addNode(list **root, int val);
list *	searchList(list *root, int val);
void	deleteNode(list **root, int val);
void	printList(list *root);
void	freeList(list *root);


#endif
