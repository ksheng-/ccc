#ifndef AST_H
#define AST_H

#include "ptypes.h"

#define SET_TYPE(var,type) ((var) |= (1 << (type)))
#define POW2(type) (1 << (type))

extern int current_line;
extern char current_file[FILENAME_MAX];
/* AST node types */
enum astnode_code
{
    AST_NULL = 0,

    // Identifiers
    AST_IDENT,
    AST_VAR,
    AST_FUNC,
    AST_LIST, // Declarator list head
    AST_STRUCT_TAG,
    AST_UNION_TAG,
    AST_ENUM_TAG,
    AST_ENUM_CONST,
    AST_MEMBER,
    AST_LABEL,
    AST_TYPEDEF_NAME,

    // DECLSPECS
    AST_TYPESPECS,
    AST_PTR,
    AST_QUALIF,
    AST_ARRAY,

    AST_NUMBER,
    AST_CHARLIT,
    AST_STRING,

    AST_DEREF,
    AST_CALL,
    AST_OP,
    AST_BINOP,

    AST_IF,
    AST_GOTO,
    AST_WHILE,
    AST_DOWHILE,
};

enum storage_classes
{
    STG_AUTO = 0,
    STG_REGISTER,
    STG_EXTERN,
    STG_STATIC
};

enum type_specs
{
    TYPE_VOID = 0,
    TYPE_CHAR,
    TYPE_SHORT,
    TYPE_INT,
    TYPE_LONG,
    TYPE_LONGLONG,
    TYPE_FLOAT,
    TYPE_DOUBLE,
    TYPE_SIGNED,
    TYPE_UNSIGNED
};

enum valid_specs
{
    SPEC_NULL = 0,
    SPEC_VOID,
    SPEC_CHAR,
    SPEC_SIGNED_CHAR,
    SPEC_UNSIGNED_CHAR,
    SPEC_SIGNED_SHORT,
    SPEC_UNSIGNED_SHORT,
    SPEC_SIGNED_INT,
    SPEC_UNSIGNED_INT,
    SPEC_SIGNED_LONG,
    SPEC_UNSIGNED_LONG,
    SPEC_SIGNED_LONGLONG,
    SPEC_UNSIGNED_LONGLONG,
    SPEC_FLOAT,
    SPEC_DOUBLE,
    SPEC_LONG_DOUBLE,
    SPEC_BOOL,
    SPEC_FLOAT_COMPLEX,
    SPEC_DOUBLE_COMPLEX,
    SPEC_LONG_DOUBLE_COMPLEX
};

enum type_qualifiers
{   
    QUAL_CONST = 0,
    QUAL_VOLATILE,
};

enum operations
{
	OP_PREINC,
	OP_POSTINC,
    OP_PREDEC,
    OP_POSTDEC,
    OP_ADDROF,
    OP_DEREF,
    OP_POS,
    OP_NEG,
    OP_NOT,
    OP_LOGNOT,
	OP_SHL,
	OP_SHR,
	OP_LTEQ,
	OP_GTEQ,
	OP_EQEQ,
	OP_NOTEQ,
	OP_LOGAND,
	OP_LOGOR,
	OP_ELLIPSIS,
	OP_TIMESEQ,
	OP_DIV,
	OP_MOD,
	OP_ADD,
	OP_SUB,
    OP_MULT,
    OP_LT,
    OP_GT,
    OP_AND,
    OP_OR,
    OP_EQ,
    OP_XOR

};

union astnode
{
    struct astnode_null {
        enum astnode_code type;
        union astnode *next;
        union astnode *prev;
    } astnode_null;

    // Temporary polymorphic AST node that gets transformed when installed
    struct astnode_ident {
        enum astnode_code type;
        char name[32];
        int stg;
        union astnode *next;
        union astnode *prev;
    } astnode_ident;

    struct astnode_var {
        enum astnode_code type;
        char name[32];
        int stg, offset;
        union astnode *next;
        union astnode *prev;
        // union astnode *ptr;
    } astnode_var;

    struct astnode_func {
        enum astnode_code type;
        char name[32];
        int stg;
        struct scope *args;
        struct scope *body;
        int inlined;
        union astnode *next;
        union astnode *prev;
        union astnode *rtype;
        // union astnode *ptr;
    } astnode_func;

    // List of AST nodes for delarator lists
    struct astnode_list {
        enum astnode_code type;
        union astnode *next;
    } astnode_list;

    struct astnode_tag {
        enum astnode_code type;
        char name[32];
        struct scope *s;
        int complete; 
    } astnode_tag;

    struct astnode_enum_tag {
        enum astnode_code type;
    } astnode_enum_tag;

    struct astnode_enum_constant {
        int val;
    } astnode_enum_constant;

    struct astnode_member {
        enum astnode_code type;
        int offset;
    } astnode_member;

    struct astnode_typedef_name {
        enum astnode_code eq_type;
    } astnode_typedef_name;

    struct astnode_label {
        enum astnode_code type;
        // TODO: Basic bloc
    } astnode_label;

    // Handle multiple type specifiers, gets transformed
    struct astnode_typespecs {
        enum astnode_code type;
        int type_arr;
        int type_actual;
        int is_const;
        int is_volatile;
        union astnode *next;
        union astnode *prev;
    } astnode_typespecs;

    struct astnode_ptr {
        enum astnode_code type;
        union astnode *next, *prev;
    } astnode_ptr;

    struct astnode_qualif {
        enum astnode_code type;
        int type_qual;
        union astnode *next;
        union astnode *prev;
    } astnode_qualif;

    struct astnode_array {
        enum astnode_code type;
        int size;
        union astnode *next;
        union astnode *prev;
    } astnode_array;

    struct astnode_number {
        enum astnode_code type;
        num number;
        union astnode *next;
        union astnode *prev;
    } astnode_number;

    struct astnode_charlit {
        enum astnode_code type;
        char ch;
        union astnode *next;
        union astnode *prev;
    } astnode_charlit;

    struct astnode_string {
        enum astnode_code type;
        char *string;
        union astnode *next;
        union astnode *prev;
    } astnode_string;

    struct astnode_deref {
        enum astnode_code type;
        union astnode *next;
        union astnode *prev;
    } astnode_deref;

    struct astnode_call {
        enum astnode_code type;
        struct symrec *stab;
        union astnode *next;
        union astnode *prev;
    } astnode_call;
   
    struct astnode_op {
        enum astnode_code type;
        int op;
        union astnode *next;
    } astnode_op;

    struct astnode_binop {
        enum astnode_code type;
        int op;
        union astnode *left;
        union astnode *right;
    } astnode_binop;

    struct astnode_if {
        enum astnode_code type;
        union astnode *test, *true, *false;
    } astnode_if;

    struct astnode_while {
        enum astnode_code type;
        union astnode *test, *body;
    } astnode_while;
    
    struct astnode_dowhile {
        enum astnode_code type;
        union astnode *test, *body;
    } astnode_dowhile;
};
typedef union astnode astnode;

void transform_typespecs(astnode *node);
astnode *new_astnode(int type);
void insert_astnode(astnode *node, astnode *pos);
void insert_astnode_op(astnode *op, astnode *node);
// Recursively print ast starting from root.
void print_ast(astnode *root, int level);

#endif
