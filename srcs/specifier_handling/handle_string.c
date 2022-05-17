/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraldi <egiraldi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 21:36:56 by egiraldi          #+#    #+#             */
/*   Updated: 2022/05/17 01:51:00 by egiraldi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*handle_string(t_arg arg, va_list *vargs, size_t *printed_len)
{
	char	*raw_str;
	char	*precise_str;
	char	*padded_str;

	(void)printed_len;
	raw_str = va_arg(*vargs, char *);
	if (raw_str == NULL)
		return (ft_add_padding("(null)", arg));
	precise_str = ft_add_precision(raw_str, arg);
	if (!precise_str)
		return (NULL);
	padded_str = ft_add_padding(precise_str, arg);
	free(precise_str);
	if (!padded_str)
		return (NULL);
	return (padded_str);
}
