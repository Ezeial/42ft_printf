/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraldi <egiraldi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:12:10 by egiraldi          #+#    #+#             */
/*   Updated: 2021/12/10 16:03:46 by egiraldi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(int ac, char **av)
{
	char *zgeg = "aa";

	ft_printf(" %u \n", 9223372036854775807LL);
	printf(" %u \n", 9223372036854775807LL);
	return (0);
}
