#ifndef SYM_H
#define SYM_H

#include "ast.h"

extern void yyerror(const char *s);

enum scope_types
{
    SCOPE_FILE,
    SCOPE_BLOCK,
    SCOPE_FUNCTION,
    SCOPE_PROTOTYPE,
};

enum namespaces
{   
    NS_DEFAULT,
    NS_TAG,
    NS_LABEL,
    NS_MEMBER
};

// Symbol table is a linked list of AST nodes
struct symrec
{
    char name[32];
    astnode *data;
    struct symrec *next;
};
typedef struct symrec symrec;

struct scope
{
    int scope_type;
    
    symrec *sym_table;
    // Namespaces / mini-scopes
    symrec *sym_table_tags;
    symrec *sym_table_labels;
    symrec *sym_table_members;
    
    // Scope stack pointers
    struct scope *next;
    struct scope *prev;
};
typedef struct scope scope;

struct scope_stack
{
    scope *front;
    scope *back;
};
typedef struct scope_stack scope_stack;

// Helper function to add/remove AST nodes
void insert_entry(scope_stack *stack, scope *s, int ns, char *name, astnode *node);
symrec *find_entry(scope_stack *stack, scope *s, int ns, char *name);
void delete_table(symrec *head);
void print_table(scope *s);

// Scope/symbol table interface
void push_scope(scope_stack *stack, int scope_type);
scope *pop_scope(scope_stack *stack);

// Search whole scope stack
void insert_sym(scope_stack *stack, int ns, char* name, astnode *node);
astnode *find_sym(scope_stack *stack, int ns, char *name);

void print_all_tables(scope_stack *stack);

#endif
