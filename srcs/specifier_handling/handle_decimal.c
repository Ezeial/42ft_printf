/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_decimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraldi <egiraldi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:11:33 by egiraldi          #+#    #+#             */
/*   Updated: 2021/12/10 15:50:22 by egiraldi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*handle_decimal(t_arg arg, va_list *vargs)
{
	char	*raw_str;
	char	*precise_str;
	char	*signed_str;
	char	*padded_str;

	raw_str = ft_itoa(va_arg(*vargs, int));
	if (!raw_str)
		return (NULL);
	precise_str = ft_add_precision(raw_str, arg);
	if (!precise_str)
		return (NULL);
	signed_str = ft_add_sign(precise_str, arg);
	if (!signed_str)
		return (NULL);
	padded_str = ft_add_padding(signed_str, arg);
	if (!padded_str)
		return (NULL);
	free(raw_str);
	free(precise_str);
	free(signed_str);
	return (padded_str);
}
