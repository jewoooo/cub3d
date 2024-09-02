/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:22:38 by minhulee          #+#    #+#             */
/*   Updated: 2023/10/10 14:31:28 by minhulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = ft_strlen(s);
	while (i <= len)
	{
		if (*(s + i) == ((char)c))
			return ((char *)s + i);
		i++;
	}
	return (0);
}
