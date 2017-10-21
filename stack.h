#ifndef STACK
#define STACK




#include "linkedlist.h"


typedef	struct stackStruct{
	list *root;
	list *top;
	int size;
}stackS;


stackS * createStack();
void	pushStack(stackS *stack, int val);
int	popStack(stackS *stack);
int	topStack(stackS *stack);
int	emptyStack(stackS *stack);
void	printStack(stackS *stack);
void	freeStack(stackS *stack);



#endif
