/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 23:34:55 by jucollet          #+#    #+#             */
/*   Updated: 2020/02/17 00:02:37 by jucollet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/includes/libft.h"
# include <stdarg.h>
# include <limits.h>

typedef enum	e_type {
	CHAR = 0b0000000000000001,
	STRING = 0b0000000000000010,
	POINTER = 0b0000000000000100,
	INTEGER = 0b0000000000001000,
	OCTAL = 0b0000000000010000,
	UNDECI = 0b0000000000100000,
	UNHEXA = 0b0000000001000000,
	UNHEXAUP = 0b0000000010000000,
	FLOAT = 0b0000000100000000,
	UINT = 0b0000001000000000,
	PERCENT = 0b0000010000000000,
	CHARNULL = 0b0000100000000000
}				t_type;

typedef enum	e_flags {
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
}				t_flags;

typedef struct	s_format {
	int flags;
	int width;
	int precision;
	int size;
	int type;
}				t_format;

int				ft_printf(const char
				*str, ...) __attribute__((format(printf,1,2)));
int				ft_defined_format_char(char c);
char			*ft_accurate_string(char *type_str, t_format *format);
char			*ft_cat_at_start(char *type_str, int len, int to_cat);
char			*ft_get_less_option_str(char *type_str, t_format *format,
																int len);
int				ft_isnt_flags(char c);
int				ft_isnt_format(char c);
int				ft_constuct_str(char *ref, va_list arg);
int				ft_jump_format(char *str, t_format *format);
int				ft_get_format_width(char **str);
t_format		*ft_get_format_info(char **str);
t_format		*init_format(void);
t_format		*ft_flags_cancel(t_format *format);
char			*ft_dec_hh_flag(va_list arg);
char			*ft_dec_h_flag(va_list arg);
char			*ft_dec_ll_flag(va_list arg);
char			*ft_dec_l_flag(va_list arg);
char			*ft_unsigned_hh_flag(va_list arg, t_format *format);
char			*ft_unsigned_h_flag(va_list arg, t_format *format);
char			*ft_unsigned_ll_flag(va_list arg, t_format *format);
char			*ft_unsigned_l_flag(va_list arg, t_format *format);
char			*ft_unsigned_int(va_list arg, t_format *format);
int				ft_get_width_len(t_format *format, char *type_str,
													char *ref_str);
char			*ft_zero_width(t_format *format, char *type_str, char *ref_str);
char			*ft_put_hash_flag(t_format *format, char *type_str,
													char *ref_str);
char			*ft_put_sign(char *type_str, char *ref_str, t_format *format);
char			*ft_space_width(char *type_str, t_format *format);
char			*ft_formatstr_null_case(char *ref_str);
char			*ft_format_string(va_list arg, t_format *format);
char			*ft_get_type_string(va_list arg, t_format *format);
char			*ft_get_type_string(va_list arg, t_format *format);
char			*ft_integer(va_list arg, t_format *format);
char			*ft_hexadecimal(va_list arg, t_format *format);
char			*ft_hexadecimalupper(va_list arg, t_format *format);
char			*ft_octal(va_list arg, t_format *format);
char			*ft_char_ptr(va_list arg);
char			*ft_cat_at_start(char *type_str, int len, int to_cat);
void			ft_get_format_flags(char **str, int *flags);
#endif
