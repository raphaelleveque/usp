#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int elem;
typedef struct list list_t;
typedef struct no node;

list_t *create();
void freeList(list_t *l);
int insert(list_t *l, int x, char name[]);
void print(list_t *l);
int removeId(list_t *l, elem x);