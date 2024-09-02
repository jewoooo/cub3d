/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_formats.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 08:38:21 by minhulee          #+#    #+#             */
/*   Updated: 2024/04/22 16:52:40 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	next_format(char *f)
{
	size_t	i;
	size_t	cursor;

	i = 1;
	while (f[i])
	{
		cursor = 0;
		while (cursor < SPEC_COUNT)
		{
			if (f[i] == SPECIFIER[cursor])
				return (i + 1);
			cursor++;
		}
		i++;
	}
	return (-1);
}

int	read_fomat(char *f, size_t *n, size_t c, va_list args)
{
	int	count;

	*n = next_format(f + c);
	if (*n < 0)
		return (-1);
	count = print_format(f[c + *n - 1], args);
	if (count < 0)
		return (-1);
	return (count);
}

int	read_formats(char *f, va_list args)
{
	int		total;
	int		count;
	size_t	next;
	size_t	cursor;

	total = 0;
	cursor = 0;
	while (f[cursor])
	{
		if (f[cursor] == '%')
		{
			count = read_fomat(f, &next, cursor, args);
			if (count < 0)
				return (-1);
			total += count;
			cursor += next;
			continue ;
		}
		if (print_without_format(f[cursor]) < 0)
			return (-1);
		total++;
		cursor++;
	}
	return (total);
}
