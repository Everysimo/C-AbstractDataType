#include <stdio.h>
#include <stdlib.h>
#include "item.h"

typedef struct hash* hashtable;

hashtable newHashtable(int size);
int InsertHash(hashtable h, struct item *elem);
struct item *hashDelete(hashtable h, char *key);
void DestroyHashtable(hashtable h);
static void deleteList(struct item *p);
int hashFun(char *k, int m);