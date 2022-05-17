/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_hash.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraldi <egiraldi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:38:40 by egiraldi          #+#    #+#             */
/*   Updated: 2022/05/17 01:20:39 by egiraldi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_add_hash(char *current_str, t_arg arg)
{
	char	*hashed_str;

	if ((arg.flags & HASH && (arg.specifier == HEXA_LOWER \
		|| arg.specifier == HEXA_UPPER)) || arg.specifier == POINTER)
	{
		if (current_str[0] == '0' && arg.specifier != POINTER)
			return (ft_strdup("0"));
		hashed_str = malloc(sizeof(char) * (ft_strlen(current_str) + 2 + 1));
		if (!hashed_str)
			return (NULL);
		if (arg.specifier == HEXA_LOWER || arg.specifier == POINTER)
			ft_memcpy(hashed_str, "0x", 2);
		if (arg.specifier == HEXA_UPPER)
			ft_memcpy(hashed_str, "0X", 2);
		ft_strlcpy(hashed_str + 2, current_str, ft_strlen(current_str) + 2);
		return (hashed_str);
	}
	return (ft_strdup(current_str));
}
