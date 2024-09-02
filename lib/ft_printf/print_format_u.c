/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:38:55 by minhulee          #+#    #+#             */
/*   Updated: 2024/04/22 16:53:36 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format_u(unsigned int n)
{
	size_t	count;

	count = 0;
	if (print_nbr_base(&count, n, DECIMAL, DECIMAL_BASE) < 0)
		return (-1);
	return (count);
}
