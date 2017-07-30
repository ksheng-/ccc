#ifndef LIST_H
#define LIST_H

/* Simple doubly linked list implementation that can be used as stack or queue*/

struct listnode
{
    void *data;
    struct listnode *next;
    struct listnode *prev;
};
typedef struct listnode listnode;

struct list
{
    listnode *head;
    listnode *tail;
};
typedef struct list list;


void append(list *l, void *data);
void *popleft(list *l);
void *popright(list *l);

#endif
