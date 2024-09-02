/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:28:14 by minhulee          #+#    #+#             */
/*   Updated: 2023/10/10 16:15:03 by minhulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	unsigned int	len;
	char			*r;

	i = 0;
	len = ft_strlen(s);
	r = 0;
	while (i <= len)
	{
		if (*(s + i) == ((char)c))
			r = (char *)s + i;
		i++;
	}
	return (r);
}
