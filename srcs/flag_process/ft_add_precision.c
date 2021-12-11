#include "ft_printf.h"

char *ft_add_precision(char *current_str, t_arg arg)
{
	size_t	len;
	char	*precise_str;

	if (current_str[0] == '0' && arg.precision == 0)
		return (ft_strdup(""));
	len = ft_strlen(current_str);
	if (current_str[0] == '-' && arg.precision > (len - 1))
	{
		precise_str = (char *)malloc(sizeof(char) * (arg.precision + 2));
		if (!precise_str)
			return (NULL);
		precise_str[0] = '-';
		ft_memset(precise_str + 1, '0', arg.precision - (len - 1));
		ft_strlcpy(precise_str + (arg.precision - (len - 1) + 1), current_str + 1, (arg.precision + 1));
		return (precise_str);
	}
	if (arg.precision > len)
	{
		precise_str = (char *)malloc(sizeof(char) * (arg.precision + 1));
		if (!precise_str)
			return (NULL);
		ft_memset(precise_str, '0', arg.precision - len);
		ft_strlcpy(precise_str + (arg.precision - len), current_str, arg.precision);
		return (precise_str);
	}
	return (ft_strdup(current_str));
}