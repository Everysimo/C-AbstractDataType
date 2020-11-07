#include "item.h"

typedef struct c_queue *queue;


/*newQueue->q
*pre:
*post: q=nil(nessun elemento)
*/
queue newQueue(void);

/*emptyQueue(q)->b
*pre:
*post: se q=nil b=true altrimenti b=false
*/
int emptyQueue(queue q);

/*enqueue(q,e)->q'
*pre=
*post= se q=<an,...,a1> allora q'=<an,...,a1,e>
*      se q=nil allora q'=<e>
*/
int enqueue(queue q,item e);

/*dequeue(q)->a
*pre= q=<n,.....,a1> q!= nil e n>0
*post= q=<n,.....,a2> a=a1
*/
item dequeue(queue q);

/*cancDaItem(q,e)->q'
*pre= 
*post= se q=<a1,e,a2,...,an> allora q'=<a1,e>
*      se q=<e> allora q'=<e>;
*/
int cancDaItem(queue q,item e);

int stampaCoda(queue q);