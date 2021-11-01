#include "ft_printf.h"

char *handle_hexa(t_arg_info arg_info, va_list *vargs)
{
	char *nb_copy;
	char *result;

	result = add_padding(ft_convert_base(nb_copy = ft_itoa_un(va_arg(*vargs, unsigned int)), "0123456789", "0123456789abcdef"), arg_info);
	free(nb_copy);
	return (result);
}