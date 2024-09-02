/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:24:51 by minhulee          #+#    #+#             */
/*   Updated: 2023/12/05 14:45:46 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *formats, ...)
{
	int		count;
	va_list	args;

	va_start(args, formats);
	count = read_formats((char *)formats, args);
	va_end(args);
	return (count);
}
