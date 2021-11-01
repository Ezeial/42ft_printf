#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

typedef unsigned char t_flag;
typedef unsigned char t_specifier;


typedef struct arg_info {
	t_specifier specifier;
	t_flag		flag;
	size_t		width;
	size_t		precision;
} t_arg_info;

typedef struct lookup {
	t_specifier specifier;
	char *(*callback)(t_arg_info, va_list*);
} t_lookup;


t_lookup get_into_map(t_specifier specifier);
int parse_arg(char **format, t_arg_info *arg_info, va_list *vargs);
char *add_padding(char *computed_str, t_arg_info arg_info);

char *handle_decimal(t_arg_info arg_info, va_list *vargs);
char *handle_string(t_arg_info arg_info, va_list *vargs);
char *handle_char(t_arg_info arg_info, va_list *vargs);
char *handle_hexa(t_arg_info arg_info, va_list *vargs);
char *handle_pointer(t_arg_info arg_info, va_list *vargs);

int ft_printf(char *format, ...);

#endif