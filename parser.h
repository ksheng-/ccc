/* Function type.  */
typedef double (*func_t) (double);

/* Data type for links in the chain of symbols.  */
struct symrec
{
  char *name;  /* name of symbol */
  int type;    /* type of symbol: either VAR or FNCT */
  union
  {
    double var;      /* value of a VAR */
    func_t fnctptr;  /* value of a FNCT */
  } value;
  struct symrec *next;  /* link field */
};

typedef struct symrec symrec;

/* The symbol table: a chain of 'struct symrec'.  */
extern symrec *sym_table;

symrec *putsym (char const *, int);
symrec *getsym (char const *);

enum num_types
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

struct num 
{
    union value
    {
        long l_int;
        long long ll_int;
        unsigned long ul_int;
        unsigned long long ull_int;
        double dbl;
        long double l_dbl;
        float flt;
    } value;
    int type;
};
typedef struct num num;

