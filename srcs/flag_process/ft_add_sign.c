/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_sign.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraldi <egiraldi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 21:55:28 by egiraldi          #+#    #+#             */
/*   Updated: 2022/05/17 02:17:23 by egiraldi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_add_sign(char *current_str, t_arg arg)
{
	char	*signed_str;

	if (arg.flags & SIGN || arg.flags & SPACE)
	{
		if (*current_str != '-')
		{
			signed_str = (char *)malloc(sizeof(char)
					* (ft_strlen(current_str) + 2));
			if (!signed_str)
				return (NULL);
			if (arg.flags & SIGN)
				signed_str[0] = '+';
			if (arg.flags & SPACE)
				signed_str[0] = ' ';
			signed_str[1] = 0;
			ft_strlcat(signed_str, current_str, ft_strlen(current_str) + 2);
		}
		else
			signed_str = ft_strdup(current_str);
	}
	else
		signed_str = ft_strdup(current_str);
	return (signed_str);
}
