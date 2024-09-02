/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:44:47 by minhulee          #+#    #+#             */
/*   Updated: 2024/04/22 16:54:10 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_nbr_base(size_t *count, unsigned long n, int base, char *base_form)
{
	unsigned long	filter;

	filter = 1;
	while (filter <= n / base)
		filter *= base;
	while (filter > 0)
	{
		if (write(1, &base_form[n / filter], 1) < 0)
			return (-1);
		n %= filter;
		filter /= base;
		(*count)++;
	}
	return (1);
}
