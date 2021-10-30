#include "ft_printf.h"

char *handle_char(t_arg_info arg_info, va_list *vargs)
{
	char str[2];
	str[0] = va_arg(*vargs, int);
	str[1] = '\0';
	return (add_padding(ft_strdup(str), arg_info));
}