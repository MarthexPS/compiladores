/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "hoc6.y"

#include "hoc.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <signal.h>
#include <setjmp.h>

#define code2(c1,c2)     code(c1); code(c2)
#define code3(c1,c2,c3)  code(c1); code(c2); \
code(c3) /* La \ es crucial para multilínea */

int indef = 0;
jmp_buf begin;
char    *progname;
int    lineno = 1 ;
char   *infile;       /* nombre de archivo de entrada */
FILE    *fin;
/* apuntador a archivo de entrada */
char   **gargv;       /* lista global de argumentos */
int    gargc;
int c;                /* global, para uso de warning() */


#line 96 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    NUMBER = 258,                  /* NUMBER  */
    STRING = 259,                  /* STRING  */
    PRINT = 260,                   /* PRINT  */
    VAR = 261,                     /* VAR  */
    BLTIN = 262,                   /* BLTIN  */
    UNDEF = 263,                   /* UNDEF  */
    WHILE = 264,                   /* WHILE  */
    IF = 265,                      /* IF  */
    ELSE = 266,                    /* ELSE  */
    FUNCTION = 267,                /* FUNCTION  */
    PROCEDURE = 268,               /* PROCEDURE  */
    RETURN = 269,                  /* RETURN  */
    FUNC = 270,                    /* FUNC  */
    PROC = 271,                    /* PROC  */
    READ = 272,                    /* READ  */
    ARG = 273,                     /* ARG  */
    OR = 274,                      /* OR  */
    AND = 275,                     /* AND  */
    GT = 276,                      /* GT  */
    GE = 277,                      /* GE  */
    LT = 278,                      /* LT  */
    LE = 279,                      /* LE  */
    EQ = 280,                      /* EQ  */
    NE = 281,                      /* NE  */
    UNARYMINUS = 282,              /* UNARYMINUS  */
    NOT = 283                      /* NOT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define NUMBER 258
#define STRING 259
#define PRINT 260
#define VAR 261
#define BLTIN 262
#define UNDEF 263
#define WHILE 264
#define IF 265
#define ELSE 266
#define FUNCTION 267
#define PROCEDURE 268
#define RETURN 269
#define FUNC 270
#define PROC 271
#define READ 272
#define ARG 273
#define OR 274
#define AND 275
#define GT 276
#define GE 277
#define LT 278
#define LE 279
#define EQ 280
#define NE 281
#define UNARYMINUS 282
#define NOT 283

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 26 "hoc6.y"

    Symbol     *sym;
/* Apuntador a la tabla de símbolos */
    Inst       *inst;
/* instrucción de máquina */
    int        narg;
/* número de argumentos */

#line 214 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUMBER = 3,                     /* NUMBER  */
  YYSYMBOL_STRING = 4,                     /* STRING  */
  YYSYMBOL_PRINT = 5,                      /* PRINT  */
  YYSYMBOL_VAR = 6,                        /* VAR  */
  YYSYMBOL_BLTIN = 7,                      /* BLTIN  */
  YYSYMBOL_UNDEF = 8,                      /* UNDEF  */
  YYSYMBOL_WHILE = 9,                      /* WHILE  */
  YYSYMBOL_IF = 10,                        /* IF  */
  YYSYMBOL_ELSE = 11,                      /* ELSE  */
  YYSYMBOL_FUNCTION = 12,                  /* FUNCTION  */
  YYSYMBOL_PROCEDURE = 13,                 /* PROCEDURE  */
  YYSYMBOL_RETURN = 14,                    /* RETURN  */
  YYSYMBOL_FUNC = 15,                      /* FUNC  */
  YYSYMBOL_PROC = 16,                      /* PROC  */
  YYSYMBOL_READ = 17,                      /* READ  */
  YYSYMBOL_ARG = 18,                       /* ARG  */
  YYSYMBOL_19_ = 19,                       /* '='  */
  YYSYMBOL_OR = 20,                        /* OR  */
  YYSYMBOL_AND = 21,                       /* AND  */
  YYSYMBOL_GT = 22,                        /* GT  */
  YYSYMBOL_GE = 23,                        /* GE  */
  YYSYMBOL_LT = 24,                        /* LT  */
  YYSYMBOL_LE = 25,                        /* LE  */
  YYSYMBOL_EQ = 26,                        /* EQ  */
  YYSYMBOL_NE = 27,                        /* NE  */
  YYSYMBOL_28_ = 28,                       /* '+'  */
  YYSYMBOL_29_ = 29,                       /* '-'  */
  YYSYMBOL_30_ = 30,                       /* '*'  */
  YYSYMBOL_31_ = 31,                       /* '/'  */
  YYSYMBOL_UNARYMINUS = 32,                /* UNARYMINUS  */
  YYSYMBOL_NOT = 33,                       /* NOT  */
  YYSYMBOL_34_ = 34,                       /* '^'  */
  YYSYMBOL_35_n_ = 35,                     /* '\n'  */
  YYSYMBOL_36_ = 36,                       /* '('  */
  YYSYMBOL_37_ = 37,                       /* ')'  */
  YYSYMBOL_38_ = 38,                       /* '{'  */
  YYSYMBOL_39_ = 39,                       /* '}'  */
  YYSYMBOL_40_ = 40,                       /* ','  */
  YYSYMBOL_YYACCEPT = 41,                  /* $accept  */
  YYSYMBOL_list = 42,                      /* list  */
  YYSYMBOL_asgn = 43,                      /* asgn  */
  YYSYMBOL_stmt = 44,                      /* stmt  */
  YYSYMBOL_cond = 45,                      /* cond  */
  YYSYMBOL_while = 46,                     /* while  */
  YYSYMBOL_if = 47,                        /* if  */
  YYSYMBOL_begin = 48,                     /* begin  */
  YYSYMBOL_end = 49,                       /* end  */
  YYSYMBOL_stmtlist = 50,                  /* stmtlist  */
  YYSYMBOL_expr = 51,                      /* expr  */
  YYSYMBOL_prlist = 52,                    /* prlist  */
  YYSYMBOL_defn = 53,                      /* defn  */
  YYSYMBOL_54_1 = 54,                      /* $@1  */
  YYSYMBOL_55_2 = 55,                      /* $@2  */
  YYSYMBOL_procname = 56,                  /* procname  */
  YYSYMBOL_arglist = 57                    /* arglist  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   336

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  121

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   283


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      35,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      36,    37,    30,    28,    40,    29,     2,    31,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    19,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    34,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    38,     2,    39,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    20,    21,    22,    23,    24,    25,
      26,    27,    32,    33
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    55,    55,    57,    58,    60,    62,    64,    66,    68,
      70,    72,    76,    79,    82,    83,    85,    87,    90,    92,
     100,   107,   116,   118,   120,   122,   124,   128,   132,   134,
     135,   137,   139,   141,   142,   144,   147,   149,   150,   152,
     154,   156,   158,   160,   162,   164,   166,   168,   170,   172,
     174,   176,   178,   180,   182,   184,   186,   188,   192,   192,
     195,   195,   199,   200,   201,   203,   205,   207
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NUMBER", "STRING",
  "PRINT", "VAR", "BLTIN", "UNDEF", "WHILE", "IF", "ELSE", "FUNCTION",
  "PROCEDURE", "RETURN", "FUNC", "PROC", "READ", "ARG", "'='", "OR", "AND",
  "GT", "GE", "LT", "LE", "EQ", "NE", "'+'", "'-'", "'*'", "'/'",
  "UNARYMINUS", "NOT", "'^'", "'\\n'", "'('", "')'", "'{'", "'}'", "','",
  "$accept", "list", "asgn", "stmt", "cond", "while", "if", "begin", "end",
  "stmtlist", "expr", "prlist", "defn", "$@1", "$@2", "procname",
  "arglist", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-84)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-35)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -84,    76,   -84,   -29,   -84,   175,   -12,    11,   -84,   -84,
     -84,   -84,   203,    -3,    -3,    12,    16,   203,   203,   -84,
     203,   -84,   272,    14,    15,    15,   256,   -84,   -84,   -84,
     -84,   288,     6,   203,   203,    30,    32,   288,   -84,   -84,
     -84,   -84,   -84,    46,   203,    35,    35,     0,   110,   -84,
     -84,   203,   147,   147,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   -84,   195,   288,
     220,   203,   203,    36,    42,    43,   288,   -84,   -84,   -84,
     -84,   288,   238,   -84,   -84,   302,    73,    10,    10,    10,
      10,    10,    10,   -16,   -16,    35,    35,    35,   -84,   288,
     -84,   288,   -35,     5,    47,    50,   -84,   -84,   -84,    95,
     -84,   203,   -84,   147,   147,   147,   288,   -84,   -84,   -84,
     -84
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,     0,    31,     0,    32,     0,    24,    25,
      26,    26,    15,     0,     0,     0,    33,     0,     0,     3,
       0,    28,     6,     8,     0,     0,    10,     4,    11,    55,
      34,    54,    18,     0,     0,     0,     0,    16,    62,    63,
      64,    58,    60,     0,     0,    44,    53,     0,     0,     5,
       7,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     9,     0,    12,
       0,    65,    65,     0,     0,     0,    13,    38,    29,    22,
      30,    14,     0,    27,    27,    52,    51,    45,    46,    47,
      48,    49,    50,    39,    40,    41,    42,    43,    57,    56,
      37,    66,     0,     0,     0,     0,    36,    23,    19,    20,
      35,     0,    17,     0,     0,     0,    67,    59,    61,    27,
      21
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -84,   -84,   107,   -40,    93,   -84,   -84,   114,   -83,   -84,
      -1,   -84,   -84,   -84,   -84,   112,    49
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,    30,    23,    52,    24,    25,    35,   108,    48,
      81,    32,    27,    73,    74,    41,   102
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      26,   109,   110,    38,    31,   111,    28,    33,    80,    39,
      40,    37,    83,    84,    64,    65,    45,    46,    66,    47,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    69,    70,    66,    44,   120,    77,    62,    63,
      64,    65,   112,    76,    66,   111,    68,    34,    43,    50,
      82,    51,    75,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    71,    99,    72,    66,
     101,   101,   104,   117,   118,   119,     2,     3,   105,     4,
     106,     5,     6,     7,   113,     8,     9,   114,    10,    11,
      12,    13,    14,    15,    16,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    17,   115,    66,    22,    18,
     116,    19,    20,     4,    21,     5,     6,     7,    53,     8,
       9,   103,    10,    11,    12,    36,    42,    15,    16,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    17,
       0,     0,     0,    18,     0,    78,    20,     0,    21,    79,
       4,     0,     5,     6,     7,     0,     8,     9,     0,    10,
      11,    12,     0,     0,    15,    16,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    17,     0,     4,    29,
      18,     6,     7,    20,     0,    21,     0,    10,     0,     0,
       0,     0,    15,    16,     0,     0,     0,     0,     4,    98,
       0,     6,     7,     0,    17,     0,     4,    10,    18,     6,
       7,    20,    15,    16,     0,    10,     0,     0,     0,     0,
      15,    16,     0,     0,    17,     0,     0,     0,    18,     0,
       0,    20,    17,     0,     0,     0,    18,     0,     0,    20,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,     0,     0,    66,     0,     0,   100,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
       0,     0,    66,     0,     0,   107,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,     0,     0,
      66,    67,   -34,   -34,   -34,   -34,   -34,   -34,   -34,   -34,
     -34,     0,   -34,   -34,     0,     0,   -34,    49,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
       0,     0,    66,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,     0,     0,    66
};

static const yytype_int8 yycheck[] =
{
       1,    84,    37,     6,     5,    40,    35,    19,    48,    12,
      13,    12,    52,    53,    30,    31,    17,    18,    34,    20,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    33,    34,    34,    19,   119,    37,    28,    29,
      30,    31,    37,    44,    34,    40,    40,    36,    36,    35,
      51,    36,     6,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    36,    68,    36,    34,
      71,    72,    36,   113,   114,   115,     0,     1,    36,     3,
      37,     5,     6,     7,    37,     9,    10,    37,    12,    13,
      14,    15,    16,    17,    18,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    29,    11,    34,     1,    33,
     111,    35,    36,     3,    38,     5,     6,     7,    25,     9,
      10,    72,    12,    13,    14,    11,    14,    17,    18,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    33,    -1,    35,    36,    -1,    38,    39,
       3,    -1,     5,     6,     7,    -1,     9,    10,    -1,    12,
      13,    14,    -1,    -1,    17,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,     3,     4,
      33,     6,     7,    36,    -1,    38,    -1,    12,    -1,    -1,
      -1,    -1,    17,    18,    -1,    -1,    -1,    -1,     3,     4,
      -1,     6,     7,    -1,    29,    -1,     3,    12,    33,     6,
       7,    36,    17,    18,    -1,    12,    -1,    -1,    -1,    -1,
      17,    18,    -1,    -1,    29,    -1,    -1,    -1,    33,    -1,
      -1,    36,    29,    -1,    -1,    -1,    33,    -1,    -1,    36,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    -1,    -1,    34,    -1,    -1,    37,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      -1,    -1,    34,    -1,    -1,    37,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    -1,    -1,
      34,    35,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    -1,    30,    31,    -1,    -1,    34,    35,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      -1,    -1,    34,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    -1,    -1,    34
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    42,     0,     1,     3,     5,     6,     7,     9,    10,
      12,    13,    14,    15,    16,    17,    18,    29,    33,    35,
      36,    38,    43,    44,    46,    47,    51,    53,    35,     4,
      43,    51,    52,    19,    36,    48,    48,    51,     6,    12,
      13,    56,    56,    36,    19,    51,    51,    51,    50,    35,
      35,    36,    45,    45,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    34,    35,    40,    51,
      51,    36,    36,    54,    55,     6,    51,    37,    35,    39,
      44,    51,    51,    44,    44,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,     4,    51,
      37,    51,    57,    57,    36,    36,    37,    37,    49,    49,
      37,    40,    37,    37,    37,    11,    51,    44,    44,    44,
      49
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    42,    42,    42,    42,    42,    42,    42,
      42,    42,    43,    43,    44,    44,    44,    44,    44,    44,
      44,    44,    44,    45,    46,    47,    48,    49,    50,    50,
      50,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    52,    52,    52,    52,    54,    53,
      55,    53,    56,    56,    56,    57,    57,    57
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     3,     2,     3,     2,     3,
       2,     3,     3,     3,     1,     1,     2,     5,     2,     4,
       4,     7,     3,     3,     1,     1,     0,     0,     0,     2,
       2,     1,     1,     1,     1,     5,     4,     4,     3,     3,
       3,     3,     3,     3,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     1,     1,     3,     3,     0,     6,
       0,     6,     1,     1,     1,     0,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 4: /* list: list defn  */
#line 58 "hoc6.y"
                               { code(STOP);
return 1; }
#line 1368 "y.tab.c"
    break;

  case 5: /* list: list asgn '\n'  */
#line 60 "hoc6.y"
                              { code2(pop1, STOP);
return 1; }
#line 1375 "y.tab.c"
    break;

  case 6: /* list: list asgn  */
#line 62 "hoc6.y"
                               { code2(pop1, STOP);
return 1; }
#line 1382 "y.tab.c"
    break;

  case 7: /* list: list stmt '\n'  */
#line 64 "hoc6.y"
                              { code(STOP);
return 1; }
#line 1389 "y.tab.c"
    break;

  case 8: /* list: list stmt  */
#line 66 "hoc6.y"
                               { code(STOP);
return 1; }
#line 1396 "y.tab.c"
    break;

  case 9: /* list: list expr '\n'  */
#line 68 "hoc6.y"
                              { code2(print, STOP);
return 1; }
#line 1403 "y.tab.c"
    break;

  case 10: /* list: list expr  */
#line 70 "hoc6.y"
                               { code2(print, STOP);
return 1; }
#line 1410 "y.tab.c"
    break;

  case 11: /* list: list error '\n'  */
#line 72 "hoc6.y"
                              { yyerrok;
}
#line 1417 "y.tab.c"
    break;

  case 12: /* asgn: VAR '=' expr  */
#line 76 "hoc6.y"
                   { /*puts("VAR = expr ###");*/
              code3(varpush,(Inst)(yyvsp[-2].sym), assign);
(yyval.inst)=(yyvsp[0].inst); }
#line 1425 "y.tab.c"
    break;

  case 13: /* asgn: ARG '=' expr  */
#line 80 "hoc6.y"
     { defnonly("$"); code2(argassign,(Inst)(yyvsp[-2].narg)); (yyval.inst)=(yyvsp[0].inst); }
#line 1431 "y.tab.c"
    break;

  case 14: /* stmt: expr  */
#line 82 "hoc6.y"
                { code(pop1); }
#line 1437 "y.tab.c"
    break;

  case 15: /* stmt: RETURN  */
#line 83 "hoc6.y"
            { defnonly("return"); code(procret);
}
#line 1444 "y.tab.c"
    break;

  case 16: /* stmt: RETURN expr  */
#line 85 "hoc6.y"
                 { defnonly( "return" ); (yyval.inst) = (yyvsp[0].inst); code(funcret); }
#line 1450 "y.tab.c"
    break;

  case 17: /* stmt: PROCEDURE begin '(' arglist ')'  */
#line 88 "hoc6.y"
          { (yyval.inst) = (yyvsp[-3].inst);
code3(call, (Inst)(yyvsp[-4].sym), (Inst)(yyvsp[-1].narg)); }
#line 1457 "y.tab.c"
    break;

  case 18: /* stmt: PRINT prlist  */
#line 90 "hoc6.y"
                   { (yyval.inst) = (yyvsp[0].inst); }
#line 1463 "y.tab.c"
    break;

  case 19: /* stmt: while cond stmt end  */
#line 92 "hoc6.y"
                    {
           /* whilecode estructura: $1           */
           ((yyvsp[-3].inst))[1] = (Inst)(yyvsp[-1].inst);
/* cuerpo del ciclo */
           ((yyvsp[-3].inst))[2] = (Inst)(yyvsp[0].inst);
/* fin, si la condición no se cumple */
       }
#line 1475 "y.tab.c"
    break;

  case 20: /* stmt: if cond stmt end  */
#line 100 "hoc6.y"
                 {    /* if sin else */
           ((yyvsp[-3].inst))[1] = (Inst)(yyvsp[-1].inst);
/* parte then */
           ((yyvsp[-3].inst))[3] = (Inst)(yyvsp[0].inst);
/* fin, si la condición no se cumple */
       }
#line 1486 "y.tab.c"
    break;

  case 21: /* stmt: if cond stmt end ELSE stmt end  */
#line 107 "hoc6.y"
                               {      /* if con else */
           ((yyvsp[-6].inst))[1] = (Inst)(yyvsp[-4].inst);
/* parte then */
           ((yyvsp[-6].inst))[2] = (Inst)(yyvsp[-1].inst);
/* parte else */
           ((yyvsp[-6].inst))[3] = (Inst)(yyvsp[0].inst);
/* fin, si la condición no se cumple */
       }
#line 1499 "y.tab.c"
    break;

  case 22: /* stmt: '{' stmtlist '}'  */
#line 116 "hoc6.y"
                     { (yyval.inst) = (yyvsp[-1].inst); }
#line 1505 "y.tab.c"
    break;

  case 23: /* cond: '(' expr ')'  */
#line 118 "hoc6.y"
                       {  code(STOP);   (yyval.inst) =  (yyvsp[-1].inst);   }
#line 1511 "y.tab.c"
    break;

  case 24: /* while: WHILE  */
#line 120 "hoc6.y"
              { (yyval.inst) = code3(whilecode,STOP,STOP); }
#line 1517 "y.tab.c"
    break;

  case 25: /* if: IF  */
#line 122 "hoc6.y"
             { (yyval.inst) = code(ifcode); code3(STOP,STOP,STOP); }
#line 1523 "y.tab.c"
    break;

  case 26: /* begin: %empty  */
#line 124 "hoc6.y"
                            { (yyval.inst) = progp;
}
#line 1530 "y.tab.c"
    break;

  case 27: /* end: %empty  */
#line 128 "hoc6.y"
                            { code(STOP);
(yyval.inst) = progp; }
#line 1537 "y.tab.c"
    break;

  case 28: /* stmtlist: %empty  */
#line 132 "hoc6.y"
                            { (yyval.inst) = progp;
}
#line 1544 "y.tab.c"
    break;

  case 31: /* expr: NUMBER  */
#line 137 "hoc6.y"
              {   (yyval.inst) = code2(constpush, (Inst)(yyvsp[0].sym)); }
#line 1550 "y.tab.c"
    break;

  case 32: /* expr: VAR  */
#line 139 "hoc6.y"
       {   (yyval.inst) = code3(varpush, (Inst)(yyvsp[0].sym), eval); }
#line 1556 "y.tab.c"
    break;

  case 33: /* expr: ARG  */
#line 141 "hoc6.y"
        {   defnonly("$"); (yyval.inst) = code2(arg, (Inst)(yyvsp[0].narg)); }
#line 1562 "y.tab.c"
    break;

  case 35: /* expr: FUNCTION begin '(' arglist ')'  */
#line 145 "hoc6.y"
           { (yyval.inst) = (yyvsp[-3].inst); code3(call,(Inst)(yyvsp[-4].sym),(Inst)(yyvsp[-1].narg));
}
#line 1569 "y.tab.c"
    break;

  case 36: /* expr: READ '(' VAR ')'  */
#line 147 "hoc6.y"
                      { (yyval.inst) = code2(varread, (Inst)(yyvsp[-1].sym)); }
#line 1575 "y.tab.c"
    break;

  case 37: /* expr: BLTIN '(' expr ')'  */
#line 149 "hoc6.y"
                   { (yyval.inst)=(yyvsp[-1].inst); code2(bltin, (Inst)(yyvsp[-3].sym)->u.ptr); }
#line 1581 "y.tab.c"
    break;

  case 38: /* expr: '(' expr ')'  */
#line 150 "hoc6.y"
                   { (yyval.inst) = (yyvsp[-1].inst);
}
#line 1588 "y.tab.c"
    break;

  case 39: /* expr: expr '+' expr  */
#line 152 "hoc6.y"
                       {   code(add); }
#line 1594 "y.tab.c"
    break;

  case 40: /* expr: expr '-' expr  */
#line 154 "hoc6.y"
                  {   code(sub); }
#line 1600 "y.tab.c"
    break;

  case 41: /* expr: expr '*' expr  */
#line 156 "hoc6.y"
                  {   code(mul); }
#line 1606 "y.tab.c"
    break;

  case 42: /* expr: expr '/' expr  */
#line 158 "hoc6.y"
                  {   code(h_div); }
#line 1612 "y.tab.c"
    break;

  case 43: /* expr: expr '^' expr  */
#line 160 "hoc6.y"
                  {   code(power); }
#line 1618 "y.tab.c"
    break;

  case 44: /* expr: '-' expr  */
#line 162 "hoc6.y"
                             { (yyval.inst)=(yyvsp[0].inst); code(negate); }
#line 1624 "y.tab.c"
    break;

  case 45: /* expr: expr GT expr  */
#line 164 "hoc6.y"
                   { code(gt); }
#line 1630 "y.tab.c"
    break;

  case 46: /* expr: expr GE expr  */
#line 166 "hoc6.y"
                   { code(ge); }
#line 1636 "y.tab.c"
    break;

  case 47: /* expr: expr LT expr  */
#line 168 "hoc6.y"
                   { code(lt); }
#line 1642 "y.tab.c"
    break;

  case 48: /* expr: expr LE expr  */
#line 170 "hoc6.y"
                   { code(le); }
#line 1648 "y.tab.c"
    break;

  case 49: /* expr: expr EQ expr  */
#line 172 "hoc6.y"
                   { code(eq); }
#line 1654 "y.tab.c"
    break;

  case 50: /* expr: expr NE expr  */
#line 174 "hoc6.y"
                   { code(ne); }
#line 1660 "y.tab.c"
    break;

  case 51: /* expr: expr AND expr  */
#line 176 "hoc6.y"
                   { code(and);}
#line 1666 "y.tab.c"
    break;

  case 52: /* expr: expr OR expr  */
#line 178 "hoc6.y"
                   { code(or); }
#line 1672 "y.tab.c"
    break;

  case 53: /* expr: NOT expr  */
#line 180 "hoc6.y"
             { (yyval.inst)= (yyvsp[0].inst); code(not); }
#line 1678 "y.tab.c"
    break;

  case 54: /* prlist: expr  */
#line 182 "hoc6.y"
                           {   code(prexpr);
}
#line 1685 "y.tab.c"
    break;

  case 55: /* prlist: STRING  */
#line 184 "hoc6.y"
                           {    (yyval.inst) = code2(prstr, (Inst)(yyvsp[0].sym));
}
#line 1692 "y.tab.c"
    break;

  case 56: /* prlist: prlist ',' expr  */
#line 186 "hoc6.y"
                           {   code(prexpr); }
#line 1698 "y.tab.c"
    break;

  case 57: /* prlist: prlist ',' STRING  */
#line 188 "hoc6.y"
                      {   code2(prstr, (Inst)(yyvsp[0].sym)); }
#line 1704 "y.tab.c"
    break;

  case 58: /* $@1: %empty  */
#line 192 "hoc6.y"
                       { (yyvsp[0].sym)->type=FUNCTION; indef=1; }
#line 1710 "y.tab.c"
    break;

  case 59: /* defn: FUNC procname $@1 '(' ')' stmt  */
#line 193 "hoc6.y"
                      { code(funcret); define((yyvsp[-4].sym)); indef=0; }
#line 1716 "y.tab.c"
    break;

  case 60: /* $@2: %empty  */
#line 195 "hoc6.y"
              { (yyvsp[0].sym)->type=PROCEDURE; indef=1; }
#line 1722 "y.tab.c"
    break;

  case 61: /* defn: PROC procname $@2 '(' ')' stmt  */
#line 196 "hoc6.y"
                  { code(procret); define((yyvsp[-4].sym)); indef=0; }
#line 1728 "y.tab.c"
    break;

  case 65: /* arglist: %empty  */
#line 203 "hoc6.y"
                          { (yyval.narg) = 0; }
#line 1734 "y.tab.c"
    break;

  case 66: /* arglist: expr  */
#line 205 "hoc6.y"
                     { (yyval.narg) = 1;
}
#line 1741 "y.tab.c"
    break;

  case 67: /* arglist: arglist ',' expr  */
#line 207 "hoc6.y"
                          { (yyval.narg) = (yyvsp[-2].narg) + 1;
}
#line 1748 "y.tab.c"
    break;


#line 1752 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 211 "hoc6.y"


/* fin de la gramática */

/* Implementaciones y utilidades */

/* Prototipos locales para evitar warnings */
int yylex(void);
int backslash(int c);
int follow(int expect, int ifyes, int ifno);
void defnonly(char *s);
void yyerror(char *s);
void execerror(char *s, char *t);
void fpecatch(void);
int moreinput(void);
void run(void);
void warning(char *s, char *t);
int yylex(void){
    /* Ignorar espacios, tab y CR (soporte CRLF) */
    while ((c=getc(fin)) == ' ' || c == '\t' || c == '\r')
        ;
if (c == EOF)
       return 0;
if (isdigit(c)) {   /* n�mero */
      char numbuf[1024], *p = numbuf;
      do {
         if (p >= numbuf + sizeof(numbuf) - 1) {
            *p = '\0';
            execerror("name too long", numbuf);
         }
         *p++ = c;
      } while ((c=getchar()) != EOF && isdigit(c)); // Solo d�gitos
      ungetc(c, stdin);
      *p = '\0';
      
      // Instalar el n�mero grande
      yylval.sym = install("", NUMBER, 0.0); // 0.0 es dummy
      yylval.sym->u.bval = stringToBig(numbuf); // Usar nueva funci�n
      return NUMBER;
   }
   // --- FIN DE SECCI�N MODIFICADA ---

    if (isalpha(c)) { 
      Symbol *s;
      char sbuf[100], *p = sbuf;
      do {
         if (p >= sbuf + sizeof(sbuf) - 1) { 
            *p = '\0'; 
            execerror("name too long", sbuf);
         }
         *p++ = c;
      } while ((c=getc(stdin)) != EOF && isalnum(c)); 
      ungetc(c, stdin); 
      *p = '\0';
      if ((s=lookup(sbuf)) == 0)
         s=install(sbuf, UNDEF, 0.0); // <--- Aquí se usa UNDEF
      yylval.sym = s;
      return s->type == UNDEF ? VAR : s->type; // <--- CAMBIADO DE INDEF A UNDEF
   }
    if (c == '$') { /* ¿argumento?
*/
       int n = 0;
while (isdigit(c=getc(fin)))
           n = 10 * n + c - '0';
ungetc(c, fin);
       if (n == 0)
          execerror("strange $...", (char *)0);
yylval.narg = n;
       return ARG;
    }
    if (c == '"') { /* cadena entre comillas */
       char sbuf[100], *p = sbuf;
       for (; (c=getc(fin)) != '"'; ) {
          if (c == '\n' || c == EOF)
             execerror("missing quote", "");
if (p >= sbuf + sizeof(sbuf) - 1) {
             *p = '\0';
execerror("string too long", sbuf);
          }
          *p++ = backslash(c);
}
       *p = 0;
       
       // INICIO DE CORRECCIÓN (líneas originales en hoc6.y 94-96)
       Symbol *s = install("", STRING, 0.0);
       s->u.str = emalloc(strlen(sbuf)+1);
       strcpy(s->u.str, sbuf);
       yylval.sym = s;
       // FIN DE CORRECCIÓN

       return STRING;
}
    switch (c) {
   case '>':                return follow('=', GE, GT);
   case '<':                return follow('=', LE, LT);
   case '=':                return follow('=', EQ, '=');
   case '!':                return follow('=', NE, NOT);
   case '|':                return follow('|', OR, '|');
   case '&':                return follow('&', AND, '&');
   case '\n':              lineno++; return '\n';
   default:                  return c;
   }
}

int backslash(int c){
    /* tomar siguiente carácter con las \ interpretadas */
    static const char transtab[] = "b\bf\fn\nr\rt\tt";
if (c != '\\')
        return c;
    c = getc(fin);
if (islower(c)) {
        const char *p = strchr(transtab, c);
if (p)
            return p[1];
}
    return c;
}

int follow(int expect,   int ifyes,   int ifno)  { /* buscar  >=, etc.   */ 
   int c  = getchar();
   if  (c  ==  expect)
      return ifyes; 
   ungetc(c,   stdin);
   return  ifno;
}

void defnonly( char *s )     /* advierte si hay definición ilegal */
{
    if (!indef)
       execerror(s, "used outside definition");
}

void yyerror(char *s)      /* comunicar errores de tiempo de compilación */
{
    warning(s, (char *)0);
}

void execerror(char *s, char *t) /* recuperación de errores de tiempo de ejecución */
{
    warning(s, t);
fseek( fin, 0L, 2); /* sacar el resto del archivo */
    longjmp(begin, 0);
}

void fpecatch(void)      /* detectar errores por punto flotante */
{
    execerror("floating point exception", (char *) 0);
}

int moreinput( void ) {
    if (gargc-- <= 0)
       return 0;
if (fin && fin != stdin)
       fclose(fin);
    infile = *gargv++;
    printf("arch ent=(%s)\n",infile);
lineno = 1;
    if (strcmp(infile, "-") == 0) {
       fin = stdin;
infile = 0;
    } else if ((fin=fopen(infile, "r")) == NULL) {
       fprintf(stderr, "%s: can't open %s\n" , progname, infile);
return moreinput();
    }
    return 1;
}

void run(void)   /* ejecutar hasta el fin de archivo (EOF) */
{
    setjmp(begin);
    signal(SIGFPE, (void (*)(int))fpecatch); // <--- CAST NECESARIO
    for (initcode(); yyparse(); initcode()){
        execute(progbase);
    }
}

void warning(char *s, char *t)        /* imprimir mensaje de advertencia   */
{
    fprintf(stderr, "%s: %s", progname, s);
if (t)
       fprintf(stderr, " %s", t);
if (infile)
       fprintf(stderr, " in %s", infile);
    fprintf(stderr, " near line %d\n", lineno);
while (c != '\n' && c != EOF)
       c = getc(fin);
/* sacar el resto del renglón de entrada */
    if (c == '\n')
       lineno++;
}

int main(int argc, char **argv){  /* hoc6 */
    int i;
    void fpecatch();
    progname = argv[0];
if (argc == 1) {        /* simular una lista de argumentos */
       static char *stdinonly[] = { "-" };
gargv = stdinonly;
       gargc = 1;
    } else {
       gargv = argv+1;
gargc = argc-1;
    }
    init();
    while (moreinput())
       run();
    return 0;
}
