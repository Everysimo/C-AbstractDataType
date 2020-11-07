#include <stdio.h>
#include <stdlib.h>
#define NULLITEM 0

typedef struct punto *item;

int eq(item a, item b);
float ascissa(item p);
float ordinata(item p);
item creapunto(float x,float y);
void stampapunto(item p);
float distanza(item p1, item p2);
void OutputItem(item p);
void InputItem(float *x);
int puntosimmetrico(item p1,item p2);
