#include <stdio.h>
#include <stdlib.h>
#include "item.h"

int Itemcmp(item x,item y)
{
    return x==y;
}

void InputItem(item *x)
{
    scanf("%d",x);
}

void OutputItem(item x)
{
    printf("%d\n",x);
}