#include "ft_printf.h"
#include <stdio.h>

int ft_printf(char *format, ...)
{
	va_list vargs;
	t_arg_info arg_info;
	size_t	len;
	
	va_start(vargs, format);
	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (!parse_arg(&format, &arg_info, &vargs))
				return (-1);
			char *str = get_into_map(arg_info.specifier).callback(arg_info, &vargs);
			ft_putstr_fd(str, 1);
			len += ft_strlen(str);
			free(str);
		}
		else
		{
			ft_putchar_fd(*format++, 1);
			len++;
		}
	}
	va_end(vargs);
	return (len);
}