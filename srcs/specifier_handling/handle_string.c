#include "ft_printf.h"

char *handle_string(t_arg_info arg_info, va_list *vargs)
{
	return (add_padding(ft_strdup(va_arg(*vargs, char *)), arg_info));
}