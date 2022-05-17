/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraldi <egiraldi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 01:41:42 by egiraldi          #+#    #+#             */
/*   Updated: 2022/05/17 02:20:11 by egiraldi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*handle_unsigned(t_arg arg, va_list *vargs, size_t *printed_len)
{
	char	*raw_str;
	char	*precise_str;
	char	*signed_str;
	char	*padded_str;

	(void)printed_len;
	raw_str = ft_itoa_un(va_arg(*vargs, unsigned int));
	if (!raw_str)
		return (NULL);
	precise_str = ft_add_precision(raw_str, arg);
	free(raw_str);
	if (!precise_str)
		return (NULL);
	signed_str = ft_add_sign(precise_str, arg);
	free(precise_str);
	if (!signed_str)
		return (NULL);
	padded_str = ft_add_padding(signed_str, arg);
	free(signed_str);
	if (!padded_str)
		return (NULL);
	return (padded_str);
}
