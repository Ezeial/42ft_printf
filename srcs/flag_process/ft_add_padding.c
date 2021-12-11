#include "ft_printf.h"

char *ft_add_padding(char *current_str, t_arg arg)
{
	size_t	len;
	char	*padded_str;

	len = ft_strlen(current_str);
	if (len > arg.width)
		return (ft_strdup(current_str));
	padded_str = (char *)malloc(sizeof(char) * (arg.width + 1));
	if (!padded_str)
		return (NULL);
	if (arg.flags & ZPAD)
	{
		ft_memset(padded_str, '0', arg.width - len);
		ft_memcpy(padded_str + (arg.width - len), current_str, len);
		padded_str[arg.width] = 0;
	}
	else if (arg.flags & LJUSTIFY)
	{
		ft_memcpy(padded_str, current_str, len);
		ft_memset(padded_str + len, ' ', arg.width - len);
		padded_str[arg.width] = 0;
	}
	else
	{
		ft_memset(padded_str, ' ', arg.width - len);
		ft_memcpy(padded_str + (arg.width - len), current_str, len);
		padded_str[arg.width] = 0;
	}
	return (padded_str);
}