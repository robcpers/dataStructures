#include "stack.h"

stackS * createStack(){
	stackS *stack = malloc(sizeof(stackS));
	stack -> root = NULL;
	stack -> top = NULL;
	stack -> size = 0;

	return stack;
}



void	pushStack(stackS *stack, int val){
	stack-> top = addNode(&(stack->root), val);
	stack -> size ++;

	return;
}


int	popStack(stackS *stack){
	if(stack -> size == 0){
		return 0;
	}
	else if(stack -> size == 1){
		free(stack -> top);
		stack -> top = NULL;
		stack -> root = NULL;
		stack -> size = 0;

		return 1;
	}

	stack -> top = stack -> top -> prev;
	free(stack -> top -> next);
	stack -> top -> next = NULL;
	stack -> size --;

	return 1;
}


int	topStack(stackS *stack){
	if(stack -> size == 0){
		return -1;
	}
	return stack -> top -> val;
}


int	emptyStack(stackS *stack){
	if(stack -> size == 0){
		return 1;
	}

	return 0;
}


void	printStack(stackS *stack){
	printList(stack -> root);

	return;
}


void	freeStack(stackS *stack){
	freeList(stack -> root);
	free(stack);
}

