/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_padding.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraldi <egiraldi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 22:29:18 by egiraldi          #+#    #+#             */
/*   Updated: 2022/05/17 02:16:29 by egiraldi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_ljustify(char *padded_str, char *current_str,
	size_t len, t_arg arg)
{
	ft_memcpy(padded_str, current_str, len);
	ft_memset(padded_str + len, ' ', arg.width - len);
	padded_str[arg.width] = 0;
}

char	*ft_add_padding(char *current_str, t_arg arg)
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
		free(padded_str);
		padded_str = ft_zpadd_nb(current_str, arg.width);
		if (!padded_str)
			return (NULL);
	}
	else if (arg.flags & LJUSTIFY)
		ft_ljustify(padded_str, current_str, len, arg);
	else
	{
		ft_memset(padded_str, ' ', arg.width - len);
		ft_memcpy(padded_str + (arg.width - len), current_str, len);
		padded_str[arg.width] = 0;
	}
	return (padded_str);
}
