#include "ft_printf.h"
#include <stdio.h>

// char *handle_pointer(t_arg arg, va_list *vargs)
// {
	// unsigned long addr;
	// char *result;
	// char *ptr_copy;
	// char *converted_copy;
	
	// addr = (unsigned long)va_arg(*vargs, void *);	
	// result = add_padding(ft_strjoin("0x", converted_copy = ft_convert_base(ptr_copy = ft_itoa_un(addr), "0123456789", "0123456789abcdef")), arg_info);
	// free(ptr_copy);
	// free(converted_copy);
	// return (result);
// }