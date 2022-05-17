/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraldi <egiraldi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 01:41:44 by egiraldi          #+#    #+#             */
/*   Updated: 2022/05/17 02:19:48 by egiraldi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char	*handle_pointer(t_arg arg, va_list *vargs, size_t *printed_len)
{
	char	*raw_str;
	char	*precise_str;
	char	*hashed_str;
	char	*padded_str;

	(void)printed_len;
	raw_str = ft_itoa_un_base(va_arg(*vargs, unsigned long),
			"0123456789abcdef");
	if (!raw_str)
		return (NULL);
	precise_str = ft_add_precision(raw_str, arg);
	free(raw_str);
	if (!precise_str)
		return (NULL);
	hashed_str = ft_add_hash(precise_str, arg);
	free(precise_str);
	if (!hashed_str)
		return (NULL);
	padded_str = ft_add_padding(hashed_str, arg);
	free(hashed_str);
	if (!padded_str)
		return (NULL);
	return (padded_str);
}
