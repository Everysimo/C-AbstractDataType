#if !defined(LIST_H)
#define LIST_H
#include "item.h"

typedef struct c_list *list;

//controllare se non è NULL
list newList(void);

int emptyList(list l);

int sizeList (list l);

//controllare se non è NULLITEM
item getItem (list l, int pos); 

//se è -1 item non trovato
int posItem (list l,item val);

//restituisce 0 se falisce
int insertList(list l, int pos,item val);

//ritorna 0 se falisce
int removeList(list l, int pos);

//controllare se non è NULL
list reverseList(list l);

//restituisce 0 se falisce
int deleteList(list l); 

//controllare se non è NULL
list cloneList(list l);

//restituisce 0 se falisce
int outputList (list l);

list inputList (int n);

#endif // LIST_H


