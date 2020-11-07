#include <stdlib.h>

typedef struct node* Pqueue;

/*
/   NewPq()->Pqueue
/   pre:
/   post: nil
/   crea una nuova priority queue
*/
Pqueue newPq();

/*
/   emptyPq()->bool
/   pre:
/   post:se q = NULL restituisce 1 altrimenti 0
*/
int emptyPq(Pqueue q);

/*
/   getMax()->item
/   pre: p!=NULL
/   post:   elem è la entry con la massima priorità fra quelle contenute in Pq
*/
int getMax(Pqueue q);

/*
/   deleteMax()->item
/   pre:    p!=NULL
/   post:   p' contiene tutte le entry di p tranne quella con amssima priorità
/   crea una nuova Pq senza l'elento Max
*/
int deleteMax(Pqueue q);

/*
/   insertPq()->Pqueue
/   pre:
/   post:   p' contiene e e tutte le entry di p
/   aggiunge una nuova Pq
*/
int insertPq(Pqueue q,int e);

int ConsPq(Pqueue q);

int StampPq(Pqueue q);

int getMin(Pqueue q);

int sostituisciElemento(Pqueue q,int newe,int e);

Pqueue mergePq(Pqueue q1,Pqueue q2);