#include "ft_printf.h"

char *handle_string(t_arg arg, va_list *vargs)
{
	return (ft_add_padding(va_arg(*vargs, char *), arg));
}