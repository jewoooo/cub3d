/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:01:24 by minhulee          #+#    #+#             */
/*   Updated: 2023/10/11 13:33:45 by minhulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, void *src, size_t len)
{
	unsigned int	i;

	if (!dst && !src)
		return (dst);
	if (dst < src)
	{
		i = 0;
		while (i < len)
		{
			*((unsigned char *)dst + i) = *((unsigned char *)src + i);
			i++;
		}
	}
	else
	{
		i = len;
		while (i > 0)
		{
			*((unsigned char *)dst + i - 1) = *((unsigned char *)src + i - 1);
			i--;
		}
	}
	return (dst);
}
