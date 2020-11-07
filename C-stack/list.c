#include <stdio.h>
#include <stdlib.h>
#include "item.h" 
#include "list.h"
static struct node* insertNode (struct node* n, int pos, item val);
static struct node* makeNode(item val, struct node* nxt);
static struct node* removeNode(struct node* n, int pos);
struct node {
    item value;
    struct node *next;
};
struct c_list {
    struct node *first;
    int size; 
};
int sizeList (list l)
{
    if(l == NULL)
	    return -1;
    return l->size;
}
list newList(void) 
{
    struct c_list *l;
    l = malloc (sizeof(struct c_list));
    if (l != NULL) {
     	l->first = NULL;
      	l->size = 0;
    }
    return l;
}
int emptyList(list l)
{
    if(l == NULL)
	    return -1;
    return (l->size == 0);
}
item getItem(list l, int pos)
{
    if(l == NULL)
	    return NULLITEM;
    if (pos<0 || pos>=l->size)
        return NULLITEM; 
    struct node *temp = l->first;
    int i = 0; 
    while (i < pos) {            
        i++;          
        temp=temp->next;     
    }  
    return temp->value;    
}
int posItem (list l, item val){
    if(l== NULL)
	    return -1;
    int pos =0;
    int found =0;     
    struct node *temp = l->first;
    while (temp!=NULL && !found)
    {          
	    if (eq(temp->value, val))     
            found = 1;
        else  
        {
            temp = temp->next;  pos++;
        }
    }
    if(!found)
      	pos = -1;
    return pos;
}
int insertList (list l, int pos, item val)
{
    if(l == NULL)
	    return 0;
    if (pos<0 || pos>l->size)
	    return 0;
    struct node* tmp = insertNode(l->first, pos, val);
    if(tmp==NULL)
	    return 0;
    l->first = tmp;
    l->size++;
    return 1;                  
}
static struct node* insertNode (struct node* nxt, int pos, item val)
{
    struct node *n1;
    if(pos == 0)                        
	    return makeNode(val, nxt);
    int i = 0;
    struct node* prec = nxt;    
    while (i < pos-1) 
    {
        prec = prec->next;      
        i++;
    }
    n1 = makeNode(val, prec->next);     
    if(n1 == NULL)
        return NULL;   
    prec->next = n1;          
    return nxt;                    
}
static struct node* makeNode(item val, struct node* nxt)
{
    struct node *nuovo = malloc (sizeof(struct node));
    if (nuovo != NULL) 
    {
     	nuovo->value = val;
      	nuovo->next = nxt;
	}
    return nuovo;
}
int removeList (list l, int pos)
{     
    if(l == NULL)
	    return 0;
    if (pos<0 || pos>=l->size)     
	    return 0;   
    l->first = removeNode(l->first, pos);
    l->size--;
    return 1;
}   
static struct node* removeNode(struct node* n, int pos)
{     
    struct node* n1;                        
    int i;
    if(pos == 0) 
    {     
        n1=n;                        
        n=n->next;
        free(n1);
    }
    else if (pos > 0)
    {
        for ( i = 0; i < pos-1; i++)
        {
            n=n->next;
        }
        n1=n->next;
        n->next=n1->next;
        free(n1);
    }
    return n;
}
list reverseList(list l) {
    list l1;    
    item val;
    struct node *temp;
    if (l == NULL)   
        return NULL;
    l1 = newList();
    if (l1 == NULL)   
        return NULL;
    temp = l->first;
    while (temp != NULL)
    {
        val = temp->value;
        if (!insertList(l1, 0, val))
        {  
            deleteList(l1);    
            return NULL;
        }
        temp = temp->next; 
    }
    return l1;
}
list cloneList (list l) 
{
    list l1;  struct node *tmp, *tmp1, *new;
    item val;
    if (l == NULL) 
        return NULL;
    if (!(l1 = newList())) 
        return NULL;
    l1->size = l->size;
    tmp = l->first;
    if (emptyList(l))  
        return l1;	
    val = tmp->value;
    tmp1 = makeNode(val, NULL);
    l1->first = tmp1;
    if (tmp1 == NULL)  
    {
        deleteList(l1);   
        return NULL;  
    }
    tmp = tmp->next;
    while (tmp != NULL)  
    {
        val = tmp->value;
        new = makeNode(val, NULL);
        if (new == NULL)  
        {
            deleteList(l1);   
            return NULL;  
        }   
        tmp1->next = new;        
        tmp = tmp->next;      tmp1 = new;            
    }
    return  l1;
}
int deleteList (list l) {
    struct node *temp;    
    struct node *temp1;
    if(l == NULL)
        return 0;
    temp = l->first;
    while (temp) 
    {
        temp1 = temp;
        temp = temp->next;
        free(temp1);
    }        
    l->first = NULL;
    l->size = 0;
    return 1;
}
int outputList (list l)
{
    int size,i;
    struct node *temp; 
    if(l==NULL)
    {
        return 0;
    }
    size=sizeList(l);
    temp=l->first;
    for ( i = 0; i < size; i++)
    {
        printf("l'item in posizione %d:\n",i);
        output_item(temp->value);
        temp=temp->next;
    }
    return i;
}
list inputList (int n)
{
    item it;
    list l=newList();
    int i;
    for ( i = 0; i < n; i++)
    {
        printf("inserisci item in posizione %d:\n",i);
        input_item(&it);
        insertList(l,i,it);
    }
    return l;
}


