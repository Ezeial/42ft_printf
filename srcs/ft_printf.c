/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraldi <egiraldi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:57:54 by egiraldi          #+#    #+#             */
/*   Updated: 2022/05/17 02:27:33 by egiraldi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	ft_process_arg(char **format, size_t *printed_len, va_list *vargs)
{
	t_arg	current_arg;
	char	*builded_arg;

	(*format)++;
	current_arg = ft_read_arg(format, vargs);
	if (current_arg.specifier == INVALID)
		return (-1);
	builded_arg = get_into_map(current_arg.specifier)
		.callback(current_arg, vargs, printed_len);
	if (!builded_arg)
		return (-1);
	ft_putstr_fd(builded_arg, 1);
	*printed_len += ft_strlen(builded_arg);
	free(builded_arg);
}

int	ft_printf(const char *format, ...)
{
	va_list		vargs;
	t_arg		current_arg;
	char		*builded_arg;
	size_t		printed_len;

	printed_len = 0;
	va_start(vargs, format);
	while (*format)
	{
		if (*format == '%')
		{
			if (ft_process_arg(&format, &printed_len, &vargs) == -1)
				return (-1);
		}
		else
		{
			ft_putchar_fd(*format, 1);
			printed_len++;
			format++;
		}
	}
	va_end(vargs);
	return (printed_len);
}
