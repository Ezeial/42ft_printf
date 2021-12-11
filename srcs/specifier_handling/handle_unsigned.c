#include "ft_printf.h"

char	*handle_unsigned(t_arg arg, va_list *vargs)
{
	char	*raw_str;
	char	*precise_str;
	char	*signed_str;
	char	*padded_str;

	raw_str = ft_itoa_un(va_arg(*vargs, unsigned int));
	if (!raw_str)
		return (NULL);
	precise_str = ft_add_precision(raw_str, arg);
	if (!precise_str)
		return (NULL);
	signed_str = ft_add_sign(precise_str, arg);
	if (!signed_str)
		return (NULL);
	padded_str = ft_add_padding(signed_str, arg);
	if (!padded_str)
		return (NULL);
	free(raw_str);
	free(precise_str);
	free(signed_str);
	return (padded_str);
}

