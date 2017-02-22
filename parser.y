%{
#include <stdio.h>
#include <stdlib.h>
#include "ptypes.h"

extern int yylex();
extern int yyparse();
extern FILE* yyin;
void yyerror(const char* s);
%}

%union {
	char *string;
	char character;
	num number;
	// symrec *tptr;
}

%token ','
%right '=' PLUSEQ MINUSEQ TIMESEQ DIVEQ MODEQ SHLEQ SHREQ ANDEQ XOREQ OREQ
%left LOGOR
%left LOGAND
%left '|'
%right '^'
%left '&'
%left EQEQ NOTEQ
%left '<' LTEQ '>' GTEQ
%left SHL SHR
%left '+' '-'
%left '*' '/' '%'
%precedence PLUSPLUS MINUSMINUS '~' '!'
%left INDSEL

%token IDENT TOKEOF ELLIPSIS AUTO BREAK CASE CHAR CONST CONTINUE DEFAULT DO DOUBLE ELSE ENUM EXTERN FLOAT FOR GOTO IF INLINE INT LONG REGISTER RESTRICT RETURN SHORT SIGNED SIZEOF STATIC STRUCT SWITCH TYPEDEF UNION UNSIGNED VOID VOLATILE WHILE _BOOL _COMPLEX _IMAGINARY

%token<char *> STRING
%token<char> CHARLIT
%token<number> NUMBER


%start input

%%
input:	input line
		| /* empty */
		;

line:	TOKEOF
		| decl
		| func
		| expr
		| /* empty */
		;

/*** DECLARATIONS *************************************************************/
decl:	declaration-specifiers init-declarator-list ';'
		| declaration-specifiers ';'
		;

declaration-specifiers: INT;

init-declarator-list: init-declarator
					  | init-declarator-list ',' init-declarator
					  ;

init-declarator: IDENT;
expr: ;
/*** FUNCTIONS ****************************************************************/
func: ;

%%

int main()
{
	yyin = stdin;
	do { 
		yyparse();
	} while(!feof(yyin));
	return 0;
}

void yyerror(const char* s)
{
	fprintf(stderr, "Parse error: %s\n", s);
	exit(1);
}
