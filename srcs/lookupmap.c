#include "ft_printf.h" 

t_lookup g_lookupmap[] = {
	{
		.specifier = 'd',
		.callback = handle_decimal
	},
	{
		.specifier = 's',
		.callback = handle_string
	},
	{
		.specifier = 'c',
		.callback = handle_char
	},
	{
		.specifier = 'x',
		.callback = handle_hexa
	},
	{
		.specifier = 'p',
		.callback = handle_pointer
	},
	{
		.specifier = '\0',
		.callback = NULL
	}   
};

t_lookup get_into_map(t_specifier specifier)
{
	size_t	i;

	i = 0;
	while (g_lookupmap[i].specifier)
	{
		if (g_lookupmap[i].specifier == specifier)
			break;
		i++;
	}
	return (g_lookupmap[i]);
}
