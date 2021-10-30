#include "ft_printf.h"
#include <stdio.h>

static size_t parse_next_number(char **str)
{
	size_t result;
	
	result = 0;
	while (ft_isdigit(**str))
	{
		result = **str - '0' + result * 10;
		(*str)++;
	}
	return (result);
}

static int check_arg_info(t_arg_info arg_info)
{
	if (!get_into_map(arg_info.specifier).specifier)
		return (0);
	return (1);
}

int parse_arg(char **format, t_arg_info *arg_info, va_list *vargs)
{
	arg_info->flag = '\0';
	if (**format == '-' || **format == '0')
	{
		arg_info->flag = **format;
		(*format)++;
	}
	if (**format == '*' && (*format)++)
		arg_info->width = va_arg(*vargs, int);
	arg_info->width = parse_next_number(format);
	if (**format == '.')
	{
		(*format)++;
		arg_info->precision = parse_next_number(format);
	}
	arg_info->specifier = **format;
	(*format)++;
	if (!check_arg_info(*arg_info))
		return 0;
	return 1;
}
