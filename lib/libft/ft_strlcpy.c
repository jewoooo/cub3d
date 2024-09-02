/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 18:08:03 by minhulee          #+#    #+#             */
/*   Updated: 2023/10/11 13:28:33 by minhulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;

	if (dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	while ((*(src + i)) && i + 1 < dstsize)
	{
		*(dst + i) = *(src + i);
		i++;
	}
	*(dst + i) = 0;
	return (ft_strlen(src));
}
