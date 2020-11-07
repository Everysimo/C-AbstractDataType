#include <stdio.h>
#include "item.h"


int eq(item a, item b) {
   return a==b;
}

int minore(item a, item b) {
   return a<b;
}

int maggiore(item a, item b) {
   return a>b;
}

void input_item(item *x) {
     scanf("%d",x);
}

int input_item_f(FILE* f,item *x){
     return fscanf(f,"%d",x);
}

void output_item(item x) {
     printf("%d\n",x);
} 

