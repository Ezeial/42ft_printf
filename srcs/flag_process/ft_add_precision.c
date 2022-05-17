/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraldi <egiraldi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 21:55:45 by egiraldi          #+#    #+#             */
/*   Updated: 2022/05/17 02:17:05 by egiraldi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_add_precision(char *current_str, t_arg arg)
{
	char	*precise_str;

	if (!(arg.flags & PRECISION))
		return (ft_strdup(current_str));
	if (arg.specifier == DECIMAL || arg.specifier == UNSIGNED_INTEGER
		|| arg.specifier == INTEGER || arg.specifier == HEXA_LOWER
		|| arg.specifier == HEXA_UPPER)
	{
		if (current_str[0] == '0' && arg.precision == 0)
			return (ft_strdup(""));
		if (current_str[0] == '-')
			return (ft_zpadd_nb(current_str, arg.precision + 1));
		else
			return (ft_zpadd_nb(current_str, arg.precision));
	}
	if (arg.specifier == STRING)
	{
		precise_str = malloc(sizeof(char) * (arg.precision + 1));
		if (!precise_str)
			return (NULL);
		ft_memcpy(precise_str, current_str, arg.precision);
		precise_str[arg.precision] = 0;
		return (precise_str);
	}
	return (ft_strdup(current_str));
}
