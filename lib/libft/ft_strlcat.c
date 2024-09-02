/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 18:25:10 by minhulee          #+#    #+#             */
/*   Updated: 2023/10/11 14:37:21 by minhulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	dst_len;
	unsigned int	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dst_len > dstsize)
		return (src_len + dstsize);
	i = 0;
	while (dst_len + i + 1 < dstsize && *(src + i))
	{
		*(dst + dst_len + i) = *(src + i);
		i++;
	}
	*(dst + dst_len + i) = '\0';
	return (dst_len + src_len);
}
