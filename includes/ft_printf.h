/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraldi <egiraldi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:13:28 by egiraldi          #+#    #+#             */
/*   Updated: 2022/05/17 01:40:42 by egiraldi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/includes/libft.h"
# include <stdarg.h>

typedef unsigned char	t_byte;

typedef enum e_specifier {
	CHARACTER = 'c',
	STRING = 's',
	POINTER = 'p',
	DECIMAL = 'd',
	INTEGER = 'i',
	UNSIGNED_INTEGER = 'u',
	HEXA_UPPER = 'X',
	HEXA_LOWER = 'x',
	PERCENT = '%',
	INVALID = 0
}	t_specifier;

typedef enum e_flag {
	LJUSTIFY = 0x01,
	SIGN = 0x02,
	SPACE = 0x04,
	HASH = 0x08,
	ZPAD = 0x10,
	PRECISION = 0x20
}	t_flag;

typedef struct arg {
	t_byte		flags;
	size_t		width;
	size_t		precision;
	t_specifier	specifier;
}	t_arg;

typedef struct lookup {
	t_specifier	specifier;
	char		*(*callback)(t_arg, va_list*, size_t*);
}	t_lookup;

int			ft_is_specifier(t_specifier specifier);
t_lookup	get_into_map(t_specifier specifier);
t_arg		ft_read_arg(char **format, va_list *vargs);

char		*ft_add_precision(char *current_str, t_arg arg);
char		*ft_add_hash(char *current_str, t_arg arg);
char		*ft_add_sign(char *current_str, t_arg arg);
char		*ft_add_padding(char *current_str, t_arg arg);

char		*handle_decimal(t_arg arg, va_list *vargs, size_t *printed_len);
char		*handle_unsigned(t_arg arg, va_list *vargs, size_t *printed_len);
char		*handle_string(t_arg arg, va_list *vargs, size_t *printed_len);
char		*handle_char(t_arg arg, va_list *vargs, size_t *printed_len);
char		*handle_hexa(t_arg arg, va_list *vargs, size_t *printed_len);
char		*handle_pointer(t_arg arg, va_list *vargs, size_t *printed_len);
char		*handle_percent(t_arg arg, va_list *vargs, size_t *printed_len);

int			ft_printf(const char *format, ...);

#endif