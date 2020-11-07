#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "queue.h"

struct node{
    item value;
    struct node* next;
};

struct c_queue{
    struct node *head,*tail;
    int size;
};

queue newQueue(void){
    queue q=malloc(sizeof(struct c_queue));
    if(q==NULL)
        return NULL;
    q->size=0;
    q->head=NULL;
    q->tail=NULL;

    return q;
}

int emptyQueue(queue q)
{
    if(q==NULL)
        return -1;
    return q->size==0;
}

int enqueue(queue q,item e)
{
    struct node* q1=malloc(sizeof(struct node));
    if(q1==NULL)
        return -1;
    q1->value = e;
    q1->next = NULL;
    
    if(q->head==NULL)
    {
        q->head=q1;
    }
    else
    {
        q->tail->next=q1;
    }
    
    q->tail=q1;
    q->size++;
    return 1;
}

item dequeue(queue q)
{
    if(q==NULL)
        return NULLITEM;
    item result=q->head->value;
    struct node* n1=malloc(sizeof(struct node));
    if(n1==NULL)
        return NULLITEM;
    n1=q->head;
    if(q->head->next==NULL)
    {
        q->head=NULL;
        q->tail=NULL;
        q->size=0;

        return result;
    }
    else
    {
        q->head=q->head->next;
        free(n1);
        q->size--;
        return result;
    }
}

int cancDaItem(queue q,item e)
{
    item primoel=q->head->value;

    while (q->head->value!=e)
    {
        enqueue(q,q->head->value);
        dequeue(q);
        if(q->head==NULL)
            return 1;
    }
    if(q->head->value==e)
    {
        enqueue(q,q->head->value);
        dequeue(q);
    }
    while (q->head->value!=primoel)
    {
        dequeue(q);
    }
    
    
    return 1;
}

int stampaCoda(queue q)
{
    item tmp;
    int tmpsize=q->size ,i=0;
    while (i<tmpsize)
    {
        tmp=q->head->value;
        OutputItem(tmp);
        enqueue(q,q->head->value);
        dequeue(q);
        i++;
        if(q->head==NULL)
            return 1;
    }

}