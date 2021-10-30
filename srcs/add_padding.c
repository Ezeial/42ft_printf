#include "ft_printf.h"

char *add_padding(char *computed_str, t_arg_info arg_info)
{
	char *new_str;

	if (arg_info.width > ft_strlen(computed_str))
	{
		new_str = malloc(arg_info.width * sizeof(char));
		if (!new_str)
			return (NULL);
		if (arg_info.flag == '0')
			ft_memset(new_str, '0', arg_info.width);
		else
			ft_memset(new_str, ' ', arg_info.width);
		if (arg_info.flag == '-')
			ft_memcpy(new_str, computed_str, ft_strlen(computed_str));
		else
			ft_memcpy(new_str + (arg_info.width - ft_strlen(computed_str)), computed_str, ft_strlen(computed_str));\
		free(computed_str);
		return (new_str);
	}
	return (computed_str);
}