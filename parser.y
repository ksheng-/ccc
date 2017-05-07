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

%left IF
%left ELSE

%type<node> block_item
%type<node> block_item_list
%type<node> statement
%type<node> compound_statement
%type<node> selection_statement
%type<node> labeled_statement
%type<node> jump_statement
%type<node> iteration_statement
%type<node> expression
%type<node> argument_expression_list
%type<node> struct_or_union
%type<node> struct_or_union_specifier
%type<node> storage_class_specifier
%type<node> type_qualifier
%type<node> type_qualifier_list
%type<node> pointer
%type<node> declaration_specifiers
%type<node> type_specifier
%type<node> direct_declarator
%type<node> init_declarator
%type<node> declarator

%start translation_unit

%%
/*** External definitions *****************************************************/
translation_unit    : external_declaration
                    | translation_unit external_declaration
                    ;

external_declaration : function_definition
                    | declaration
                    ;

function_definition : declaration_specifiers declarator compound_statement
                      {
                        // TODO link symbol table to declarator
                        printf("FUNCTION");
                        // insert_astnode($1, ast_tail); 
                        print_ast(ast_head, 0);
                      }
                    | declaration_specifiers declarator declaration_list compound_statement
                    | declarator declaration_list compound_statement
                    | declarator compound_statement
                    ;

declaration_list    : declaration
                    | declaration_list declaration
                    ;

/*** Expressions **************************************************************/
primary_expression  : IDENT
                      {
                        $$ = find_sym(&scopes, NS_DEFAULT, *$1);
                      }
                    | NUMBER
                      {
                        $$ = new_astnode(AST_NUMBER);
                        $$->astnode_number.value = $1;
                      }
                    | CHARLIT
                    | STRING
                    | '(' expression ')'
                    ;

postfix_expression  : primary_expression
                    | postfix_expression '[' expression ']'
                    | postfix_expression '(' ')'
                    | postfix_expression '(' argument_expression_list ')'
                      {
                        $$ = new_astnode(AST_CALL);
                      }
                    | postfix_expression '.' IDENT
                    | postfix_expression INDSEL IDENT
                    | postfix_expression PLUSPLUS
                    | postfix_expression MINUSMINUS
                    ;

argument_expression_list : assignment_expression
                    | argument_expression_list ',' assignment_expression
                    ;

unary_expression    : postfix_expression
                    | PLUSPLUS unary_expression
                    | MINUSMINUS unary_expression
                    | unary_operator cast_expression
                    | SIZEOF unary_expression
                    | SIZEOF '(' type_name ')'
                    ;

unary_operator      : '&'
                    | '*'
                    | '+'
                    | '-'
                    | '~'
                    | '!'
                    ;

cast_expression     : unary_expression
                    | '(' type_name ')' cast_expression
                    ;

multiplicative_expression : cast_expression
                    | multiplicative_expression '*' cast_expression
                    | multiplicative_expression '/' cast_expression
                    | multiplicative_expression '%' cast_expression
                    ;

additive_expression : multiplicative_expression
                    | additive_expression '+' multiplicative_expression
                    | additive_expression '-' multiplicative_expression
                    ;

shift_expression    : additive_expression
                    | shift_expression SHL additive_expression
                    | shift_expression SHR additive_expression
                    ;

relational_expression : shift_expression
                    | relational_expression '<' shift_expression
                    | relational_expression '>' shift_expression
                    | relational_expression LTEQ shift_expression
                    | relational_expression GTEQ shift_expression
                    ;

equality_expression : relational_expression
                    | equality_expression EQEQ relational_expression
                    | equality_expression NOTEQ relational_expression
                    ;

and_expression      : equality_expression
                    | and_expression '&' equality_expression
                    ;

exclusive_or_expression : and_expression
                    | exclusive_or_expression '^' and_expression
                    ;

inclusive_or_expression : exclusive_or_expression
                    | inclusive_or_expression '|' exclusive_or_expression
                    ;

logical_and_expression : inclusive_or_expression
                    | logical_and_expression LOGAND inclusive_or_expression
                    ;

logical_or_expression : logical_and_expression
                    | logical_or_expression LOGOR logical_and_expression
                    ;

conditional_expression : logical_or_expression
                    | logical_or_expression '?' expression ':' conditional_expression
                    ;

assignment_expression : conditional_expression
                    | unary_expression assignment_operator assignment_expression
                    ;

assignment_operator : '='
                    | TIMESEQ
                    | DIVEQ
                    | MODEQ
                    | PLUSEQ
                    | MINUSEQ
                    | SHLEQ
                    | SHREQ
                    | ANDEQ
                    | XOREQ
                    | OREQ
                    ;

expression          : assignment_expression
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

storage_class_specifier : TYPEDEF
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
                    | IF '(' expression ')' statement ELSE statement %prec ELSE
                    | SWITCH '(' expression ')' statement
                    ;

iteration_statement : WHILE '(' expression ')' statement
                    | DO statement WHILE '(' expression ')' ';'
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




