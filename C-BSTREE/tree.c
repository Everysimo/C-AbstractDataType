#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "tree.h"

struct node{
    item value;
    struct node *left;
    struct node *right;
};

item getItem(struct node *n);
void setItem(struct node *n,item el);

/*restituisce il valore condento nel nodo
*getItem(n)->item
*pre:n non vuoto
*post: item
*/
item getItem(Btree n){
    if(n==NULL)
        return NULLITEM;
    return n->value;
}

/*aggiorna il valore del nodo
*setItem(n,el)->
*pre:n non vuoto
*post: n->value=el
*/
void setItem(Btree n,item el){
    if(n==NULL)
        return;
    n->value=el;
}

/*
*   newtree:crea un nuovo albero vuoto 
*/
Btree newtree(){
    return NULL;
}

/*
*   emptytree:controlla se l'albero è vuoto
*/
int emptytree(Btree T){
    if (T==NULL)
        return 1;
    return 0;
}

/*
*   consBtree:alloca memoria per un nuovo albero  
*/
Btree consBtree(item val,Btree sx,Btree dx){
    Btree t=malloc(sizeof(struct node));
    if(emptytree(t))
        return NULL;

    t->value=val;
    t->left=sx;
    t->right=dx;

    return t;
}

/*
*   restistuisce un puntatore alla radice dell'albero
*/
struct node *getRoot(Btree T){
    if(!emptytree(T)){
        return T;
    }
    return NULL;
}

/*
*   restistuisce il figlio sinisto di T
*/
Btree figliosx(Btree T){
    if(!emptytree(T))
        return T->left;
    return NULL;
}

/*
*   restistuisce il figlio destro di T
*/
Btree figliodx(Btree T){
    if(!emptytree(T))
        return T->right;
    return NULL;
}

/*
*   ti fa inserire un elemento nell'albero
*/
 Btree inputTree(FILE *fp){
    Btree t1,t2;
    item el;
    if(input_item_f(fp,&el)!=1)
        return newtree();
    if(el==NULLITEM)
        return newtree();

    printf("costruisco il sottoalbero sx:\n");
    t1=inputTree(fp);
    printf("costruisco il sottoalbero dx:\n");
    t2=inputTree(fp);
    return consBtree(el,t1,t2);
}

Btree insertItem(Btree t,item el){
    if(emptytree(t))
        return consBtree(el,figliosx(t),figliodx(t));

    if(eq(el,getItem(t)))
        return ;

    if(minore(el,getItem(t))){
        t->left=insertItem(figliosx(t),el);
    }

    if(maggiore(el,getItem(t))){
        t->right=insertItem(figliosx(t),el);
    }
    return t;
}

Btree deleteItem(Btree t,item el){
    if(emptytree(t))
        return t;
    if(minore(el,getItem(t)))
        t->left=deleteItem(figliosx(t),el);
    if(maggiore(el,getItem(t)))
        t->right=deleteItem(figliosx(t),el);

    if(t->left==NULL){
        Btree temp =t->right;
        free(t);
        return temp;
    }
    else if(t->right==NULL){
        Btree temp =t->left;
        free(t);
        return temp;
    }
    struct node* temp = minValue(t->right);
    t->value = temp->value;
    t->right = deleteItem(t->right, temp->value);
}

struct node * minValue(struct node* node)
{
    struct node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

void inorder(Btree t){
    if(emptytree(t)) return;
    inorder(figliosx(t));
    output_item(getItem(getRoot(t)));
    inorder(figliodx(t));
}

int leafcounter(Btree t){
    if(emptytree(t)) 
        return 0;

    if(emptytree(figliosx(t))&&emptytree(figliodx(t)))
        return 1;
    
    return leafcounter(figliodx(t))+leafcounter(figliosx(t));
}

Btree spec_CloneBtree(Btree t){
    if(emptytree(t))
        return newtree();

    Btree t2=consBtree(getItem(getRoot(t)),spec_CloneBtree(figliodx(t)),spec_CloneBtree(figliosx(t)));
    return t2;
}

int contains(Btree T, item val)
{
      if (T == NULL)  return 0;
      if (eq(val, getItem(T)))  return 1;
      if (minore(val, getItem(T)))
            return (contains(figlioSX(T), val));
      else
            return (contains(figlioDX(T), val));
}

