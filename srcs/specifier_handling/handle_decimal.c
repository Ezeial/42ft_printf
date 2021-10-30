#include "ft_printf.h"

char *handle_decimal(t_arg_info arg_info, va_list *vargs)
{
	return (add_padding(ft_itoa(va_arg(*vargs, int)), arg_info));
}