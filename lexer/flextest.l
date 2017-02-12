%option noyywrap

%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "tokens-manual.h" // Enumerated token classes

/* Token semantic value */
typedef union 
{
	long l_int;
	long long ll_int;
	unsigned long ul_int;
	unsigned long long ull_int;
} integer_types;

typedef union 
{
	double dbl;
	long double l_dbl;
	float flt;
} floating_types;

typedef enum num_types
{
	INTEGER,
	LONG_INTEGER,
	LONGLONG_INTEGER,
	UNSIGNED_INTEGER,
	UNSIGNED_LONG_INTEGER,
	UNSIGNED_LONGLONG_INTEGER,
	FLOAT_REAL,
	DOUBLE_REAL,
	LONG_DOUBLE_REAL
} num_types;
num_types current_num_type;

typedef union
{
	char *string;
	char character;
	integer_types integer;
	floating_types floating;
} YYSTYPE;
YYSTYPE yylval;

/* Error message or linemarkers */
int current_line = 1;
char current_file[FILENAME_MAX];
int str_length;



typedef enum tokens token;
%}

DIGIT [0-9]
OCTAL [0-7]
HEX	[0-9A-Fa-f]	

%x sc_linemarker
%x sc_char
%x sc_string

%%

							char str_buf[512];
							char *str_ptr;
 /*** LINEMARKERS *************************************************************/
^#" "{DIGIT}+				{BEGIN(sc_linemarker); current_line = atoi(&yytext[2]);}
<sc_linemarker>{
	{DIGIT}+				{current_line = atoi(yytext);}
	\".+?\"					{strncpy(current_file, yytext + 1, strlen(yytext) - 1); current_file[strlen(yytext) - 2] = '\0';} /* Need to extend regex to handle contrived filenames */
	[ \t\r]+				/* silently consume whitespace */
	\n						{BEGIN(INITIAL);}
}

 /*** CHARACTER LITERALS ******************************************************/
\'							{BEGIN(sc_char);}
<sc_char>{
	\n						{fprintf(stderr, "%s:%d:Error:Unterminated char literal\n", current_file, current_line);}
	/* \\[0'\"\?\\abfntrv]		{ */
								/* if (str_ptr == str_buf) */
								/* { */
									/* *str_ptr++ = '\\';  */
									/* *str_ptr++ = yytext[1]; */
								/* } */
								/* else */
									/* fprintf(stderr, "%s:%d:Warning:Unsupported multibyte character literal truncated to first byte\n", current_file, current_line); */
									
							/* } */
	\\0\'						{BEGIN(INITIAL); yylval.character = '\0'; token t = CHARLIT; return t;}
	\\'\'						{BEGIN(INITIAL); yylval.character = '\''; token t = CHARLIT; return t;}
	\\\"\'					{BEGIN(INITIAL); yylval.character = '\"'; token t = CHARLIT; return t;}
	\\\?\'					{BEGIN(INITIAL); yylval.character = '\?'; token t = CHARLIT; return t;}
	\\\\\'					{BEGIN(INITIAL); yylval.character = '\\'; token t = CHARLIT; return t;}
	\\a\'						{BEGIN(INITIAL); yylval.character = '\a'; token t = CHARLIT; return t;}
	\\b\'						{BEGIN(INITIAL); yylval.character = '\b'; token t = CHARLIT; return t;}
	\\f\'						{BEGIN(INITIAL); yylval.character = '\f'; token t = CHARLIT; return t;}
	\\n\'						{BEGIN(INITIAL); yylval.character = '\n'; token t = CHARLIT; return t;}
	\\t\'						{BEGIN(INITIAL); yylval.character = '\t'; token t = CHARLIT; return t;}
	\\r\'						{BEGIN(INITIAL); yylval.character = '\r'; token t = CHARLIT; return t;}
	\\v\'						{BEGIN(INITIAL); yylval.character = '\v'; token t = CHARLIT; return t;}
	\\[0-7]{1,3}\'			{/* octal escape sequence */
								BEGIN(INITIAL);
								int result;
								(void) sscanf(yytext + 1, "%o", &result);
								yylval.character = result;
								if ( result > 0xff )
									fprintf(stderr, "%s:%d:Warning:Octal escape sequence \\0%o out of range\n", current_file, current_line, result);
								token t = CHARLIT;
								return t;
							}
	\\x[0-9A-Fa-f]+\'			{/* hex escape sequence */
								BEGIN(INITIAL);
								int result;
								(void) sscanf(yytext + 2, "%x", &result);
								yylval.character = result;
								if ( result > 0xff )
									fprintf(stderr, "%s:%d:Warning:Hex escape sequence \\x%x out of range\n", current_file, current_line, result);
								token t = CHARLIT;
								return t;
							}
	[^\\\n\"]\'				{BEGIN(INITIAL); yylval.character = yytext[0]; token t = CHARLIT; return t;}

	.*\'						{
								BEGIN(INITIAL);
								yylval.character = yytext[0];
								fprintf(stderr, "%s:%d:Warning:Unsupported multibyte character literal truncated to first byte sequence.\n", current_file, current_line);
							}
}	

 /*** STRING LITERALS *********************************************************/
\"							{BEGIN(sc_string); str_ptr = str_buf;}
<sc_string>{
	\n						{fprintf(stderr, "%s:%d:Error:Unterminated string literal\n", current_file, current_line);}
	\\0						{*str_ptr++ = '\0';}
	\\'						{*str_ptr++ = '\'';}
	\\\"					{*str_ptr++ = '\"';}
	\\\?					{*str_ptr++ = '\?';}
	\\\\					{*str_ptr++ = '\\';}
	\\a						{*str_ptr++ = '\a';}
	\\b						{*str_ptr++ = '\b';}
	\\f						{*str_ptr++ = '\f';}
	\\n						{*str_ptr++ = '\n';}
	\\t						{*str_ptr++ = '\t';}
	\\r						{*str_ptr++ = '\r';}
	\\v						{*str_ptr++ = '\v';}
	\\[0-7]{1,3}			{/* octal escape sequence */
							int result;
							(void) sscanf(yytext + 1, "%o", &result);
							*str_ptr++ = result;
							if ( result > 0xff )
								fprintf(stderr, "%s:%d:Warning:Octal escape \\0%o sequence out of range\n", current_file, current_line, result);
						}
	\\x[0-9A-Fa-f]+			{/* hex escape sequence */
								int result;
								(void) sscanf(yytext + 2, "%x", &result);
								*str_ptr++ = result;
								if ( result > 0xff )
									fprintf(stderr, "%s:%d:Warning:Hex escape sequence \\x%x out of range\n", current_file, current_line, result);
							}
	/* \\{DIGIT}+				{ */
								/* fprintf(stderr, "%s:%d: Error: bad escape sequence\n", current_file, current_line); */
							/* } */
	/* \\(.|\n)				{*str_ptr++ = yytext[1];} */
	[^\\\n\"]+				{
								char *yptr = yytext;
								while (*yptr)
									*str_ptr++ = *yptr++;
							}
	/* [^\"\n]*				{yylval.string = yytext; token t = STRING; return t;} */
	\"						{
								BEGIN(INITIAL); 
								str_length = str_ptr - str_buf; 
								yylval.string = malloc(sizeof(str_buf));
								memcpy(yylval.string, str_buf, str_length);
								token t = STRING; 
								return t;
							}

}

 /*** KEYWORDS ****************************************************************/
auto						{token t = AUTO; return t;}
break						{token t = BREAK; return t;}
case						{token t = CASE; return t;}
char						{token t = CHAR; return t;}
const						{token t = CONST; return t;}
continue					{token t = CONTINUE; return t;}
default						{token t = DEFAULT; return t;}
do							{token t = DO; return t;}
double						{token t = DOUBLE; return t;}
else						{token t = ELSE; return t;}
enum						{token t = ENUM; return t;}
extern						{token t = EXTERN; return t;}
float						{token t = FLOAT; return t;}
for							{token t = FOR; return t;}
goto						{token t = GOTO; return t;}
if							{token t = IF; return t;}
inline						{token t = INLINE; return t;}
int							{token t = INT; return t;}
long						{token t = LONG; return t;}
register					{token t = REGISTER; return t;}
restrict					{token t = RESTRICT; return t;}
return						{token t = RETURN; return t;}
short						{token t = SHORT; return t;}
signed						{token t = SIGNED; return t;}
sizeof						{token t = SIZEOF; return t;}
static						{token t = STATIC; return t;}
struct						{token t = STRUCT; return t;}
switch						{token t = SWITCH; return t;}
typedef						{token t = TYPEDEF; return t;}
union						{token t = UNION; return t;}
unsigned					{token t = UNSIGNED; return t;}
void						{token t = VOID; return t;}
volatile					{token t = VOLATILE; return t;}
while						{token t = WHILE; return t;}
_Bool						{token t = _BOOL; return t;}
_Complex					{token t = _COMPLEX; return t;}
_Imaginary					{token t = _IMAGINARY; return t;}

 /*** IDENTIFIERS *************************************************************/
[_A-Za-z][_A-Za-z0-9]*		{yylval.string = yytext; token t = IDENT; return t;}

 /*** PUNCTUATORS *************************************************************/
"\["						{return *yytext;}
"\]"						{return *yytext;}
"\("						{return *yytext;}
"\)"						{return *yytext;}
"\{"						{return *yytext;}
"\}"						{return *yytext;}
"\."						{return *yytext;}
"&"							{return *yytext;}
"\*"						{return *yytext;}
"\+"						{return *yytext;}
"\-"						{return *yytext;}
"~"							{return *yytext;}
"!"							{return *yytext;}
"\/"						{return *yytext;}
"%"							{return *yytext;}
"\<"						{return *yytext;}
"\>"						{return *yytext;}
"\^"						{return *yytext;}
"\|"						{return *yytext;}
"\?"						{return *yytext;}
":"							{return *yytext;}
";"							{return *yytext;}
"="							{return *yytext;}
","							{return *yytext;}
"#"							{return *yytext;}
\-\>						{token t = INDSEL; return t;}	
\+\+						{token t = PLUSPLUS; return t;}
\-\-						{token t = MINUSMINUS; return t;}
\<\<						{token t = SHL; return t;}
\>\>						{token t = SHR; return t;}
\<=							{token t = LTEQ; return t;}
\>=							{token t = GTEQ; return t;}
==							{token t = EQEQ; return t;}
\!=							{token t = NOTEQ; return t;}
&&							{token t = LOGAND; return t;}
\|\|						{token t = LOGOR; return t;}
\.\.\.						{token t = ELLIPSIS; return t;}
\*=							{token t = TIMESEQ; return t;}
\/=							{token t = DIVEQ; return t;}
%=							{token t = MODEQ; return t;}
\+=							{token t = PLUSEQ; return t;}
\-=							{token t = MINUSEQ; return t;}
\<\<=						{token t = SHLEQ; return t;}
\>\>=						{token t = SHREQ; return t;}
&=							{token t = ANDEQ; return t;}
\|=							{token t = OREQ; return t;}
\^=							{token t = XOREQ; return t;}

 /*** NUMBERS *****************************************************************/

	/* Ints */
[1-9]{DIGIT}*				{current_num_type = INTEGER; yylval.integer.l_int = strtol(yytext, NULL, 10); token t = NUMBER; return t;}
0{OCTAL}*					{current_num_type = INTEGER; yylval.integer.l_int = strtol(yytext, NULL, 8);  token t = NUMBER; return t;}
0[xX]{HEX}+					{current_num_type = INTEGER; yylval.integer.l_int = strtol(yytext, NULL, 16); token t = NUMBER; return t;}

	/* Long ints */
[1-9]{DIGIT}*[lL]			{current_num_type = LONG_INTEGER; yylval.integer.l_int = strtol(yytext, NULL, 10); token t = NUMBER; return t;}
0{OCTAL}*[lL]				{current_num_type = LONG_INTEGER; yylval.integer.l_int = strtol(yytext, NULL, 8); token t = NUMBER; return t;}
0[xX]{HEX}+[lL]				{current_num_type = LONG_INTEGER; yylval.integer.l_int = strtol(yytext, NULL, 16); token t = NUMBER; return t;}

	/* Long long ints */
[1-9]{DIGIT}*(ll|LL)		{current_num_type = LONGLONG_INTEGER; yylval.integer.ll_int = strtoll(yytext, NULL, 10); token t = NUMBER; return t;}
0{OCTAL}*(ll|LL)			{current_num_type = LONGLONG_INTEGER; yylval.integer.ll_int = strtoll(yytext, NULL, 8); token t = NUMBER; return t;}
0[xX]{HEX}+(ll|LL)			{current_num_type = LONGLONG_INTEGER; yylval.integer.ll_int = strtoll(yytext, NULL, 16); token t = NUMBER; return t;}
	
	/* Unsigned ints */
[1-9]{DIGIT}*[uU]			{current_num_type = UNSIGNED_INTEGER; yylval.integer.ul_int = strtoul(yytext, NULL, 10); token t = NUMBER; return t;}
0{OCTAL}*[uU]				{current_num_type = UNSIGNED_INTEGER; yylval.integer.ul_int = strtoul(yytext, NULL, 8); token t = NUMBER; return t;}
0[xX]{HEX}+[uU]				{current_num_type = UNSIGNED_INTEGER; yylval.integer.ul_int = strtoul(yytext, NULL, 16); token t = NUMBER; return t;}

	/* Unsigned long ints */
[1-9]{DIGIT}*([uU][lL]|[lL][uU])		{current_num_type = UNSIGNED_LONG_INTEGER; yylval.integer.ul_int = strtoul(yytext, NULL, 10); token t = NUMBER; return t;}
0{OCTAL}*([uU][lL]|[lL][uU])			{current_num_type = UNSIGNED_LONG_INTEGER; yylval.integer.ul_int = strtoul(yytext, NULL, 8); token t = NUMBER; return t;}
0[xX]{HEX}+([uU][lL]|[lL][uU])			{current_num_type = UNSIGNED_LONG_INTEGER; yylval.integer.ul_int = strtoul(yytext, NULL, 16); token t = NUMBER; return t;}

	/* Unsigned long long ints */
[1-9]{DIGIT}*([uU](ll|LL)|(ll|LL)[uU])	{current_num_type = UNSIGNED_LONGLONG_INTEGER; yylval.integer.ull_int = strtoull(yytext, NULL, 10); token t = NUMBER; return t;}
0{OCTAL}*([uU](ll|LL)|(ll|LL)[uU])		{current_num_type = UNSIGNED_LONGLONG_INTEGER; yylval.integer.ull_int = strtoull(yytext, NULL, 8); token t = NUMBER; return t;}
0[xX]{HEX}+([uU](ll|LL)|(ll|LL)[uU])	{current_num_type = UNSIGNED_LONGLONG_INTEGER; yylval.integer.ull_int = strtoull(yytext, NULL, 16); token t = NUMBER; return t;}

	/* Double */
(({DIGIT}*\.{DIGIT}+|{DIGIT}+\.)([eE][\+-]?{DIGIT}+)?|{DIGIT}+[eE][\+-]?{DIGIT}+)		{current_num_type = DOUBLE_REAL; yylval.floating.dbl = strtod(yytext, NULL); token t = NUMBER; return t;}
0[xX](({HEX}*\.{HEX}+|{HEX}+\.)([pP][\+-]?{DIGIT}+)?|{HEX}+[pP][\+-]?{DIGIT}+)			{current_num_type = DOUBLE_REAL; yylval.floating.dbl = strtod(yytext, NULL); token t = NUMBER; return t;}

	/* Long double */
(({DIGIT}*\.{DIGIT}+|{DIGIT}+\.)([eE][\+-]?{DIGIT}+)?|{DIGIT}+[eE][\+-]?{DIGIT}+)[lL]	{current_num_type = LONG_DOUBLE_REAL; yylval.floating.l_dbl = strtold(yytext, NULL); token t = NUMBER; return t;}
0[xX](({HEX}*\.{HEX}+|{HEX}+\.)([pP][\+-]?{DIGIT}+)?|{HEX}+[pP][\+-]?{DIGIT}+)[lL]		{current_num_type = LONG_DOUBLE_REAL; yylval.floating.l_dbl = strtold(yytext, NULL); token t = NUMBER; return t;}

	/* Float */
(({DIGIT}*\.{DIGIT}+|{DIGIT}+\.)([eE][\+-]?{DIGIT}+)?|{DIGIT}+[eE][\+-]?{DIGIT}+)[fF]	{current_num_type = FLOAT_REAL; yylval.floating.flt = strtof(yytext, NULL); token t = NUMBER; return t;}
0[xX](({HEX}*\.{HEX}+|{HEX}+\.)([pP][\+-]?{DIGIT}+)?|{HEX}+[pP][\+-]?{DIGIT}+)[fF]		{current_num_type = FLOAT_REAL; yylval.floating.flt = strtof(yytext, NULL); token t = NUMBER; return t;}



 /*** MISC ********************************************************************/
<*><<EOF>>					{token t = TOKEOF; return t;}
\n							{++current_line;}
[ \t\r]+					/* silently consume whitespace */
.							{fprintf(stderr, "Error: unrecognized character '%s'\n", yytext);}	/* Unrecognized token */

%%

int main()
{
	/* Token class returned from yylex() */
	int t;
	char c;
	char buf[512];
	while (t = yylex())
	{
		printf("%s	%d	", current_file, current_line);
		switch(t)
		{
			case CHARLIT:
/* \\[0'\"\?\\abfntrv] */
				printf("CHARLIT");
				switch(yylval.character)
				{
					case '\0': printf("\t\\0\n"); break;
					case '\'': printf("\t\\\'\n"); break;
					case '\"': printf("\t\\\"\n"); break;
					case '\?': printf("\t\\?\n"); break;
					case '\\': printf("\t\\\\\n"); break;
					case '\a': printf("\t\\a\n"); break;
					case '\b': printf("\t\\b\n"); break;
					case '\f': printf("\t\\f\n"); break;
					case '\n': printf("\t\\n\n"); break;
					case '\t': printf("\t\\t\n"); break;
					case '\r': printf("\t\\r\n"); break;
					case '\v': printf("\t\\v\n"); break;
					default: 
						if (isprint(yylval.character))
							printf("\t%c\n", yylval.character); 
						else
							printf("\t%03o\n", yylval.character); 
						break;
				}
				break;
			case STRING:
				printf("STRING\t");
				for (int i = 0; i < str_length; ++i)
				{
					c = *yylval.string++;
					switch(c)
					{
						case '\0': printf("\\0"); break;
						case '\'': printf("\\'"); break;
						case '\"': printf("\\\""); break;
						case '\?': printf("\?"); break;
						case '\\': printf("\\\\"); break;
						case '\a': printf("\\a"); break;
						case '\b': printf("\\b"); break;
						case '\f': printf("\\f"); break;
						case '\n': printf("\\n"); break;
						case '\t': printf("\\t"); break;
						case '\r': printf("\\r"); break;
						case '\v': printf("\\v"); break;
						default: 
							if (isprint(c))
								printf("%c", c); 
							else
								printf("\\%03o", c); 
							break;
					}
				}
				printf("\n");
				break;
			case IDENT:
				printf("IDENT\t%s\n", yylval.string);
				break;
			case NUMBER:
				printf("NUMBER");
				switch (current_num_type)
				{
					case INTEGER:
						printf("\tINTEGER\t%lld\tINT\n", yylval.integer.l_int);
						break;
					case LONG_INTEGER:
						printf("\tINTEGER\t%lld\tLONG\n", yylval.integer.l_int);
						break;
					case LONGLONG_INTEGER:
						printf("\tINTEGER\t%lld\tLONGLONG\n", yylval.integer.ll_int);
						break;
					case UNSIGNED_INTEGER:
						printf("\tINTEGER\t%lld\tUNSIGNED,INT\n", yylval.integer.ul_int);
						break;
					case UNSIGNED_LONG_INTEGER:
						printf("\tINTEGER\t%lld\tUNSIGNED,LONG\n", yylval.integer.ul_int);
						break;
					case UNSIGNED_LONGLONG_INTEGER:
						printf("\tINTEGER\t%lld\tUNSIGNED,LONGLONG\n", yylval.integer.ull_int);
						break;
					case FLOAT_REAL:
						printf("\tREAL\t%lg\tFLOAT\n", yylval.floating.flt);
						break;
					case DOUBLE_REAL:
						printf("\tREAL\t%lg\tDOUBLE\n", yylval.floating.dbl);
						break;
					case LONG_DOUBLE_REAL:
						printf("\tREAL\t%Lg\tLONGDOUBLE\n", yylval.floating.l_dbl);
						break;	
				}
				break;
			case AUTO:
				printf("AUTO\n");
				break;
			case BREAK:
				printf("BREAK\n");
				break;
			case CASE:
				printf("CASE\n");
				break;
			case CHAR:
				printf("CHAR\n");
				break;
			case CONST:
				printf("CONST\n");
				break;
			case CONTINUE:
				printf("CONTINUE\n");
				break;
			case DEFAULT:
				printf("DEFAULT\n");
				break;
			case DO:
				printf("BREAK\n");
				break;
			case DOUBLE:
				printf("DOUBLE\n");
				break;
			case ELSE:
				printf("ELSE\n");
				break;
			case ENUM:
				printf("ENUM\n");
				break;
			case EXTERN:
				printf("EXTERN\n");
				break;
			case FLOAT:
				printf("FLOAT\n");
				break;
			case FOR:
				printf("FOR\n");
				break;
			case GOTO:
				printf("GOTO\n");
				break;
			case IF:
				printf("IF\n");
				break;
			case INLINE:
				printf("INLINE\n");
				break;
			case INT:
				printf("INT\n");
				break;
			case LONG:
				printf("LONG\n");
				break;
			case REGISTER:
				printf("REGISTER\n");
				break;
			case RESTRICT:
				printf("RESTRICT\n");
				break;
			case RETURN:
				printf("RETURN\n");
				break;
			case SHORT:
				printf("SHORT\n");
				break;
			case SIGNED:
				printf("SIGNED\n");
				break;
			case SIZEOF:
				printf("SIZEOF\n");
				break;
			case STATIC:
				printf("STATIC\n");
				break;
			case STRUCT:
				printf("STRUCT\n");
				break;
			case SWITCH:
				printf("SWITCH\n");
				break;
			case TYPEDEF:
				printf("TYPEDEF\n");
				break;
			case UNION:
				printf("UNION\n");
				break;
			case UNSIGNED:
				printf("UNSIGNED\n");
				break;
			case VOID:
				printf("VOID\n");
				break;
			case VOLATILE:
				printf("VOLATILE\n");
				break;
			case WHILE:
				printf("WHILE\n");
				break;
			case _BOOL:
				printf("_BOOL\n");
				break;
			case _COMPLEX:
				printf("_COMPLEX\n");
				break;
			case _IMAGINARY:
				printf("_IMAGINARY\n");
				break;
			case '[':
				printf("[\n");
				break;
			case ']':
				printf("]\n");
				break;
			case '(':
				printf("(\n");
				break;
			case ')':
				printf(")\n");
				break;
			case '{':
				printf("{\n");
				break;
			case '}':
				printf("}\n");
				break;
			case '.':
				printf(".\n");
				break;
			case '&':
				printf("&\n");
				break;
			case '*':
				printf("*\n");
				break;
			case '+':
				printf("+\n");
				break;
			case '-':
				printf("-\n");
				break;
			case '~':
				printf("~\n");
				break;
			case '!':
				printf("!\n");
				break;
			case '/':
				printf("/\n");
				break;
			case '%':
				printf("%\n");
				break;
			case '<':
				printf("<\n");
				break;
			case '>':
				printf(">\n");
				break;
			case '^':
				printf("^\n");
				break;
			case '|':
				printf("|\n");
				break;
			case '?':
				printf("?\n");
				break;
			case ':':
				printf(":\n");
				break;
			case ';':
				printf(";\n");
				break;
			case '=':
				printf("=\n");
				break;
			case ',':
				printf(",\n");
				break;
			case '#':
				printf("#\n");
				break;
			case INDSEL:
				printf("INDSEL\n");
				break;
			case PLUSPLUS:
				printf("PLUSPLUS\n");
				break;
			case MINUSMINUS:
				printf("MINUSMINUS\n");
				break;
			case SHL:
				printf("SHL\n");
				break;
			case SHR:
				printf("SHR\n");
				break;
			case LTEQ:
				printf("LTEQ\n");
				break;
			case GTEQ:
				printf("GTEQ\n");
				break;
			case EQEQ:
				printf("EQEQ\n");
				break;
			case NOTEQ:
				printf("NOTEQ\n");
				break;
			case LOGAND:
				printf("LOGAND\n");
				break;
			case LOGOR:
				printf("LOGOR\n");
				break;
			case ELLIPSIS:
				printf("ELLIPSIS\n");
				break;
			case TIMESEQ:
				printf("TIMESEQ\n");
				break;
			case DIVEQ:
				printf("DIVEQ\n");
				break;
			case MODEQ:
				printf("MODEQ\n");
				break;
			case PLUSEQ:
				printf("PLUSEQ\n");
				break;
			case MINUSEQ:
				printf("MINUSEQ\n");
				break;
			case SHLEQ:
				printf("SHLEQ\n");
				break;
			case SHREQ:
				printf("SHREQ\n");
				break;
			case ANDEQ:
				printf("ANDEQ\n");
				break;
			case OREQ:
				printf("OREQ\n");
				break;
			case XOREQ:
				printf("XOREQ\n");
				break;
			default: 
				printf("%s\n", yylval.string);
				break;
		}
	}
}

