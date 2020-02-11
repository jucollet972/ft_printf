#include "../libft/includes/libft.h"
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>

#ifndef FT_PRINTF
#define FT_PRINTF

typedef enum e_type {
        CHAR =    0b0000000000000001,
        STRING =  0b0000000000000010,
        POINTER = 0b0000000000000100,
        INTEGER = 0b0000000000001000,
        OCTAL   = 0b0000000000010000,
        UNDECI  = 0b0000000000100000,
        UNHEXA  = 0b0000000001000000,
       UNHEXAUP = 0b0000000010000000,
       FLOAT    = 0b0000000100000000,
       UINT     = 0b0000001000000000,
       PERCENT  = 0b0000010000000000,
       CHARNULL = 0b0000100000000000
}                   t_type;

typedef enum e_flags {
     HASH = 0b0000000000000001,
        H = 0b0000000000000010,
       HH = 0b0000000000000100,
        L = 0b0000000000001000,
       LL = 0b0000000000010000,
    BIG_L = 0b0000000000100000,
     ZERO = 0b0000000001000000,
     LESS = 0b0000000010000000,
     MORE = 0b0000000100000000,
    SPACE = 000000001000000000
}                  t_flags;

typedef struct s_format {
    int flags;
    int width;
    int precision;
    int size;
    int type;
}               t_format;

int ft_printf(const char *str, ...)__attribute__ ((format (printf, 1, 2)));
#endif
