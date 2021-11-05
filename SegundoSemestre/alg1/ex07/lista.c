#include "lista.h"

struct no {
    int id;
    char name[51];
    node *next;
    node *prev;
};

struct list {
    node *start, *end;
    int size;
};

list_t *create() {
    list_t *l;
    l = malloc(sizeof(list_t));
    assert(l != NULL);
    l->start = NULL;
    l->end = NULL;
    l->size = 0;

    return l;
}

void freeList(list_t *l) {
    if (l != NULL) {
        node *p = l->start;
        while (p != NULL) {
            l->start = p->next;
            free(p);
            p = l->start;
        }
        free(l);
    }
}


int exists(list_t *l, int x) {
    node *p = l->start;
    while (p != NULL) {
        if(p->id == x) return 1;
        p = p->next;
    }
    return -1;
}


int insert(list_t *l, int x, char name[]) {
    assert(l != NULL);
    if(exists(l, x) == 1) return -1;

    node *p = malloc(sizeof(node));
    p->id = x;
    strcpy(p->name, name);
    p->next = NULL;
    p->prev = NULL;

    node *tmp, *prev;
    tmp = l->start;
    prev = NULL;

    while (tmp != NULL && x >= tmp->id) {
        prev = tmp;
        tmp = tmp->next;
    }

    if (tmp != NULL && x == tmp->id) {
        free(p);
        return -1;
    }
    if (prev == NULL) {
        p->next = l->start;
        if (l->start != NULL)
            l->start->prev = p;
        l->start = p;
    } else {
        p->next = prev->next;
        prev->next = p;
        if (p->next != NULL)
            p->next->prev = p;
        else
            l->end = p;
        p->prev = prev;
    }
    return 1;
}

void print(list_t *l) {
    if(l->start == NULL && l->end == NULL){
        printf("VAZIA\n");
        return;
    }

    node *p = l->start;
    while (p != NULL) {
        printf("%d, %s; ", p->id, p->name);
        p = p->next;
    }
    printf("\n");
}

int removeId(list_t *l, int x) {
    if(exists(l, x) == -1) return -1;
    
    node *p = l->start;
    node *prev = NULL;

    while (p != NULL && x > p->id) {        
        prev = p;
        p = p->next;
    }

    if (prev == NULL) {
        l->start = l->start->next;
        if (l->start != NULL)
            l->start->prev = NULL;
        else
            l->end = NULL;
        free(p);
    } else {
        if (p->next == NULL) {
            l->end = p->prev;
            prev->next = NULL;
            free(p);
        } else {
            prev->next = p->next;
            p->next->prev = prev;
            free(p);
        }
    }

    return 1;
}

