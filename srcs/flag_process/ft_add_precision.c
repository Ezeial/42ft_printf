#include "ft_printf.h"

char *ft_add_precision(char *current_str, t_arg arg)
{
	size_t	len;
	char	*precise_str;

	if (ft_atoi(current_str) == 0 && arg.precision == 0)
		return (ft_strdup(""));
	len = ft_strlen(current_str);
	if (arg.precision > len)
	{
		precise_str = (char *)malloc(sizeof(char) * (arg.precision + 1));
		if (!precise_str)
			return (NULL);
		ft_memset(precise_str, '0', arg.precision - len);
		ft_memcpy(precise_str + (arg.precision - len), current_str, len);
		precise_str[arg.precision] = 0;
		// if (ft_atoi(current_str) < 0)
		// {
		// 	precise_str[0] = '-';
		// 	precise_str[arg.precision - len] = '0';
		// }
		return (precise_str);	
	}
	return (ft_strdup(current_str));
}