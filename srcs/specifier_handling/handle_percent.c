/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraldi <egiraldi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 00:51:42 by egiraldi          #+#    #+#             */
/*   Updated: 2022/05/17 01:50:42 by egiraldi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*handle_percent(t_arg arg, va_list *vargs, size_t *printed_len)
{
	char	percent_str[2];

	(void)printed_len;
	(void)vargs;
	percent_str[0] = '%';
	percent_str[1] = 0;
	return (ft_add_padding(percent_str, arg));
}
