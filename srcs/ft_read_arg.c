/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraldi <egiraldi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 13:48:52 by egiraldi          #+#    #+#             */
/*   Updated: 2021/12/10 16:07:44 by egiraldi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_read_flag(char **format, t_arg *arg)
{
	arg->flags = 0;
	if (**format == '-')
	{
		arg->flags |= LJUSTIFY;
		(*format)++;
	}
	if (**format == '+')
	{
		arg->flags |= SIGN;
		(*format)++;
	}
	if (**format == ' ')
	{
		arg->flags |= SPACE;
		(*format)++;
	}
	if (**format == '#')
	{
		arg->flags |= HASH;
		(*format)++;
	}
	if (**format == '0')
	{
		arg->flags |= ZPAD;
		(*format)++;
	}
}

static void	ft_read_width(char **format, t_arg *arg, va_list *vargs)
{
	arg->width = 0;
	while (ft_isdigit(**format))
	{
		arg->width = (arg->width * 10) + (**format - '0');
		(*format)++;
	}
	if (**format == '*')
	{
		arg->width = va_arg(*vargs, int);
		(*format)++;
	}
}

static void	ft_read_precision(char **format, t_arg *arg, va_list *vargs)
{
	arg->precision = 0;
	if (**format == '.')
	{
		(*format)++;
		while (ft_isdigit(**format))
		{
			arg->precision = (arg->precision * 10) + (**format - '0');
			(*format)++;
		}
		if (**format == '*')
		{
			arg->precision = va_arg(*vargs, int);
			(*format)++;
		}
	}
}

static void ft_read_specifier(char **format, t_arg *arg)
{
	if (ft_is_specifier(**format))
		arg->specifier = **format;
	else
		arg->specifier = INVALID;
	*format++;
}

t_arg	ft_read_arg(char **format, va_list *vargs)
{
	t_arg	arg;

	ft_read_flag(format, &arg);
	ft_read_width(format, &arg, vargs);
	ft_read_precision(format, &arg, vargs);
	ft_read_specifier(format, &arg);
	return (arg);
}
