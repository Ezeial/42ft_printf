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

int	main(int ac, char **av)
{
	char *zgeg = "aa";

	printf(" %c %c %c \n", '0', 0, '1');
	ft_printf(" %c %c %c \n", '0', 0, '1');
	return (0);
}
