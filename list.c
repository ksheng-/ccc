#include <stdio.h>
#include <stdlib.h>
#include "list.h"


void append(list *l, void *d)
{
    listnode *tmp = l->head;
    listnode *newnode = (listnode *) malloc(sizeof(listnode));
    newnode->data = d;
    newnode->next = NULL;
    
    if (l->head == NULL)
    {
        l->head = newnode;
    }
    else 
    {
        l->tail->next = newnode;
        newnode->prev = l->tail;
    }

    l->tail = newnode;
}

void *popleft(list *l)
{
    if (l->head == NULL)
    {
        fprintf(stderr, "Can't pop left, list is empty.");
        return NULL;
    }
    
    void *retval = l->head->data;
    listnode *temp = l->head;
    
    if (l->head->next == NULL)
    {
        l->tail = NULL;
    }
    else
    {
        l->head->next->prev = NULL;
    }

    l->head = l->head->next;
    free(temp);
    return retval;
}

void *popright(list *l)
{
    if (l->head == NULL)
    {
        fprintf(stderr, "Can't pop right, list is empty.");
        return NULL;
    }
    
    void *retval = l->tail->data;
    listnode *temp = l->tail;
    
    if (l->head->next == NULL)
    {
        l->head = NULL;
    }
    else
    {
        l->tail->prev->next = NULL;
    }

    l->tail = l->tail->next;
    free(temp);
    return retval;
}

/* void debug_printlist(list *l) */
/* { */
    /* listnode *ptr = l->head; */
    /* while (ptr != NULL) */
    /* { */
        /* printf("%d->", * (int *) ptr->data); */
        /* ptr = ptr->next; */
    /* } */
    /* printf("\n"); */
/* } */

/* int main()  */
/* { */
    /* list l = {NULL, NULL}; */
    /* int one = 1; */
    /* int two = 2; */
    /* int three = 3; */
    /* append(&l, &one); */
    /* debug_printlist(&l); */
    /* append(&l, &two); */
    /* debug_printlist(&l); */
    /* append(&l, &three); */
    /* debug_printlist(&l); */
    /* printf("Popped %d\n", *(int*) popleft(&l)); */
    /* debug_printlist(&l); */
    /* printf("Popped %d\n", *(int*) popright(&l)); */
    /* debug_printlist(&l); */
    /* printf("Popped %d\n", *(int*) popleft(&l)); */
    /* debug_printlist(&l); */
/* } */
