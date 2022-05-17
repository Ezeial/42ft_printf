/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraldi <egiraldi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 02:30:21 by egiraldi          #+#    #+#             */
/*   Updated: 2022/05/17 02:30:27 by egiraldi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*handle_char(t_arg arg, va_list *vargs, size_t *printed_len)
{
	char	raw_str[2];
	char	*padded_str;
	int		c;

	c = va_arg(*vargs, int);
	if (c == 0)
	{
		write(1, &c, 1);
		(*printed_len)++;
		if (arg.width != 0)
			arg.width--;
		return (ft_add_padding("", arg));
	}
	raw_str[0] = c;
	raw_str[1] = 0;
	padded_str = ft_add_padding(raw_str, arg);
	if (!padded_str)
		return (NULL);
	return (padded_str);
}
