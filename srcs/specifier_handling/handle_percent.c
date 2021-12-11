#include "ft_printf.h"

char	*handle_percent(t_arg arg, va_list *vargs)
{
	char	percent_str[2];

	percent_str[0] = '%';
	percent_str[1] = 0;
	return (ft_add_padding(percent_str, arg));
}