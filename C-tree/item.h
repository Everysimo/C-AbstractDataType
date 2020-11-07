#ifndef ITEM_H
#define ITEM_H
typedef int item;
#endif

#define NULLITEM 0

int eq(item x, item y);
void input_item(item *x); 
void output_item(item x);
int input_item_f(FILE* f,item *x);
