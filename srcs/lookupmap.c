/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookupmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraldi <egiraldi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:03:19 by egiraldi          #+#    #+#             */
/*   Updated: 2021/12/10 16:13:12 by egiraldi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_lookup	g_lookupmap[] = {
{
	.specifier = DECIMAL,
	.callback = handle_decimal
},
{
	.specifier = INTEGER,
	.callback = handle_decimal
},
{
	.specifier = UNSIGNED_INTEGER,
	.callback = handle_unsigned
},
{
	.specifier = STRING,
	.callback = handle_string
},
{
	.specifier = CHARACTER,
	.callback = handle_char
},
{
	.specifier = HEXA_LOWER,
	.callback = handle_hexa
},
{
	.specifier = HEXA_UPPER,
	.callback = handle_hexa
},
{
	.specifier = POINTER,
	.callback = handle_pointer
},
{
	.specifier = PERCENT,
	.callback = handle_percent
},
{
	.specifier = INVALID,
	.callback = NULL
}
};

int	ft_is_specifier(t_specifier specifier)
{
	size_t	i;

	i = 0;
	while (g_lookupmap[i].specifier)
	{
		if (g_lookupmap[i].specifier == specifier)
			return (1);
		i++;
	}
	return (0);
}

t_lookup	get_into_map(t_specifier specifier)
{
	size_t	i;

	i = 0;
	while (g_lookupmap[i].specifier)
	{
		if (g_lookupmap[i].specifier == specifier)
			break ;
		i++;
	}
	return (g_lookupmap[i]);
}
