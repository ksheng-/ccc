%option noyywrap

%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "ptypes.h"
#include "ast.h"
#include "parser.tab.h"
/* #include "tokens-manual.h" // Enumerated token classes */
// #include "parser.h"
/* Token semantic value */

/* Error message or linemarkers */
extern int current_line;
extern char current_file[FILENAME_MAX];
int str_length;


%}

DIGIT [0-9]
OCTAL [0-7]
HEX [0-9A-Fa-f] 

%x sc_linemarker
%x sc_char
%x sc_string

%%

                            char str_buf[512];
                            char *str_ptr;
 /*** LINEMARKERS *************************************************************/
^#" "{DIGIT}+               {BEGIN(sc_linemarker); current_line = atoi(&yytext[2]);}
<sc_linemarker>{
    {DIGIT}+                {current_line = atoi(yytext);}
    \".+?\"                 {strncpy(current_file, yytext + 1, strlen(yytext) - 1); current_file[strlen(yytext) - 2] = '\0';} /* Need to extend regex to handle contrived filenames */
    [ \t\r]+                /* silently consume whitespace */
    \n                      {BEGIN(INITIAL);}
}

 /*** CHARACTER LITERALS ******************************************************/
\'                          {BEGIN(sc_char);}
<sc_char>{
    \n                      {fprintf(stderr, "%s:%d:Error:Unterminated char literal\n", current_file, current_line);}
    /* \\[0'\"\?\\abfntrv]      { */
                                /* if (str_ptr == str_buf) */
                                /* { */
                                    /* *str_ptr++ = '\\';  */
                                    /* *str_ptr++ = yytext[1]; */
                                /* } */
                                /* else */
                                    /* fprintf(stderr, "%s:%d:Warning:Unsupported multibyte character literal truncated to first byte\n", current_file, current_line); */
                                    
                            /* } */
    \\0\'                   {BEGIN(INITIAL); yylval.character = '\0'; return CHARLIT;}
    \\'\'                   {BEGIN(INITIAL); yylval.character = '\''; return CHARLIT;}
    \\\"\'                  {BEGIN(INITIAL); yylval.character = '\"'; return CHARLIT;}
    \\\?\'                  {BEGIN(INITIAL); yylval.character = '\?'; return CHARLIT;}
    \\\\\'                  {BEGIN(INITIAL); yylval.character = '\\'; return CHARLIT;}
    \\a\'                   {BEGIN(INITIAL); yylval.character = '\a'; return CHARLIT;}
    \\b\'                   {BEGIN(INITIAL); yylval.character = '\b'; return CHARLIT;}
    \\f\'                   {BEGIN(INITIAL); yylval.character = '\f'; return CHARLIT;}
    \\n\'                   {BEGIN(INITIAL); yylval.character = '\n'; return CHARLIT;}
    \\t\'                   {BEGIN(INITIAL); yylval.character = '\t'; return CHARLIT;}
    \\r\'                   {BEGIN(INITIAL); yylval.character = '\r'; return CHARLIT;}
    \\v\'                   {BEGIN(INITIAL); yylval.character = '\v'; return CHARLIT;}
    \\[0-7]{1,3}\'          {/* octal escape sequence */
                                BEGIN(INITIAL);
                                int result;
                                (void) sscanf(yytext + 1, "%o", &result);
                                yylval.character = result;
                                if ( result > 0xff )
                                    fprintf(stderr, "%s:%d:Warning:Octal escape sequence \\0%o out of range\n", current_file, current_line, result);
                                return CHARLIT;
                            }
    \\x[0-9A-Fa-f]+\'       {/* hex escape sequence */
                                BEGIN(INITIAL);
                                int result;
                                (void) sscanf(yytext + 2, "%x", &result);
                                yylval.character = result;
                                if ( result > 0xff )
                                    fprintf(stderr, "%s:%d:Warning:Hex escape sequence \\x%x out of range\n", current_file, current_line, result);
                                return CHARLIT;
                            }
    [^\\\n\"]\'             {BEGIN(INITIAL); yylval.character = yytext[0]; return CHARLIT;}

    .*\'                    {
                                BEGIN(INITIAL);
                                yylval.character = yytext[0];
                                fprintf(stderr, "%s:%d:Warning:Unsupported multibyte character literal truncated to first byte sequence.\n", current_file, current_line);
                            }
}   

 /*** STRING LITERALS *********************************************************/
\"                          {BEGIN(sc_string); str_ptr = str_buf;}
<sc_string>{
    \n                      {fprintf(stderr, "%s:%d:Error:Unterminated string literal\n", current_file, current_line);}
    \\0                     {*str_ptr++ = '\0';}
    \\'                     {*str_ptr++ = '\'';}
    \\\"                    {*str_ptr++ = '\"';}
    \\\?                    {*str_ptr++ = '\?';}
    \\\\                    {*str_ptr++ = '\\';}
    \\a                     {*str_ptr++ = '\a';}
    \\b                     {*str_ptr++ = '\b';}
    \\f                     {*str_ptr++ = '\f';}
    \\n                     {*str_ptr++ = '\n';}
    \\t                     {*str_ptr++ = '\t';}
    \\r                     {*str_ptr++ = '\r';}
    \\v                     {*str_ptr++ = '\v';}
    \\[0-7]{1,3}            {/* octal escape sequence */
                            int result;
                            (void) sscanf(yytext + 1, "%o", &result);
                            *str_ptr++ = result;
                            if ( result > 0xff )
                                fprintf(stderr, "%s:%d:Warning:Octal escape \\0%o sequence out of range\n", current_file, current_line, result);
                        }
    \\x[0-9A-Fa-f]+         {/* hex escape sequence */
                                int result;
                                (void) sscanf(yytext + 2, "%x", &result);
                                *str_ptr++ = result;
                                if ( result > 0xff )
                                    fprintf(stderr, "%s:%d:Warning:Hex escape sequence \\x%x out of range\n", current_file, current_line, result);
                            }
    /* \\{DIGIT}+               { */
                                /* fprintf(stderr, "%s:%d: Error: bad escape sequence\n", current_file, current_line); */
                            /* } */
    /* \\(.|\n)             {*str_ptr++ = yytext[1];} */
    [^\\\n\"]+              {
                                char *yptr = yytext;
                                while (*yptr)
                                    *str_ptr++ = *yptr++;
                            }
    /* [^\"\n]*             {yylval.string = yytext; token t = STRING; return t;} */
    \"                      {
                                BEGIN(INITIAL); 
                                str_length = str_ptr - str_buf; 
                                yylval.string = malloc(sizeof(str_buf));
                                memcpy(yylval.string, str_buf, str_length);
                                return STRING;
                            }

}

 /*** KEYWORDS ****************************************************************/
auto                        {return AUTO;}
break                       {return BREAK;}
case                        {return CASE;}
char                        {return CHAR;}
const                       {return CONST;}
continue                    {return CONTINUE;}
default                     {return DEFAULT;}
do                          {return DO;}
double                      {return DOUBLE;}
else                        {return ELSE;}
enum                        {return ENUM;}
extern                      {return EXTERN;}
float                       {return FLOAT;}
for                         {return FOR;}
goto                        {return GOTO;}
if                          {return IF;}
inline                      {return INLINE;}
int                         {return INT;}
long                        {return LONG;}
register                    {return REGISTER;}
restrict                    {return RESTRICT;}
return                      {return RETURN;}
short                       {return SHORT;}
signed                      {return SIGNED;}
sizeof                      {return SIZEOF;}
static                      {return STATIC;}
struct                      {return STRUCT;}
switch                      {return SWITCH;}
typedef                     {return TYPEDEF;}
union                       {return UNION;}
unsigned                    {return UNSIGNED;}
void                        {return VOID;}
volatile                    {return VOLATILE;}
while                       {return WHILE;}
_Bool                       {return _BOOL;}
_Complex                    {return _COMPLEX;}
_Imaginary                  {return _IMAGINARY;}

 /*** IDENTIFIERS *************************************************************/
[_A-Za-z][_A-Za-z0-9]*      {yylval.string = yytext; return IDENT;}

 /*** PUNCTUATORS *************************************************************/
"\["                        {return *yytext;}
"\]"                        {return *yytext;}
"\("                        {return *yytext;}
"\)"                        {return *yytext;}
"\{"                        {return *yytext;}
"\}"                        {return *yytext;}
"\."                        {return *yytext;}
"&"                         {return *yytext;}
"\*"                        {return *yytext;}
"\+"                        {return *yytext;}
"\-"                        {return *yytext;}
"~"                         {return *yytext;}
"!"                         {return *yytext;}
"\/"                        {return *yytext;}
"%"                         {return *yytext;}
"\<"                        {return *yytext;}
"\>"                        {return *yytext;}
"\^"                        {return *yytext;}
"\|"                        {return *yytext;}
"\?"                        {return *yytext;}
":"                         {return *yytext;}
";"                         {return *yytext;}
"="                         {return *yytext;}
","                         {return *yytext;}
"#"                         {return *yytext;}
\-\>                        {return INDSEL;}   
\+\+                        {return PLUSPLUS;}
\-\-                        {return MINUSMINUS;}
\<\<                        {return SHL;}
\>\>                        {return SHR;}
\<=                         {return LTEQ;}
\>=                         {return GTEQ;}
==                          {return EQEQ;}
\!=                         {return NOTEQ;}
&&                          {return LOGAND;}
\|\|                        {return LOGOR;}
\.\.\.                      {return ELLIPSIS;}
\*=                         {return TIMESEQ;}
\/=                         {return DIVEQ;}
%=                          {return MODEQ;}
\+=                         {return PLUSEQ;}
\-=                         {return MINUSEQ;}
\<\<=                       {return SHLEQ;}
\>\>=                       {return SHREQ;}
&=                          {return ANDEQ;}
\|=                         {return OREQ;}
\^=                         {return XOREQ;}

 /*** NUMBERS *****************************************************************/

    /* Ints */
[1-9]{DIGIT}*               {yylval.number.type = INTEGER; yylval.number.value.l_int = strtol(yytext, NULL, 10);  return NUMBER;}
0{OCTAL}*                   {yylval.number.type = INTEGER; yylval.number.value.l_int = strtol(yytext, NULL, 8);   return NUMBER;}
0[xX]{HEX}+                 {yylval.number.type = INTEGER; yylval.number.value.l_int = strtol(yytext, NULL, 16);  return NUMBER;}

    /* Long ints */
[1-9]{DIGIT}*[lL]           {yylval.number.type = LONG_INTEGER; yylval.number.value.l_int = strtol(yytext, NULL, 10); return NUMBER;}
0{OCTAL}*[lL]               {yylval.number.type = LONG_INTEGER; yylval.number.value.l_int = strtol(yytext, NULL, 8); return NUMBER;}
0[xX]{HEX}+[lL]             {yylval.number.type = LONG_INTEGER; yylval.number.value.l_int = strtol(yytext, NULL, 16); return NUMBER;}

    /* Long long ints */
[1-9]{DIGIT}*(ll|LL)        {yylval.number.type = LONGLONG_INTEGER; yylval.number.value.ll_int = strtoll(yytext, NULL, 10); return NUMBER;}
0{OCTAL}*(ll|LL)            {yylval.number.type = LONGLONG_INTEGER; yylval.number.value.ll_int = strtoll(yytext, NULL, 8); return NUMBER;}
0[xX]{HEX}+(ll|LL)          {yylval.number.type = LONGLONG_INTEGER; yylval.number.value.ll_int = strtoll(yytext, NULL, 16); return NUMBER;}
    
    /* Unsigned ints */
[1-9]{DIGIT}*[uU]           {yylval.number.type = UNSIGNED_INTEGER; yylval.number.value.ul_int = strtoul(yytext, NULL, 10); return NUMBER;}
0{OCTAL}*[uU]               {yylval.number.type = UNSIGNED_INTEGER; yylval.number.value.ul_int = strtoul(yytext, NULL, 8); return NUMBER;}
0[xX]{HEX}+[uU]             {yylval.number.type = UNSIGNED_INTEGER; yylval.number.value.ul_int = strtoul(yytext, NULL, 16); return NUMBER;}

    /* Unsigned long ints */
[1-9]{DIGIT}*([uU][lL]|[lL][uU])        {yylval.number.type = UNSIGNED_LONG_INTEGER; yylval.number.value.ul_int = strtoul(yytext, NULL, 10); return NUMBER;}
0{OCTAL}*([uU][lL]|[lL][uU])            {yylval.number.type = UNSIGNED_LONG_INTEGER; yylval.number.value.ul_int = strtoul(yytext, NULL, 8); return NUMBER;}
0[xX]{HEX}+([uU][lL]|[lL][uU])          {yylval.number.type = UNSIGNED_LONG_INTEGER; yylval.number.value.ul_int = strtoul(yytext, NULL, 16); return NUMBER;}

    /* Unsigned long long ints */
[1-9]{DIGIT}*([uU](ll|LL)|(ll|LL)[uU])  {yylval.number.type = UNSIGNED_LONGLONG_INTEGER; yylval.number.value.ull_int = strtoull(yytext, NULL, 10); return NUMBER;}
0{OCTAL}*([uU](ll|LL)|(ll|LL)[uU])      {yylval.number.type = UNSIGNED_LONGLONG_INTEGER; yylval.number.value.ull_int = strtoull(yytext, NULL, 8); return NUMBER;}
0[xX]{HEX}+([uU](ll|LL)|(ll|LL)[uU])    {yylval.number.type = UNSIGNED_LONGLONG_INTEGER; yylval.number.value.ull_int = strtoull(yytext, NULL, 16); return NUMBER;}

    /* Double */
(({DIGIT}*\.{DIGIT}+|{DIGIT}+\.)([eE][\+-]?{DIGIT}+)?|{DIGIT}+[eE][\+-]?{DIGIT}+)       {yylval.number.type = DOUBLE_REAL; yylval.number.value.dbl = strtod(yytext, NULL); return NUMBER;}
0[xX](({HEX}*\.{HEX}+|{HEX}+\.)([pP][\+-]?{DIGIT}+)?|{HEX}+[pP][\+-]?{DIGIT}+)          {yylval.number.type = DOUBLE_REAL; yylval.number.value.dbl = strtod(yytext, NULL); return NUMBER;}

    /* Long double */
(({DIGIT}*\.{DIGIT}+|{DIGIT}+\.)([eE][\+-]?{DIGIT}+)?|{DIGIT}+[eE][\+-]?{DIGIT}+)[lL]   {yylval.number.type = LONG_DOUBLE_REAL; yylval.number.value.l_dbl = strtold(yytext, NULL); return NUMBER;}
0[xX](({HEX}*\.{HEX}+|{HEX}+\.)([pP][\+-]?{DIGIT}+)?|{HEX}+[pP][\+-]?{DIGIT}+)[lL]      {yylval.number.type = LONG_DOUBLE_REAL; yylval.number.value.l_dbl = strtold(yytext, NULL); return NUMBER;}

    /* Float */
(({DIGIT}*\.{DIGIT}+|{DIGIT}+\.)([eE][\+-]?{DIGIT}+)?|{DIGIT}+[eE][\+-]?{DIGIT}+)[fF]   {yylval.number.type = FLOAT_REAL; yylval.number.value.flt = strtof(yytext, NULL); return NUMBER;}
0[xX](({HEX}*\.{HEX}+|{HEX}+\.)([pP][\+-]?{DIGIT}+)?|{HEX}+[pP][\+-]?{DIGIT}+)[fF]      {yylval.number.type = FLOAT_REAL; yylval.number.value.flt = strtof(yytext, NULL); return NUMBER;}



 /*** MISC ********************************************************************/
<*><<EOF>>                  {return TOKEOF;}
\n                          {++current_line;}
[ \t\r]+                    /* silently consume whitespace */
.                           {fprintf(stderr, "Error: unrecognized character '%s'\n", yytext);}  /* Unrecognized token */

%%

/* int main() */
/* { */
    /* [> Token class returned from yylex() <] */
    /* int t; */
    /* char c; */
    /* char buf[512]; */
    /* while (t = yylex()) */
    /* { */
        /* printf("%s  %d  ", current_file, current_line); */
        /* switch(t) */
        /* { */
            /* case CHARLIT: */
/* [> \\[0'\"\?\\abfntrv] <] */
                /* printf("CHARLIT"); */
                /* switch(yylval.character) */
                /* { */
                    /* case '\0': printf("\t\\0\n"); break; */
                    /* case '\'': printf("\t\\\'\n"); break; */
                    /* case '\"': printf("\t\\\"\n"); break; */
                    /* case '\?': printf("\t\\?\n"); break; */
                    /* case '\\': printf("\t\\\\\n"); break; */
                    /* case '\a': printf("\t\\a\n"); break; */
                    /* case '\b': printf("\t\\b\n"); break; */
                    /* case '\f': printf("\t\\f\n"); break; */
                    /* case '\n': printf("\t\\n\n"); break; */
                    /* case '\t': printf("\t\\t\n"); break; */
                    /* case '\r': printf("\t\\r\n"); break; */
                    /* case '\v': printf("\t\\v\n"); break; */
                    /* default:  */
                        /* if (isprint(yylval.character)) */
                            /* printf("\t%c\n", yylval.character);  */
                        /* else */
                            /* printf("\t%03o\n", yylval.character);  */
                        /* break; */
                /* } */
                /* break; */
            /* case STRING: */
                /* printf("STRING\t"); */
                /* for (int i = 0; i < str_length; ++i) */
                /* { */
                    /* c = *yylval.string++; */
                    /* switch(c) */
                    /* { */
                        /* case '\0': printf("\\0"); break; */
                        /* case '\'': printf("\\'"); break; */
                        /* case '\"': printf("\\\""); break; */
                        /* case '\?': printf("\?"); break; */
                        /* case '\\': printf("\\\\"); break; */
                        /* case '\a': printf("\\a"); break; */
                        /* case '\b': printf("\\b"); break; */
                        /* case '\f': printf("\\f"); break; */
                        /* case '\n': printf("\\n"); break; */
                        /* case '\t': printf("\\t"); break; */
                        /* case '\r': printf("\\r"); break; */
                        /* case '\v': printf("\\v"); break; */
                        /* default:  */
                            /* if (isprint(c)) */
                                /* printf("%c", c);  */
                            /* else */
                                /* printf("\\%03o", c);  */
                            /* break; */
                    /* } */
                /* } */
                /* printf("\n"); */
                /* break; */
            /* case IDENT: */
                /* printf("IDENT\t%s\n", yylval.string); */
                /* break; */
            /* case NUMBER: */
                /* printf("NUMBER"); */
                /* switch (current_num_type) */
                /* { */
                    /* case INTEGER: */
                        /* printf("\tINTEGER\t%lld\tINT\n", yylval.integer.l_int); */
                        /* break; */
                    /* case LONG_INTEGER: */
                        /* printf("\tINTEGER\t%lld\tLONG\n", yylval.integer.l_int); */
                        /* break; */
                    /* case LONGLONG_INTEGER: */
                        /* printf("\tINTEGER\t%lld\tLONGLONG\n", yylval.integer.ll_int); */
                        /* break; */
                    /* case UNSIGNED_INTEGER: */
                        /* printf("\tINTEGER\t%lld\tUNSIGNED,INT\n", yylval.integer.ul_int); */
                        /* break; */
                    /* case UNSIGNED_LONG_INTEGER: */
                        /* printf("\tINTEGER\t%lld\tUNSIGNED,LONG\n", yylval.integer.ul_int); */
                        /* break; */
                    /* case UNSIGNED_LONGLONG_INTEGER: */
                        /* printf("\tINTEGER\t%lld\tUNSIGNED,LONGLONG\n", yylval.integer.ull_int); */
                        /* break; */
                    /* case FLOAT_REAL: */
                        /* printf("\tREAL\t%lg\tFLOAT\n", yylval.floating.flt); */
                        /* break; */
                    /* case DOUBLE_REAL: */
                        /* printf("\tREAL\t%lg\tDOUBLE\n", yylval.floating.dbl); */
                        /* break; */
                    /* case LONG_DOUBLE_REAL: */
                        /* printf("\tREAL\t%Lg\tLONGDOUBLE\n", yylval.floating.l_dbl); */
                        /* break;   */
                /* } */
                /* break; */
            /* case AUTO: */
                /* printf("AUTO\n"); */
                /* break; */
            /* case BREAK: */
                /* printf("BREAK\n"); */
                /* break; */
            /* case CASE: */
                /* printf("CASE\n"); */
                /* break; */
            /* case CHAR: */
                /* printf("CHAR\n"); */
                /* break; */
            /* case CONST: */
                /* printf("CONST\n"); */
                /* break; */
            /* case CONTINUE: */
                /* printf("CONTINUE\n"); */
                /* break; */
            /* case DEFAULT: */
                /* printf("DEFAULT\n"); */
                /* break; */
            /* case DO: */
                /* printf("BREAK\n"); */
                /* break; */
            /* case DOUBLE: */
                /* printf("DOUBLE\n"); */
                /* break; */
            /* case ELSE: */
                /* printf("ELSE\n"); */
                /* break; */
            /* case ENUM: */
                /* printf("ENUM\n"); */
                /* break; */
            /* case EXTERN: */
                /* printf("EXTERN\n"); */
                /* break; */
            /* case FLOAT: */
                /* printf("FLOAT\n"); */
                /* break; */
            /* case FOR: */
                /* printf("FOR\n"); */
                /* break; */
            /* case GOTO: */
                /* printf("GOTO\n"); */
                /* break; */
            /* case IF: */
                /* printf("IF\n"); */
                /* break; */
            /* case INLINE: */
                /* printf("INLINE\n"); */
                /* break; */
            /* case INT: */
                /* printf("INT\n"); */
                /* break; */
            /* case LONG: */
                /* printf("LONG\n"); */
                /* break; */
            /* case REGISTER: */
                /* printf("REGISTER\n"); */
                /* break; */
            /* case RESTRICT: */
                /* printf("RESTRICT\n"); */
                /* break; */
            /* case RETURN: */
                /* printf("RETURN\n"); */
                /* break; */
            /* case SHORT: */
                /* printf("SHORT\n"); */
                /* break; */
            /* case SIGNED: */
                /* printf("SIGNED\n"); */
                /* break; */
            /* case SIZEOF: */
                /* printf("SIZEOF\n"); */
                /* break; */
            /* case STATIC: */
                /* printf("STATIC\n"); */
                /* break; */
            /* case STRUCT: */
                /* printf("STRUCT\n"); */
                /* break; */
            /* case SWITCH: */
                /* printf("SWITCH\n"); */
                /* break; */
            /* case TYPEDEF: */
                /* printf("TYPEDEF\n"); */
                /* break; */
            /* case UNION: */
                /* printf("UNION\n"); */
                /* break; */
            /* case UNSIGNED: */
                /* printf("UNSIGNED\n"); */
                /* break; */
            /* case VOID: */
                /* printf("VOID\n"); */
                /* break; */
            /* case VOLATILE: */
                /* printf("VOLATILE\n"); */
                /* break; */
            /* case WHILE: */
                /* printf("WHILE\n"); */
                /* break; */
            /* case _BOOL: */
                /* printf("_BOOL\n"); */
                /* break; */
            /* case _COMPLEX: */
                /* printf("_COMPLEX\n"); */
                /* break; */
            /* case _IMAGINARY: */
                /* printf("_IMAGINARY\n"); */
                /* break; */
            /* case '[': */
                /* printf("[\n"); */
                /* break; */
            /* case ']': */
                /* printf("]\n"); */
                /* break; */
            /* case '(': */
                /* printf("(\n"); */
                /* break; */
            /* case ')': */
                /* printf(")\n"); */
                /* break; */
            /* case '{': */
                /* printf("{\n"); */
                /* break; */
            /* case '}': */
                /* printf("}\n"); */
                /* break; */
            /* case '.': */
                /* printf(".\n"); */
                /* break; */
            /* case '&': */
                /* printf("&\n"); */
                /* break; */
            /* case '*': */
                /* printf("*\n"); */
                /* break; */
            /* case '+': */
                /* printf("+\n"); */
                /* break; */
            /* case '-': */
                /* printf("-\n"); */
                /* break; */
            /* case '~': */
                /* printf("~\n"); */
                /* break; */
            /* case '!': */
                /* printf("!\n"); */
                /* break; */
            /* case '/': */
                /* printf("/\n"); */
                /* break; */
            /* case '%': */
                /* printf("%\n"); */
                /* break; */
            /* case '<': */
                /* printf("<\n"); */
                /* break; */
            /* case '>': */
                /* printf(">\n"); */
                /* break; */
            /* case '^': */
                /* printf("^\n"); */
                /* break; */
            /* case '|': */
                /* printf("|\n"); */
                /* break; */
            /* case '?': */
                /* printf("?\n"); */
                /* break; */
            /* case ':': */
                /* printf(":\n"); */
                /* break; */
            /* case ';': */
                /* printf(";\n"); */
                /* break; */
            /* case '=': */
                /* printf("=\n"); */
                /* break; */
            /* case ',': */
                /* printf(",\n"); */
                /* break; */
            /* case '#': */
                /* printf("#\n"); */
                /* break; */
            /* case INDSEL: */
                /* printf("INDSEL\n"); */
                /* break; */
            /* case PLUSPLUS: */
                /* printf("PLUSPLUS\n"); */
                /* break; */
            /* case MINUSMINUS: */
                /* printf("MINUSMINUS\n"); */
                /* break; */
            /* case SHL: */
                /* printf("SHL\n"); */
                /* break; */
            /* case SHR: */
                /* printf("SHR\n"); */
                /* break; */
            /* case LTEQ: */
                /* printf("LTEQ\n"); */
                /* break; */
            /* case GTEQ: */
                /* printf("GTEQ\n"); */
                /* break; */
            /* case EQEQ: */
                /* printf("EQEQ\n"); */
                /* break; */
            /* case NOTEQ: */
                /* printf("NOTEQ\n"); */
                /* break; */
            /* case LOGAND: */
                /* printf("LOGAND\n"); */
                /* break; */
            /* case LOGOR: */
                /* printf("LOGOR\n"); */
                /* break; */
            /* case ELLIPSIS: */
                /* printf("ELLIPSIS\n"); */
                /* break; */
            /* case TIMESEQ: */
                /* printf("TIMESEQ\n"); */
                /* break; */
            /* case DIVEQ: */
                /* printf("DIVEQ\n"); */
                /* break; */
            /* case MODEQ: */
                /* printf("MODEQ\n"); */
                /* break; */
            /* case PLUSEQ: */
                /* printf("PLUSEQ\n"); */
                /* break; */
            /* case MINUSEQ: */
                /* printf("MINUSEQ\n"); */
                /* break; */
            /* case SHLEQ: */
                /* printf("SHLEQ\n"); */
                /* break; */
            /* case SHREQ: */
                /* printf("SHREQ\n"); */
                /* break; */
            /* case ANDEQ: */
                /* printf("ANDEQ\n"); */
                /* break; */
            /* case OREQ: */
                /* printf("OREQ\n"); */
                /* break; */
            /* case XOREQ: */
                /* printf("XOREQ\n"); */
                /* break; */
            /* default:  */
                /* printf("%s\n", yylval.string); */
                /* break; */
        /* } */
    /* } */
 /* } */

