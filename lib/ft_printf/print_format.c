/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:49:36 by minhulee          #+#    #+#             */
/*   Updated: 2023/12/05 14:26:02 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(char s, va_list args)
{
	int	count;

	count = -1;
	if (s == 'c')
		count = print_format_c(va_arg(args, int));
	else if (s == 's')
		count = print_format_s(va_arg(args, char *));
	else if (s == 'p')
		count = print_format_p(va_arg(args, void *));
	else if (s == 'd' || s == 'i')
		count = print_format_di(va_arg(args, int));
	else if (s == 'u')
		count = print_format_u(va_arg(args, unsigned int));
	else if (s == 'x' || s == 'X')
		count = print_format_xux(s, va_arg(args, unsigned int));
	else if (s == '%')
		count = print_format_per();
	return (count);
}
