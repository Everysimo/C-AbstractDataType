#include "item.h"

typedef struct node *Btree;


/*newtree()->Btree
*pre:
*post: si alloca memoria per una nuova struttura ad albero
*/
Btree newtree(void);

/*emptytree(T)->bool
*pre:
*post: se T non ha elementi ritorna 1 altrimenti 0
*/
int emptytree(Btree T);

/*getRoot()->struct node
*pre: T non vuoto
*post: restituisce un puntatore alla radice dell'albero
*/
struct node *getRoot(Btree T);

/*consBtree(val,Tsx,Tdx)->Btree
*pre:T non vuoto
*post:construisce un figlio dell'albero e i sui succesivi figli dx e sx vuoti
*/
Btree consBtree(item val,Btree sx,Btree dx);

/*figliosx(T)->Btree
*pre:T non vuoto
*post; se T non è vuoto ritorna il figlio sinisto di T 
*/
Btree figliosx(Btree T);

/*figliodx(T)->Btree
*pre:T non vuoto
*post; se T non è vuoto ritorna il figlio destro di T 
*/
Btree figliodx(Btree T);

Btree inputTree(FILE *fp);

void inorder(Btree t);

int leafcounter(Btree t);

Btree spec_CloneBtree(Btree t);