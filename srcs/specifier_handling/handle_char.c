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
	char *raw_str;

	raw_str = malloc(sizeof(char) * 2);
	if (!raw_str)
		return (NULL);
	raw_str[0] = va_arg(*vargs, int);
	raw_str[1] = 0;	
}
