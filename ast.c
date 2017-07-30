#include <stdio.h>
#include <stdlib.h>
#include "ast.h"
#include "ptypes.h"

void transform_typespecs(astnode *node)
{
    if (*(int *) node != AST_TYPESPECS)
    {
        fprintf(stderr, "Cannot transform non-typespec node\n");
        return;
    }
    
    /* Bitarray of set type specs, indexed by enum decl_specs */
    int typespecs = node->astnode_typespecs.type_arr;
    switch (typespecs)
    {
        case POW2(TYPE_VOID):
            node->astnode_typespecs.type_actual = SPEC_VOID;
            break;
        case POW2(TYPE_CHAR):
            node->astnode_typespecs.type_actual = SPEC_CHAR;
            break;
        case POW2(TYPE_SIGNED) + POW2(TYPE_CHAR):
            node->astnode_typespecs.type_actual = SPEC_SIGNED_CHAR;
            break;
        case POW2(TYPE_UNSIGNED) + POW2(TYPE_CHAR):
            node->astnode_typespecs.type_actual = SPEC_UNSIGNED_CHAR;
            break;
        case POW2(TYPE_SHORT):
        case POW2(TYPE_SIGNED) + POW2(TYPE_SHORT):
        case POW2(TYPE_SHORT) + POW2(TYPE_INT):
        case POW2(TYPE_SIGNED) + POW2(TYPE_SHORT) + POW2(TYPE_INT):
            node->astnode_typespecs.type_actual = SPEC_SIGNED_SHORT;
            break;
        case POW2(TYPE_UNSIGNED) + POW2(TYPE_SHORT):
        case POW2(TYPE_UNSIGNED) + POW2(TYPE_SHORT) + POW2(TYPE_INT):
            node->astnode_typespecs.type_actual = SPEC_UNSIGNED_SHORT;
            break;
        case POW2(TYPE_INT):
        case POW2(TYPE_SIGNED):
        case POW2(TYPE_SIGNED) + POW2(TYPE_INT):
            node->astnode_typespecs.type_actual = SPEC_SIGNED_INT;
            break;
        case POW2(TYPE_UNSIGNED):
        case POW2(TYPE_UNSIGNED) + POW2(TYPE_INT):
            node->astnode_typespecs.type_actual = SPEC_UNSIGNED_INT;
            break;
        case POW2(TYPE_LONG):
        case POW2(TYPE_SIGNED) + POW2(TYPE_LONG):
        case POW2(TYPE_LONG) + POW2(TYPE_INT):
        case POW2(TYPE_SIGNED) + POW2(TYPE_LONG) + POW2(TYPE_INT):
            node->astnode_typespecs.type_actual = SPEC_SIGNED_LONG;
            break;
        case POW2(TYPE_UNSIGNED) + POW2(TYPE_LONG):
        case POW2(TYPE_UNSIGNED) + POW2(TYPE_LONG) + POW2(TYPE_INT):
            node->astnode_typespecs.type_actual = SPEC_UNSIGNED_LONG;
            break;
        case POW2(TYPE_LONGLONG):
        case POW2(TYPE_SIGNED) + POW2(TYPE_LONGLONG):
        case POW2(TYPE_LONGLONG) + POW2(TYPE_INT):
        case POW2(TYPE_SIGNED) + POW2(TYPE_LONGLONG) + POW2(TYPE_INT):
            node->astnode_typespecs.type_actual = SPEC_SIGNED_LONGLONG;
            break;
        case POW2(TYPE_UNSIGNED) + POW2(TYPE_LONGLONG):
        case POW2(TYPE_UNSIGNED) + POW2(TYPE_LONGLONG) + POW2(TYPE_INT):
            node->astnode_typespecs.type_actual = SPEC_UNSIGNED_LONGLONG;
            break;
        case POW2(TYPE_FLOAT):
            node->astnode_typespecs.type_actual = SPEC_FLOAT;
            break;
        case POW2(TYPE_DOUBLE):
            node->astnode_typespecs.type_actual = SPEC_DOUBLE;
            break;
        case POW2(TYPE_LONG) + POW2(TYPE_DOUBLE):
            node->astnode_typespecs.type_actual = SPEC_LONG_DOUBLE;
            break;
        default:
            fprintf(stderr, "Not a valid combination of type specifiers.\n");
    }

}

astnode *new_astnode(int type)
{
    astnode *node = (astnode *) malloc(sizeof(astnode));
    *(int *) node = type;
    return node;
}

void insert_astnode(astnode *node, astnode *pos)
{
    astnode *tmp;

    switch (*(int *) pos)
    {
        case AST_NULL:
            tmp = pos->astnode_null.next;
            pos->astnode_null.next = node;
            break;
        case AST_IDENT:
            tmp = pos->astnode_ident.next;
            pos->astnode_ident.next = node;
            break;
        case AST_VAR:
            tmp = pos->astnode_var.next;
            pos->astnode_var.next = node;
            break;
        case AST_FUNC:
            tmp = pos->astnode_func.next;
            pos->astnode_func.next = node;
            break;
        case AST_TYPESPECS:
            tmp = pos->astnode_typespecs.next;
            pos->astnode_typespecs.next = node;
            break;
        case AST_QUALIF:
            tmp = pos->astnode_qualif.next;
            pos->astnode_qualif.next = node;
            break;
    }
    
    switch (*(int *) node)
    {
        case AST_NULL:
            node->astnode_null.next = tmp;
            break;
        case AST_IDENT:
            node->astnode_ident.next = tmp;
            break;
        case AST_VAR:
            node->astnode_var.next = tmp;
            break;
        case AST_FUNC:
            node->astnode_func.next = tmp;
            break;
        case AST_TYPESPECS:
            node->astnode_typespecs.next = tmp;
            break;
        case AST_QUALIF:
            node->astnode_qualif.next = tmp;
            break;
    }

}

void insert_astnode_op(astnode *op, astnode *node)
{
    astnode *tmp;
    if (node == NULL)
    {
        return;
    }

    switch (*(int *) node)
    {
        case AST_VAR:
            tmp = node->astnode_var.prev;
            node->astnode_var.prev = op;
            break;
        case AST_NUMBER:
            tmp = node->astnode_number.prev;
            node->astnode_number.prev = op;
            break;
        case AST_CHARLIT:
            tmp = node->astnode_charlit.prev;
            node->astnode_charlit.prev = op;
            break;
        case AST_STRING:
            tmp = node->astnode_string.prev;
            node->astnode_string.prev = op;
            break;
    }

    switch (*(int *) op)
    {
        case AST_OP:
            op->astnode_op.next = tmp;
            break;
        case AST_BINOP:
            op->astnode_binop.left = tmp;
            break;
    }
}

void print_ast(astnode *root, int level)
{
    if (root == NULL)
    {
        return;
    }
     
    for (int i = 0; i < level; ++i)
    {
        fprintf(stderr, "   ");
    }
    
    switch (*(int *) root)
    { 
        case AST_VAR:
            fprintf(stderr, "%s defined at %s:%d as a variable of type:\n", root->astnode_var.name, current_file, current_line);
            print_ast(root->astnode_var.next, level+1);
            break;
        case AST_FUNC:
            fprintf(stderr, "%s defined at %s:%d as a function with return type:\n", root->astnode_func.name, current_file, current_line);
            print_ast(root->astnode_func.next, level+1);
            break;
        case AST_NUMBER:
            fprintf(stderr, "NUMBER: %s");
            break;
        case AST_TYPESPECS:
            if (root->astnode_typespecs.is_const)
                fprintf(stderr, "const ");
            if (root->astnode_typespecs.is_volatile)
                fprintf(stderr, "volatile ");
            switch (root->astnode_typespecs.type_actual)
            {
                case SPEC_NULL: fprintf(stderr, "int\n"); break;
                case SPEC_VOID: fprintf(stderr, "void\n"); break;
                case SPEC_CHAR: fprintf(stderr, "char\n"); break;
                case SPEC_SIGNED_CHAR: fprintf(stderr, "signed char\n"); break;
                case SPEC_UNSIGNED_CHAR: fprintf(stderr, "unsigned char\n"); break;
                case SPEC_SIGNED_SHORT: fprintf(stderr, "signed short\n"); break;
                case SPEC_UNSIGNED_SHORT: fprintf(stderr, "unsigned short\n"); break;
                case SPEC_SIGNED_INT: fprintf(stderr, "signed int\n"); break;
                case SPEC_UNSIGNED_INT: fprintf(stderr, "unsigned int\n"); break;
                case SPEC_SIGNED_LONG: fprintf(stderr, "signed long\n"); break;
                case SPEC_UNSIGNED_LONG: fprintf(stderr, "unsigned long\n"); break;
                case SPEC_SIGNED_LONGLONG: fprintf(stderr, "signed long long\n"); break;
                case SPEC_UNSIGNED_LONGLONG: fprintf(stderr, "unsigned long long\n"); break;
                case SPEC_FLOAT: fprintf(stderr, "float\n"); break;
                case SPEC_DOUBLE: fprintf(stderr, "double\n"); break;
                case SPEC_LONG_DOUBLE: fprintf(stderr, "long double\n"); break;
                case SPEC_BOOL: fprintf(stderr, "_bool\n"); break;
                case SPEC_FLOAT_COMPLEX: fprintf(stderr, "float _complex\n"); break;
                case SPEC_DOUBLE_COMPLEX: fprintf(stderr, "double _complex\n"); break;
                case SPEC_LONG_DOUBLE_COMPLEX: fprintf(stderr, "long double _complex\n"); break;
            }
            print_ast(root->astnode_typespecs.next, level+1);
            break;
        case AST_PTR:
            break;
        case AST_QUALIF:
            switch (root->astnode_qualif.type_qual)
            {
                case QUAL_CONST: fprintf(stderr, "const\n"); break;
                case QUAL_VOLATILE: fprintf(stderr, "volatile\n"); break;  
            }
            print_ast(root->astnode_qualif.next, level+1);
            break;
        case AST_ARRAY:
            break;
        case AST_OP:
            switch (root->astnode_op.op)
            {
                case OP_PREINC:
                    fprintf(stderr, "unary op: pre increment\n");
                    break;
                case OP_POSTINC:
                    fprintf(stderr, "unary op: post increment\n");
                    break;
                case OP_PREDEC:
                    fprintf(stderr, "unary op: pre decrement\n");
                    break;
                case OP_POSTDEC:
                    fprintf(stderr, "unary op: post decrement\n");
                    break;
                case OP_ADDROF:
                    fprintf(stderr, "unary op: address of\n");
                    break;
                case OP_DEREF:
                    fprintf(stderr, "unary op: dereference\n");
                    break;
                case OP_POS:
                    fprintf(stderr, "unary op: positive\n");
                    break;
                case OP_NEG:
                    fprintf(stderr, "unary op: negative\n");
                    break;
                case OP_NOT:
                    fprintf(stderr, "unary op: bitwise not\n");
                    break;
                case OP_LOGNOT:
                    fprintf(stderr, "unary op: logical not\n");
                    break;
            }
            break;
        case AST_BINOP:
            switch (root->astnode_op.op)
            {
                case OP_SHL:
                    fprintf(stderr, "binary op: shift left\n");
                    
                    break;
                case OP_SHR:
                    fprintf(stderr, "binary op: shift right\n");
                    break;
                case OP_LTEQ:
                    fprintf(stderr, "binary op: <=\n");
                    break;
                case OP_GTEQ:
                    fprintf(stderr, "binary op: >=\n");
                    break;
                case OP_EQEQ:
                    fprintf(stderr, "binary op: ==\n");
                    break;
                case OP_NOTEQ:
                    fprintf(stderr, "binary op: !=\n");
                    break;
                case OP_LOGAND:
                    fprintf(stderr, "binary op: &&\n");
                    break;
                case OP_LOGOR:
                    fprintf(stderr, "binary op: ||\n");
                    break;
                case OP_ELLIPSIS:
                    fprintf(stderr, "binary op: ...\n");
                    break;
                case OP_TIMESEQ:
                    fprintf(stderr, "binary op: >>\n");
                    break;
                case OP_DIV:
                    fprintf(stderr, "binary op: /\n");
                    break;
                case OP_MOD:
                    fprintf(stderr, "binary op: %\n");
                    break;
                case OP_ADD:
                    fprintf(stderr, "binary op: +\n");
                    break;
                case OP_SUB:
                    fprintf(stderr, "binary op: -\n");
                    break;
                case OP_MULT:
                    fprintf(stderr, "binary op: *\n");
                     break;
                case OP_LT:
                    fprintf(stderr, "binary op: <\n");
                    break;
                case OP_GT:
                    fprintf(stderr, "binary op: >\n");
                    break;
                case OP_AND:
                    fprintf(stderr, "binary op: &\n");
                    break;
                case OP_OR:
                    fprintf(stderr, "binary op: |\n");
                    break;
                case OP_EQ:
                    fprintf(stderr, "binary op: =\n");
                    break;
                case OP_XOR:
                    fprintf(stderr, "binary op: ^\n");
                    break;
            }
            print_ast(root->astnode_binop.left, level+1);
            print_ast(root->astnode_binop.right, level+1);
            break;
        case AST_IF:
            fprintf(stderr, "IF:\n");
            print_ast(root->astnode_if.test, level + 1);
            break;
        case AST_GOTO:
            break;
        case AST_WHILE:
            fprintf(stderr, "WHILE:\n");
            print_ast(root->astnode_while.test, level + 1);
            break;
        case AST_DOWHILE:
            fprintf(stderr, "DO WHILE:\n");
            print_ast(root->astnode_if.test, level + 1);
            break;
    }
}
