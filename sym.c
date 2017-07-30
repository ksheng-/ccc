#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sym.h"

void insert_entry(scope_stack *stack, scope *s, int ns, char *name, astnode *node)
{
    if (s == 0)
    {
        s = stack->back;
    }
    /* fprintf(stderr, "Installing '%s' into symbol table in scope %d miniscope %d\n", name, s, ns); */
    
    symrec *newnode = (symrec *) malloc(sizeof(symrec));
    strcpy(newnode->name, name);
    newnode->data = node;
    newnode->next = NULL;

    symrec *head; 
    switch (ns)
    {
        case NS_DEFAULT:
            if ((head = s->sym_table) == NULL)
            {
                s->sym_table = newnode;
                return;
            }
            break;
        case NS_TAG:
            if ((head = s->sym_table_tags) == NULL)
            {
                s->sym_table_tags = newnode;
                return;
            }
            break;
        case NS_LABEL:
            if ((head = s->sym_table_labels) == NULL)
            {
                s->sym_table_labels = newnode;
                return;
            }
            break;
        case NS_MEMBER:
            if ((head = s->sym_table_members) == NULL)
            {
                s->sym_table_members = newnode;
                return;
            }
            break;
    }
    
    symrec *tmp = head;
    symrec *last = head;
    while (tmp != NULL)
    {
        if (strcmp(tmp->name, name) == 0)
        {
            char msg[128];
            sprintf(msg, "Conflicting definition for symbol '%s'.", name);
            yyerror(msg); 
            return;
        }
        last = tmp;
        tmp = tmp->next;
    }
    last->next = newnode;
}

symrec *find_entry(scope_stack *stack, scope *s, int ns, char *name)
{
    if (s == 0)
    {
        s = stack->back;
    }

    symrec *head;
    switch (ns)
    {
        case NS_DEFAULT:
            head = s->sym_table;
            break;
        case NS_TAG:
            head = s->sym_table_tags;
            break;
        case NS_LABEL:
            head = s->sym_table_labels;
            break;
        case NS_MEMBER:
            head = s->sym_table_members;
            break;
    }
    
    symrec *curr = head;

    if (head == NULL)
    {
        return 0;
    }
    while (curr != 0 && strcmp(curr->name, name) != 0)
    {
        curr = curr->next; 
    }
    return curr;
}

void delete_table(symrec *head)
{
    symrec *curr = head;
    if (head == NULL)
    {
        return;
    }

    symrec *tmp;
    while (curr->next != NULL)
    {
        tmp = curr;
        curr = curr->next;
        free(curr);
    }
}


void print_table(scope *s)
{
    switch (s->scope_type)
    {
        case SCOPE_FILE:
            fprintf(stderr, "[File Scope]\nnamespace | symbol\n");
            break;
        case SCOPE_BLOCK:
            fprintf(stderr, "[Block Scope]\nnamespace | symbol\n");
            break;
        case SCOPE_FUNCTION:
            fprintf(stderr, "[Function Scope]\nnamespace | symbol\n");
            break;
        case SCOPE_PROTOTYPE:
            fprintf(stderr, "[Prototype Scope]\nnamespace | symbol\n");
            break;
    }

    symrec *curr;
    if ((curr = s->sym_table) != NULL)
    {
        while (curr != NULL)
        {
            fprintf(stderr, "(default)   %s\n", curr->name);
            curr = curr->next;
        }
    }
    
    if ((curr = s->sym_table_tags) != NULL)
    {
        while (curr != NULL)
        {
            fprintf(stderr, "(tags)      %s\n", curr->name);
            curr = curr->next;
        }
    }
    
    if ((curr = s->sym_table_members) != NULL)
    {
        while (curr != NULL)
        {
            fprintf(stderr, "(members)   %s\n", curr->name);
            curr = curr->next;
        }
    }
    
    if ((curr = s->sym_table_labels) != NULL)
    {
        while (curr != NULL)
        {
            fprintf(stderr, "(labels)    %s\n", curr->name);
            curr = curr->next;
        }
    }
}

void push_scope(scope_stack *stack, int scope_type)
{
    fprintf(stderr, "Scope pushed.\n");
    scope *tmp = stack->front;
    scope *newscope = (scope *) malloc(sizeof(scope));
    
    newscope->scope_type = scope_type;
    
    newscope->sym_table;
    newscope->sym_table_tags;
    newscope->sym_table_labels;
    newscope->sym_table_members;
    
    newscope->next = NULL;

    if (stack->front == NULL)
    {
        stack->front = newscope;
    }
    else
    {
        stack->back->next = newscope;
        newscope->prev = stack->back;
    }

    stack->back = newscope;
}

scope *pop_scope(scope_stack *stack)
{
    fprintf(stderr, "Scope popped.\n");
    if (stack->front == NULL)
    {
        fprintf(stderr, "Can't pop scope, stack is empty.");
        return NULL;
    }

    scope *retval = stack->back;
    scope *tmp = stack->back;

    if (stack->front->next == NULL)
    {
        stack->front = NULL;
    }
    else
    {
        stack->back->prev->next = NULL;
    }

    stack->back = stack->back->prev;

    delete_table(tmp->sym_table);
    delete_table(tmp->sym_table_tags);
    delete_table(tmp->sym_table_labels);
    delete_table(tmp->sym_table_members);
    free(tmp);
    return retval;
}

void print_all_tables(scope_stack *stack)
{
    fprintf(stderr, "-- PRINTING SYMBOL TABLES --\n");
    scope *curr = stack->front;

    while (curr != NULL)
    {
        print_table(curr);
        curr = curr->next;
    }
    
}

void insert_sym(scope_stack *stack, int ns, char *name, astnode *node);

astnode *find_sym(scope_stack *stack, int ns, char *name)
{
    scope *curr = stack->front;
    symrec *entry;
    while (curr != NULL)
    {
        if ((entry = find_entry(stack, curr, ns, name)) != 0);
        {
            if (entry)
                return entry->data; 
        }
        curr = curr->next;
    }

    return 0;
}

