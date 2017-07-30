%{
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ptypes.h"
#include "sym.h"
#include "ast.h"

extern int yylex();
extern int yyparse();
extern FILE* yyin;
void yyerror(const char* s);

int current_line = 0;
char current_file[FILENAME_MAX];
int debug = 0;

scope_stack scopes;

astnode *ast_head;
astnode *ast_tail;

%}

%union {
    char *string;
    char character;
    num number;
    astnode *node;
}

%token<string> IDENT
%token<character> CHARLIT
%token<string> STRING
%token<number> NUMBER

%token TOKEOF ELLIPSIS AUTO BREAK CASE CHAR CONST CONTINUE DEFAULT DO DOUBLE ENUM EXTERN FLOAT FOR GOTO INLINE INT LONG REGISTER RESTRICT RETURN SHORT SIGNED SIZEOF STATIC STRUCT SWITCH TYPEDEF UNION UNSIGNED VOID VOLATILE WHILE _BOOL _COMPLEX _IMAGINARY

%left ','
%right '=' PLUSEQ MINUSEQ TIMESEQ DIVEQ MODEQ SHLEQ SHREQ ANDEQ XOREQ OREQ
%right '?' ':'
%left LOGOR LOGAND '|' '^' '&'
%left EQEQ NOTEQ
%left '<' LTEQ '>' GTEQ
%left SHL SHR
%left '+' '-'
%left '*' '/' '%'
%left INDSEL PLUSPLUS MINUSMINUS '~' '!'

%left '(' ')'
%left UNARY

%left IF
%left ELSE

%type<node> declaration_specifiers
%type<node> type_specifier
%type<node> direct_declarator
%type<node> init_declarator
%type<node> declarator
%type<node> storage_class_specifier
%type<node> type_qualifier
%type<node> type_qualifier_list
%type<node> pointer
%type<node> struct_or_union
%type<node> block_item
%type<node> block_item_list
%type<node> expression
%type<node> primary_expression
%type<node> postfix_expression
%type<node> compound_statement
%type<node> unary_operator
%type<node> unary_expression
%type<node> cast_expression
%type<node> multiplicative_expression
%type<node> additive_expression
%type<node> shift_expression
%type<node> relational_expression
%type<node> equality_expression
%type<node> and_expression
%type<node> exclusive_or_expression
%type<node> inclusive_or_expression
%type<node> logical_and_expression
%type<node> logical_or_expression
%type<node> conditional_expression
%type<node> assignment_expression
%type<node> assignment_operator
%type<node> statement
%type<node> labeled_statement
%type<node> selection_statement
%type<node> iteration_statement

%start translation_unit

%%


/*** Expressions **************************************************************/
primary_expression  : IDENT
                      {
                        $$ = find_sym(&scopes, NS_DEFAULT, $1);
                      }
                    | NUMBER
                      {
                        $$ = new_astnode(AST_NUMBER);
                        $$->astnode_number.number = $1;
                      }
                    | CHARLIT
                      {
                        $$ = new_astnode(AST_CHARLIT);
                        $$->astnode_charlit.ch = $1;
                      }
                    | STRING
                      {
                        $$ = new_astnode(AST_STRING);
                        $$->astnode_string.string = $1;
                      }
                    | '(' expression ')'
                      {
                        $$ = $2;
                      }
                    ;

postfix_expression  : primary_expression
                    | postfix_expression '[' expression ']'
                      {
                        astnode *index = new_astnode(AST_BINOP);
                        index->astnode_binop.left = $1;
                        index->astnode_binop.right = $3; 
                        index->astnode_binop.op = (int) '+';
                        
                        $$ = new_astnode(AST_DEREF);
                        insert_astnode(index, $$); 
                      }
                    | postfix_expression '(' ')'
                      {
                        $$ = new_astnode(AST_CALL);
                        $$->astnode_call.stab = $1;
                      }
                    | postfix_expression '(' argument_expression_list ')'
                    | postfix_expression '.' IDENT
                    | postfix_expression INDSEL IDENT
                    | postfix_expression PLUSPLUS
                      {
                        $$  = new_astnode(AST_OP);
                        $$->astnode_op.op = OP_POSTINC;
                        insert_astnode_op($$, $1);
                      }
                    | postfix_expression MINUSMINUS
                      {
                        $$ = new_astnode(AST_OP);
                        $$->astnode_op.op = OP_POSTDEC;
                        insert_astnode_op($$, $1);
                      }
                    ;

argument_expression_list : assignment_expression
                    | argument_expression_list ',' assignment_expression
                    ;

unary_expression    : postfix_expression
                    | PLUSPLUS unary_expression
                      {
                        $$ = new_astnode(AST_OP);
                        $$->astnode_op.op = OP_PREINC;
                        insert_astnode_op($$, $2);
                      } 
                    | MINUSMINUS unary_expression
                      {
                        $$ = new_astnode(AST_OP);
                        $$->astnode_op.op = OP_PREDEC;
                        insert_astnode_op($$, $2);
                      } 
                    | unary_operator cast_expression
                      {
                        insert_astnode_op($$, $2);
                      }
                    | SIZEOF unary_expression
                    | SIZEOF '(' type_name ')'
                    ;

unary_operator      : '&' %prec UNARY
                      {
                        $$ = new_astnode(AST_OP);
                        $$->astnode_op.op = OP_ADDROF;
                      }
                    | '*'
                      {
                        $$ = new_astnode(AST_OP);
                        $$->astnode_op.op = OP_DEREF;
                      }
                    | '+'
                      {
                        $$ = new_astnode(AST_OP);
                        $$->astnode_op.op = OP_POS;
                      }
                    | '-'
                      {
                        $$ = new_astnode(AST_OP);
                        $$->astnode_op.op = OP_NEG;
                      }
                    | '~'
                      {
                        $$ = new_astnode(AST_OP);
                        $$->astnode_op.op = OP_NOT;
                      }
                    | '!'
                      {
                        $$ = new_astnode(AST_OP);
                        $$->astnode_op.op = OP_LOGNOT;
                      }
                    ;

cast_expression     : unary_expression
                    | '(' type_name ')' cast_expression
                    ;

multiplicative_expression : cast_expression
                    | multiplicative_expression '*' cast_expression
                      {
                        $$ = new_astnode(AST_BINOP);
                        $$->astnode_binop.op = OP_MULT;
                        $$->astnode_binop.left = $1;
                        $$->astnode_binop.right = $3;
                      }
                    | multiplicative_expression '/' cast_expression
                      {
                        $$ = new_astnode(AST_BINOP);
                        $$->astnode_binop.op = OP_DIV;
                        $$->astnode_binop.left = $1;
                        $$->astnode_binop.right = $3;
                      }
                    | multiplicative_expression '%' cast_expression
                      {
                        $$ = new_astnode(AST_BINOP);
                        $$->astnode_binop.op = OP_MOD;
                        $$->astnode_binop.left = $1;
                        $$->astnode_binop.right = $3;
                      }
                    ;

additive_expression : multiplicative_expression
                    | additive_expression '+' multiplicative_expression
                      {
                        $$ = new_astnode(AST_BINOP);
                        $$->astnode_binop.op = OP_ADD;
                        $$->astnode_binop.left = $1;
                        $$->astnode_binop.right = $3;
                      }
                    | additive_expression '-' multiplicative_expression
                      {
                        $$ = new_astnode(AST_BINOP);
                        $$->astnode_binop.op = OP_SUB;
                        $$->astnode_binop.left = $1;
                        $$->astnode_binop.right = $3;
                      }
                    ;

shift_expression    : additive_expression
                    | shift_expression SHL additive_expression
                      {
                        $$ = new_astnode(AST_BINOP);
                        $$->astnode_binop.op = OP_SHL;
                        $$->astnode_binop.left = $1;
                        $$->astnode_binop.right = $3;
                      }
                    | shift_expression SHR additive_expression
                      {
                        $$ = new_astnode(AST_BINOP);
                        $$->astnode_binop.op = OP_SHR;
                        $$->astnode_binop.left = $1;
                        $$->astnode_binop.right = $3;
                      }
                    ;

relational_expression : shift_expression
                    | relational_expression '<' shift_expression
                      {
                        $$ = new_astnode(AST_BINOP);
                        $$->astnode_binop.op = OP_LT;
                        $$->astnode_binop.left = $1;
                        $$->astnode_binop.right = $3;
                      }
                    | relational_expression '>' shift_expression
                      {
                        $$ = new_astnode(AST_BINOP);
                        $$->astnode_binop.op = OP_GT;
                        $$->astnode_binop.left = $1;
                        $$->astnode_binop.right = $3;
                      }
                    | relational_expression LTEQ shift_expression
                      {
                        $$ = new_astnode(AST_BINOP);
                        $$->astnode_binop.op = OP_LTEQ;
                        $$->astnode_binop.left = $1;
                        $$->astnode_binop.right = $3;
                      }
                    | relational_expression GTEQ shift_expression
                      {
                        $$ = new_astnode(AST_BINOP);
                        $$->astnode_binop.op = OP_GTEQ;
                        $$->astnode_binop.left = $1;
                        $$->astnode_binop.right = $3;
                      }
                    ;

equality_expression : relational_expression
                    | equality_expression EQEQ relational_expression
                      {
                        $$ = new_astnode(AST_BINOP);
                        $$->astnode_binop.op = OP_EQEQ;
                        $$->astnode_binop.left = $1;
                        $$->astnode_binop.right = $3;
                      }
                    | equality_expression NOTEQ relational_expression
                      {
                        $$ = new_astnode(AST_BINOP);
                        $$->astnode_binop.op = OP_NOTEQ;
                        $$->astnode_binop.left = $1;
                        $$->astnode_binop.right = $3;
                      }
                    ;

and_expression      : equality_expression
                    | and_expression '&' equality_expression
                      {
                        $$ = new_astnode(AST_BINOP);
                        $$->astnode_binop.op = OP_AND;
                        $$->astnode_binop.left = $1;
                        $$->astnode_binop.right = $3;
                      }
                    ;

exclusive_or_expression : and_expression
                    | exclusive_or_expression '^' and_expression
                      {
                        $$ = new_astnode(AST_BINOP);
                        $$->astnode_binop.op = OP_XOR;
                        $$->astnode_binop.left = $1;
                        $$->astnode_binop.right = $3;
                      }
                    ;

inclusive_or_expression : exclusive_or_expression
                    | inclusive_or_expression '|' exclusive_or_expression
                      {
                        $$ = new_astnode(AST_BINOP);
                        $$->astnode_binop.op = OP_OR;
                        $$->astnode_binop.left = $1;
                        $$->astnode_binop.right = $3;
                      }
                    ;

logical_and_expression : inclusive_or_expression
                    | logical_and_expression LOGAND inclusive_or_expression
                      {
                        $$ = new_astnode(AST_BINOP);
                        $$->astnode_binop.op = OP_LOGAND;
                        $$->astnode_binop.left = $1;
                        $$->astnode_binop.right = $3;
                      }
                    ;

logical_or_expression : logical_and_expression
                    | logical_or_expression LOGOR logical_and_expression
                      {
                        $$ = new_astnode(AST_BINOP);
                        $$->astnode_binop.op = OP_LOGOR;
                        $$->astnode_binop.left = $1;
                        $$->astnode_binop.right = $3;
                      }
                    ;

conditional_expression : logical_or_expression
                    | logical_or_expression '?' expression ':' conditional_expression
                    ;

assignment_expression : conditional_expression
                    | unary_expression assignment_operator assignment_expression
                      {
                        $$ = new_astnode(AST_BINOP);
                        $$->astnode_binop.op = OP_EQ;
                        $$->astnode_binop.left = $1;
                        $$->astnode_binop.right = $3;
                      }
                    ;

assignment_operator : '='
                    | TIMESEQ
                      {
                        $$ = new_astnode(AST_BINOP);
                        $$->astnode_binop.op = OP_MULT;
                        $$->astnode_binop.left = $<node>0;
                      }
                    | DIVEQ
                      {
                        $$ = new_astnode(AST_BINOP);
                        $$->astnode_binop.op = OP_DIV;
                        $$->astnode_binop.left = $<node>0;
                      }
                    | MODEQ
                      {
                        $$ = new_astnode(AST_BINOP);
                        $$->astnode_binop.op = OP_MOD;
                        $$->astnode_binop.left = $<node>0;
                      }
                    | PLUSEQ
                      {
                        $$ = new_astnode(AST_BINOP);
                        $$->astnode_binop.op = OP_ADD;
                        $$->astnode_binop.left = $<node>0;
                      }
                    | MINUSEQ
                      {
                        $$ = new_astnode(AST_BINOP);
                        $$->astnode_binop.op = OP_SUB;
                        $$->astnode_binop.left = $<node>0;
                      }
                    | SHLEQ
                      {
                        $$ = new_astnode(AST_BINOP);
                        $$->astnode_binop.op = OP_SHL;
                        $$->astnode_binop.left = $<node>0;
                      }
                    | SHREQ
                      {
                        $$ = new_astnode(AST_BINOP);
                        $$->astnode_binop.op = OP_SHR;
                        $$->astnode_binop.left = $<node>0;
                      }
                    | ANDEQ
                      {
                        $$ = new_astnode(AST_BINOP);
                        $$->astnode_binop.op = OP_AND;
                        $$->astnode_binop.left = $<node>0;
                      }
                    | XOREQ
                      {
                        $$ = new_astnode(AST_BINOP);
                        $$->astnode_binop.op = OP_XOR;
                        $$->astnode_binop.left = $<node>0;
                      }
                    | OREQ
                      {
                        $$ = new_astnode(AST_BINOP);
                        $$->astnode_binop.op = OP_OR;
                        $$->astnode_binop.left = $<node>0;
                      }

                    ;

expression          : assignment_expression
                      {
                        print_ast($1, 0);
                      }
                    | expression ',' assignment_expression
                    ;

constant_expression : conditional_expression
                    ;

/*** Declarations *************************************************************/
declaration         : declaration_specifiers ';'
                      {
                        insert_astnode($1, ast_tail);
                        print_ast(ast_head, 0);
                      }
                    | declaration_specifiers init_declarator_list ';'
                      {
                        /* attach declspecs to declarator */
                        insert_astnode($1, ast_tail); 
                        print_ast(ast_head, 0);
                      }
                    ;

declaration_specifiers : storage_class_specifier
                    | storage_class_specifier declaration_specifiers
                    | type_specifier
                      {
                        transform_typespecs($1);
                      }
                    | type_specifier declaration_specifiers
                      {
                        /* accumulate type specifiers */
                        $1->astnode_typespecs.type_arr |= $2->astnode_typespecs.type_arr;
                        transform_typespecs($1);
                        $$ = $1;
                      }
                    | type_qualifier
                    | type_qualifier declaration_specifiers
                    ;

init_declarator_list : init_declarator
                      {
                        if ($1->astnode_ident.next && *(int *) ($1->astnode_ident.next) == AST_FUNC)
                        {
                            astnode *func_node = $1->astnode_ident.next;
                            strcpy(func_node->astnode_func.name, $1->astnode_ident.name);
                            insert_entry(&scopes, 0, NS_DEFAULT, func_node->astnode_func.name, func_node);
                            insert_astnode($<node>0, ast_tail); 
                            ast_head = func_node;
                            print_ast(ast_head, 0);
                            ast_head = new_astnode(AST_NULL);
                            ast_tail = ast_head;
                        }
                        else /* variable declaration */ 
                        {
                            * (int *) $1 = AST_VAR;
                            strcpy($1->astnode_var.name, $1->astnode_ident.name);
                            insert_entry(&scopes, 0, NS_DEFAULT, $1->astnode_var.name, ast_head->astnode_null.next);
                            insert_astnode($<node>0, ast_tail); 
                            print_ast(ast_head, 0);
                            ast_head = new_astnode(AST_NULL);
                            ast_tail = ast_head;
                        }
                      }
                    | init_declarator_list ',' init_declarator
                      {
                        if ($3->astnode_ident.next && *(int *) ($3->astnode_ident.next) == AST_FUNC)
                        {
                            astnode *func_node = $3->astnode_ident.next;
                            strcpy(func_node->astnode_func.name, $3->astnode_ident.name);
                            insert_entry(&scopes, 0, NS_DEFAULT, func_node->astnode_func.name, func_node);

                            insert_astnode($<node>0, ast_tail);
                            print_ast(ast_head, 0);
                            ast_head = new_astnode(AST_NULL);
                            ast_tail = ast_head;
                        }
                        else /* variable declaration */ 
                        {
                            * (int *) $3 = AST_VAR;
                            strcpy($3->astnode_var.name, $3->astnode_ident.name);
                            insert_entry(&scopes, 0, NS_DEFAULT, $3->astnode_var.name, ast_head->astnode_null.next);
                            insert_astnode($<node>0, ast_tail); 
                            print_ast(ast_head, 0);
                            ast_head = new_astnode(AST_NULL);
                            ast_tail = ast_head;
                        }
                      }
                    ;

init_declarator     : declarator
                    | declarator '=' initializer
                    ;

storage_class_specifier : TYPEDEF {$$ = new_astnode(AST_TYPEDEF_NAME);}
                    | EXTERN    {$$ = new_astnode(AST_VAR); $$->astnode_var.stg = EXTERN;}
                    | STATIC    {$$ = new_astnode(AST_VAR); $$->astnode_var.stg = STATIC;}
                    | AUTO      {$$ = new_astnode(AST_VAR); $$->astnode_var.stg = AUTO;}
                    | REGISTER  {$$ = new_astnode(AST_VAR); $$->astnode_var.stg = REGISTER;}
                    ;

type_specifier      : VOID
                      {
                        $$ = new_astnode(AST_TYPESPECS);
                        SET_TYPE($$->astnode_typespecs.type_arr, TYPE_VOID); 
                      }
                    | CHAR
                      {
                        $$ = new_astnode(AST_TYPESPECS);
                        SET_TYPE($$->astnode_typespecs.type_arr, TYPE_CHAR); 
                      }
                    | SHORT
                      {
                        $$ = new_astnode(AST_TYPESPECS);
                        SET_TYPE($$->astnode_typespecs.type_arr, TYPE_SHORT); 
                      }
                    | INT
                      {
                        $$ = new_astnode(AST_TYPESPECS);
                        SET_TYPE($$->astnode_typespecs.type_arr, TYPE_INT); 
                        /* insert_astnode(newnode, ast_tail); */
                      }
                    | LONG
                      {
                        $$ = new_astnode(AST_TYPESPECS);
                        SET_TYPE($$->astnode_typespecs.type_arr, TYPE_LONG); 
                      }
                    | FLOAT
                      {
                        $$ = new_astnode(AST_TYPESPECS);
                        SET_TYPE($$->astnode_typespecs.type_arr, TYPE_FLOAT); 
                      }
                    | DOUBLE
                      {
                        $$ = new_astnode(AST_TYPESPECS);
                        SET_TYPE($$->astnode_typespecs.type_arr, TYPE_DOUBLE); 
                      }
                    | SIGNED
                      {
                        $$ = new_astnode(AST_TYPESPECS);
                        SET_TYPE($$->astnode_typespecs.type_arr, TYPE_SIGNED); 
                      }
                    | UNSIGNED
                      {
                        $$ = new_astnode(AST_TYPESPECS);
                        SET_TYPE($$->astnode_typespecs.type_arr, TYPE_UNSIGNED); 
                      }
                    | struct_or_union_specifier
                    | enum_specifier
                    ;

struct_or_union_specifier : struct_or_union '{' struct_declaration_list '}'
                    | struct_or_union IDENT '{' struct_declaration_list '}'
                    | struct_or_union IDENT
                    ;

struct_or_union     : STRUCT    {$$ = new_astnode(AST_STRUCT_TAG);}
                    | UNION     {$$ = new_astnode(AST_UNION_TAG);}
                    ;

struct_declaration_list : struct_declaration
                    | struct_declaration_list struct_declaration
                    ;

struct_declaration  : specifier_qualifier_list struct_declarator_list ';'
                    ;

specifier_qualifier_list : type_specifier
                    | type_specifier specifier_qualifier_list
                    | type_qualifier
                    | type_qualifier specifier_qualifier_list
                    ;

struct_declarator_list : struct_declarator
                    | struct_declarator_list ',' struct_declarator
                    ;

struct_declarator   : declarator
                    | ':' constant_expression
                    | declarator ':' constant_expression
                    ;

enum_specifier      : ENUM '{' enumerator_list '}'
                    | ENUM IDENT '{' enumerator_list '}'
                    | ENUM IDENT
                    ;

enumerator_list     : enumerator
                    | enumerator_list ',' enumerator
                    ;

enumerator          : IDENT
                    | IDENT '=' constant_expression
                    ;

type_qualifier      : CONST
                      {
                        $$ = new_astnode(AST_TYPESPECS);
                        $$->astnode_typespecs.is_const = 1;
                      }
                    | VOLATILE
                      {
                        $$ = new_astnode(AST_TYPESPECS);
                        $$->astnode_typespecs.is_volatile = 1;
                      }
                    ;

declarator          : direct_declarator
                    | pointer direct_declarator
                      {
                        insert_astnode($1, ast_tail);      
                      }
                    ;

direct_declarator   : IDENT
                      { 
                        ast_head = new_astnode(AST_IDENT);
                        ast_tail = ast_head;
                        strcpy(ast_head->astnode_ident.name, $1);
                        $$ = ast_head;
                        /* ast_head = newnode; */
                        /* insert_astnode(newnode, ast_tail); */
                      }
                    | '(' declarator ')'
                    | direct_declarator '[' ']'
                      {
                        astnode *newnode = new_astnode(AST_ARRAY);
                        newnode->astnode_array.size = -1; 
                        insert_astnode(newnode, ast_tail);
                      }
                    | direct_declarator '[' NUMBER ']'
                      {
                        astnode *newnode = new_astnode(AST_ARRAY);
                        newnode->astnode_array.size = $3.value.s_int;
                        insert_astnode(newnode, ast_tail);
                      }
                    /* TODO fix sr conflict */
                    /* | direct_declarator '[' type_qualifier_list ']' */
                    /* | direct_declarator '[' assignment_expression ']' */
                    /* | direct_declarator '[' type_qualifier_list assignment_expression']' */
                    /* | direct_declarator '[' STATIC assignment_expression']' */
                    /* | direct_declarator '[' STATIC type_qualifier_list assignment_expression']' */
                    /* | direct_declarator '[' type_qualifier_list STATIC assignment_expression']' */
                    /* | direct_declarator '[' constant_expression ']' */
                    | direct_declarator '[' '*' ']'
                    | direct_declarator '[' type_qualifier_list '*' ']'
                    | direct_declarator '(' parameter_type_list ')'
                    | direct_declarator '(' identifier_list ')'
                    | direct_declarator '(' ')'
                      {
                        astnode *newnode = new_astnode(AST_FUNC);
                        insert_astnode(newnode, ast_tail);
                        ast_tail = newnode;
                      }
                    ;

pointer             : '*'                       {$$ = new_astnode(AST_PTR);}
                    | '*' type_qualifier_list   {$$ = new_astnode(AST_PTR);}
                    | '*' pointer
                      {
                       astnode *newnode = new_astnode(AST_PTR);
                       insert_astnode(newnode, $2);
                       $$ = $2;
                      }
                    | '*' type_qualifier_list pointer
                      {
                       astnode *newnode = new_astnode(AST_PTR);
                       insert_astnode(newnode, $3);
                       $$ = $3;
                      }
                    ;

type_qualifier_list : type_qualifier
                    | type_qualifier_list type_qualifier
                      {
                        $1->astnode_qualif.next = $2;
                      }
                    ;

parameter_type_list : parameter_list
                    | parameter_list ',' ELLIPSIS
                    ;

parameter_list      : parameter_declaration
                    | parameter_list ',' parameter_declaration
                    ;

parameter_declaration : declaration_specifiers declarator
                    | declaration_specifiers abstract_declarator
                    | declaration_specifiers
                    ;

identifier_list     : IDENT
                    | identifier_list ',' IDENT
                    ;

type_name           : specifier_qualifier_list
                    | specifier_qualifier_list abstract_declarator
                    ;

abstract_declarator : pointer
                    | direct_abstract_declarator
                    | pointer direct_abstract_declarator
                    ;

direct_abstract_declarator : '(' abstract_declarator ')'
                    | '[' ']'
                    | '[' assignment_expression ']'
                    | direct_abstract_declarator '[' ']'
                    | direct_abstract_declarator '[' assignment_expression ']'
                    | '[' '*' ']'
                    | direct_abstract_declarator '[' '*' ']'
                    | '(' ')'
                    | '(' parameter_type_list ')'
                    | direct_abstract_declarator '(' ')'
                    | direct_abstract_declarator '(' parameter_type_list ')'
                    ;

/* typedef_name        : IDENT */
                    /* ; */

initializer         : assignment_expression
                    | '{' initializer_list '}'
                    | '{' initializer_list ',' '}'
                    ;

initializer_list    : initializer
                    | initializer_list ',' initializer
                    ;

/*** statements ***************************************************************/
statement           : labeled_statement
                    | compound_statement
                    | expression_statement
                    | selection_statement
                    | iteration_statement
                    | jump_statement
                    ;

labeled_statement   : IDENT ':' statement
                      {
                        $$ = $3;
                        insert_entry(&scopes, 0, NS_LABEL, $1,  $3);
                      }
                    | CASE constant_expression ':' statement
                    | DEFAULT ':' statement
                    ;

compound_statement  : '{' '}'
                    | '{' {push_scope(&scopes, SCOPE_BLOCK);} block_item_list '}'
                      {
                        $$ = $3;
                        pop_scope(&scopes);
                      }
                    ;

block_item_list     : block_item
                    | block_item_list block_item
                    ;

block_item          : declaration
                    | statement

expression_statement : ';'
                    | expression ';'
                    ;

selection_statement : IF '(' expression ')' statement                %prec IF
                      {
                        $$ = new_astnode(AST_IF);
                        $$->astnode_if.test = $3;
                        $$->astnode_if.true = $5;
                        $$->astnode_if.false = 0;
                      }
                    | IF '(' expression ')' statement ELSE statement %prec ELSE
                      {
                        $$ = new_astnode(AST_IF);
                        $$->astnode_if.test = $3;
                        $$->astnode_if.true = $5;
                        $$->astnode_if.false = $7;
                      }
                    | SWITCH '(' expression ')' statement
                    ;

iteration_statement : WHILE '(' expression ')' statement
                      {
                        $$ = new_astnode(AST_WHILE);
                        $$->astnode_while.test = $3;
                        $$->astnode_while.body = $5;
                      }
                    | DO statement WHILE '(' expression ')' ';'
                      {
                        $$ = new_astnode(AST_DOWHILE);
                        $$->astnode_while.test = $5;
                        $$->astnode_while.body = $2;
                      }
                    | FOR '(' expression_statement expression_statement ')' statement
                    | FOR '(' declaration expression_statement ')' statement
                    | FOR '(' declaration expression_statement expression ')' statement
                    ;

jump_statement      : GOTO IDENT ';'
                    | CONTINUE ';'
                    | BREAK ';'
                    | RETURN ';'
                    | RETURN expression ';'
                    ;

/*** External definitions *****************************************************/
translation_unit    : external_declaration
                    | translation_unit external_declaration
                    ;

external_declaration : function_definition
                    | declaration
                    ;

function_definition : declaration_specifiers declarator compound_statement
                      {
                        // insert_astnode($1, ast_tail); 
                        print_ast(ast_head, 0);
                        astnode *node = new_astnode(AST_FUNC);
                        node->astnode_func.rtype = $1;
                      }
                    | declaration_specifiers declarator declaration_list compound_statement
                    | declarator declaration_list compound_statement
                    | declarator compound_statement
                    ;

declaration_list    : declaration
                    | declaration_list declaration
                    ;

%%

void yyerror(const char *s)
{
    fprintf(stderr, "Parse error at line %d in file '%s': %s.\n", current_line, current_file, s);
}

int main()
{
    push_scope(&scopes, SCOPE_FILE);
    ast_head = new_astnode(AST_NULL);
    ast_tail = ast_head;
    yyin = stdin;
    do {
        yyparse();
        print_all_tables(&scopes);
    } while(!feof(yyin));
    return 0;
}




