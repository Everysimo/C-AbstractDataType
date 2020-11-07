#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"
#include "item.h"
#include "stack.h"

struct c_stack
{
    list top;
};

stack newStack(void)
{
    stack s;
    s = malloc(sizeof(struct c_stack));
    if(s==NULL)
    {
        return NULL;
    }
    s->top=newList();
    return s;
}

int emptyStack(stack s)
{
    return emptyList(s->top);
}

int push(stack s,item e)
{
    return insertList(s->top,0,e);
}

int pop(stack s)
{
    return removeList(s->top,0);
}

item top(stack s)
{
    return getItem(s->top,0);
}

int stampStack(stack s)
{
    while (!emptyStack(s))
    {
        output_item(top(s));
        pop(s);
    }
}

stack reverseStack(stack s)
{
    stack s_reverse=newStack();
    stack tmpS=newStack();
    item tmp;
    if(s_reverse==NULL)
        return NULL;

    while (!emptyStack(s))
    {
        tmp=top(s);
        push(tmpS,tmp);
        push(s_reverse,tmp);
        pop(s);
    }
    while (!emptyStack(tmpS))
    {
        tmp=top(tmpS);
        push(s,tmp);
        pop(tmpS);
    }
    return s_reverse;
}

stack mergeStack(stack s1,stack s2)
{
    stack s_merged=newStack();
    item tmp;
    while (!emptyStack(s1))
    {
        tmp=top(s1);
        push(s_merged,tmp);
        pop(s1);
    }
    while (!emptyStack(s2))
    {
        tmp=top(s2);
        push(s_merged,tmp);
        pop(s2);
    }
    return s_merged;
}

stack convBin(int n)
{
    item tmp;
    stack bin=newStack();

    while (n!=0)
    {
        tmp=n%2;
        n=n/2;
        push(bin,tmp);
    }
    return bin;
}

item RisEspPostFissa(char* espr)
{
    int i=0;
    stack espressione=newStack();
    item c;

    while (c=sscanf(espr,"%.2f")!="\0")
    {
        push(espressione,c);
    }
    
}