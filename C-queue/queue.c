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
        q->head=q1;
    else
        q->tail->next=q1;
    
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

int stampaCoda(queue q)
{
    item tmp;
    int tmpsize=q->size ,i=0;
    while (i<tmpsize)
    {
        tmp=q->head->value;
        OutputItem(tmp);
        enqueue(q,tmp);
        dequeue(q);
        i++;
        if(q->head==NULL)
            return 1;
    }

}

queue mergeQueue(queue q1,queue q2)
{
    queue qnew=newQueue();
    int size1=q1->size,size2=q2->size;
    item tmp;
    qnew=q1;

    for(int i=0;i<size1;i++)
    {
        tmp=q1->head->value;
        enqueue(qnew,tmp);
        dequeue(q1);
    }

    for(int i=0;i<size2;i++)
    {
        tmp=q2->head->value;
        enqueue(qnew,tmp);
        dequeue(q2);
    }
    return qnew;
}