/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:38:30 by minhulee          #+#    #+#             */
/*   Updated: 2024/04/22 16:53:09 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format_s(char *s)
{
	size_t	count;

	if (!s)
		s = "(null)";
	count = 0;
	while (s[count])
	{
		if (write(1, &s[count], 1) < 0)
			return (-1);
		count++;
	}
	return (count);
}
