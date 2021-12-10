/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraldi <egiraldi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:57:54 by egiraldi          #+#    #+#             */
/*   Updated: 2021/12/10 15:12:43 by egiraldi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(char *format, ...)
{
	va_list		vargs;
	t_arg		current_arg;
	char		*builded_arg;

	va_start(vargs, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			current_arg = ft_read_arg(&format, &vargs);
			builded_arg = get_into_map(current_arg.specifier).callback(current_arg, vargs);
			ft_putstr_fd(*format, 1);
			free(builded_arg);
		}
		else
		{
			ft_putchar_fd(*format, 1);
			format++;
		}
	}
	va_end(vargs);
	return (0);
}
