/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 12:52:02 by minhulee          #+#    #+#             */
/*   Updated: 2023/10/14 15:37:04 by minhulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	measure_len(int n)
{
	size_t			len;
	unsigned int	filter;

	if (n == 0)
		return (1);
	filter = 1000000000;
	len = 10;
	while (n / filter < 1)
	{
		len--;
		filter /= 10;
	}
	return (len);
}

char	*convert_int(char *result, int n, size_t len, unsigned int flag)
{
	size_t			i;

	i = len - 1;
	if (flag)
		result[0] = '-';
	while (i >= flag)
	{
		result[i] = (n % 10) + 48;
		n /= 10;
		if (i == 0)
			break ;
		i--;
	}
	return (result);
}

char	*ft_itoa(int n)
{
	char			*result;
	size_t			len;
	unsigned int	flag;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = 0;
	flag = 0;
	if (n < 0)
	{
		len++;
		flag = 1;
		n = -n;
	}
	len += measure_len(n);
	result = (char *)ft_calloc(len + 1, sizeof(char));
	if (!result)
		return (0);
	return (convert_int(result, n, len, flag));
}
