#include <stdio.h>
#include <stdlib.h>
#include "Pqueue.h"
#define MAXPQ 50

static void sali (Pqueue q);
static void scendi(Pqueue q);

struct node{
    int vet[MAXPQ];
    int numel;
};

Pqueue newPq(void){
    Pqueue q;
    q=malloc(sizeof(struct node));
    if(q==NULL)
        return NULL;
    q->numel=0;
    return q;
}

int emptyPq(Pqueue q){
    if(!q)
        return 1;
    return q->numel == 0;
}

int getMax(Pqueue q){
    return q->vet[1];
}

int deleteMax(Pqueue q){
    if(!q||q->numel==0)
        return 0;

    q->vet[1]=q->vet[q->numel];
    q->numel --;

    scendi(q);
    return 1;
}

static void scendi(Pqueue q){
    int temp,n,i,pos;
    n=q->numel;
    i=1;
    while(1){
        if(2*i+1<=n)
            if(q->vet[i*2]>q->vet[i*2+1])
                pos = i*2;
            else
                pos = i*2+1;
        else if(2*i<=n)
            pos = 2*i;
        else break;
        
        if (q->vet[pos] > q->vet[i])
       {
             temp = q->vet[i];
             q->vet[i] = q->vet[pos];
             q->vet[pos] = temp;
             i = pos;
       }
       else
           break;
    }
}

int insertPq (Pqueue q, int key)
{

     if (!q || q->numel==MAXPQ) return 0; // CODA PIENA 

     q->numel++;
     q->vet[q->numel] = key;   // INSERISCI IN ULTIMA POSIZIONE
     
     sali(q);     // AGGIUSTA LO HEAP RISALENDO

     return 1;
} 

static void sali (Pqueue q)
{
    int temp, pos=q->numel, i=pos/2;

    while (pos>1)
    {
                
       if (q->vet[pos] > q->vet[i])
       {
             temp = q->vet[i];
             q->vet[i] = q->vet[pos];
             q->vet[pos] = temp;
             pos = i;
             i = pos/2;
       }
       
       else
             break;
     }
}

int ConsPq(Pqueue q){
    int n,i,tmp;

    printf("quanti elementi vuoi inserire? \n");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("inserisci elemento da inserire: ");
        scanf("%d",&tmp);
        insertPq(q,tmp);
    }
    return 1;
}

int StampPq(Pqueue q){
    printf("stampa coda:\n");
    int i=1;
    int pos=q->numel;
    while (i<=pos)
    {
        printf("%d\n",q->vet[i]);
        i++;
    }
    return 1;
}

int getMin(Pqueue q){
    int i=1;
    int pos=q->numel;
    int tmp=0;
    while (i<=pos)
    {
        tmp=q->vet[i];
        i++;
    }
    return tmp;
}

int sostituisciElemento(Pqueue q,int newe,int e){
    int i=1;
    int pos=q->numel;
    int tmp=0;

    while (tmp=q->vet[i]!=e){
        if(i>pos)
            return 0;
        i++;
    }

    q->vet[i]=0;
    insertPq(q,newe);
    sali(q);
    return 1;
}

Pqueue mergePq(Pqueue q1,Pqueue q2){
    Pqueue newq=newPq();
    int i=1;
    int posq1=q1->numel;
    int posq2=q2->numel;
    int tmp=0;
    while (i<=posq1)
    {
        tmp=q1->vet[i];
        insertPq(newq,tmp);
        sali(newq);
        i++;
    }
    i=1;
    tmp=0;
    while (i<=posq2)
    {
        tmp=q2->vet[i];
        insertPq(newq,tmp);
        sali(newq);
        i++;
    }
    scendi(newq);
    return newq;
}