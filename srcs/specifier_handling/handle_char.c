/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraldi <egiraldi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:10:44 by egiraldi          #+#    #+#             */
/*   Updated: 2021/12/10 15:50:17 by egiraldi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*handle_char(t_arg arg, va_list *vargs)
{
	char raw_str[2];
	char *padded_str;

	raw_str[0] = va_arg(*vargs, int);
	raw_str[1] = 0;	
	padded_str = ft_add_padding(raw_str, arg);
	if (!padded_str)
		return (NULL);
	return (padded_str);
}
