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

int			ft_printf(const char *str, ...)__attribute__ ((format (printf, 1, 2)));
char		*ft_accurate_string(char *type_str, t_format *format);
char		*ft_cat_at_start(char *type_str, int len, int to_cat);
char		*ft_integer_accurate_str(char *type_str, t_format *format);
char		*ft_get_less_option_str(char *type_str, t_format *format, int len);
int			ft_isnt_flags(char c);
int			ft_isnt_format(char c);
void		ft_get_format_flags(char **str, int* flags);
int			ft_get_format_width(char **str);
int			ft_get_format_precision(char **str);
int			ft_get_format_size(char **str);
int			ft_get_format_type(char **str);
t_format	*ft_get_format_info(char *str);
t_format 	*init_format(void);
char		*ft_dec_hh_flag(va_list arg);
char		*ft_dec_h_flag(va_list arg);
char		*ft_dec_ll_flag(va_list arg);
char		*ft_dec_l_flag(va_list arg);

#endif
