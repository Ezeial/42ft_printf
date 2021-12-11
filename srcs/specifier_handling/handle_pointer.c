#include "ft_printf.h"
#include <stdio.h>

char *handle_pointer(t_arg arg, va_list *vargs)
{
	char *raw_str;
	char *precise_str;
	char *hashed_str;
	char *padded_str;

	raw_str = ft_itoa_un_base(va_arg(*vargs, unsigned long), "0123456789abcdef");
	if (!raw_str)
	return (NULL);
	precise_str = ft_add_precision(raw_str, arg);
	if (!precise_str)
		return (NULL);
	hashed_str = ft_add_hash(precise_str, arg);
	if (!hashed_str)
		return (NULL);
	padded_str = ft_add_padding(hashed_str, arg);
	if (!padded_str)
		return (NULL);
	free(raw_str);
	free(precise_str);
	free(hashed_str);
	return (padded_str);
}