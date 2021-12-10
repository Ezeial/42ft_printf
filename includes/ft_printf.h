/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraldi <egiraldi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:13:28 by egiraldi          #+#    #+#             */
/*   Updated: 2021/12/10 16:13:28 by egiraldi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
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
}	t_flag;

typedef struct arg {
	t_byte		flags;
	size_t		width;
	size_t		precision;
	t_specifier	specifier;
}	t_arg;

typedef struct lookup {
	t_specifier	specifier;
	char		*(*callback)(t_arg, va_list*);
}	t_lookup;

int			ft_is_specifier(t_specifier specifier);
t_lookup	get_into_map(t_specifier specifier);
t_arg		ft_read_arg(char **format, va_list *vargs);

char		*handle_decimal(t_arg arg, va_list *vargs);
char		*handle_string(t_arg arg, va_list *vargs);
char		*handle_char(t_arg arg, va_list *vargs);
char		*handle_hexa(t_arg arg, va_list *vargs);
char		*handle_pointer(t_arg arg, va_list *vargs);

int			ft_printf(char *format, ...);

#endif