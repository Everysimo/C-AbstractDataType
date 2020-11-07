#include "item.h"
#include "list.h"

typedef struct c_stack *stack;

stack newStack();

int emptyStack(stack s);

int push(stack s,item e);

int pop(stack s);

item top(stack s);

int stampStack(stack s);

stack reverseStack(stack s);

stack mergeStack(stack s1,stack s2);

stack convBin(int n);


