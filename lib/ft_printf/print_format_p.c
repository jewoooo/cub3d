/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:39:25 by minhulee          #+#    #+#             */
/*   Updated: 2024/04/22 16:53:20 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_sharp(size_t *count)
{
	if (write(1, ZEROX, 2) < 0)
		return (-1);
	(*count) += 2;
	return (1);
}

int	print_format_p(void *p)
{
	unsigned long	n;
	size_t			count;

	count = 0;
	n = (unsigned long)p;
	if (print_sharp(&count) < 0)
		return (-1);
	if (print_nbr_base(&count, n, HEXA, HEXA_BASE) < 0)
		return (-1);
	return (count);
}
