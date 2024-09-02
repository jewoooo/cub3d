/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:36:38 by minhulee          #+#    #+#             */
/*   Updated: 2023/10/14 13:14:02 by minhulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcut(const char *s, size_t start, size_t end)
{
	char			*r;
	unsigned int	i;

	r = (char *)ft_calloc(end - start + 1, sizeof(char));
	if (!r)
		return (0);
	i = 0;
	while (start < end)
	{
		r[i] = s[start];
		i++;
		start++;
	}
	return (r);
}

char	*ft_strdup(const char *s)
{
	char			*r;
	unsigned int	len;
	unsigned int	i;

	len = ft_strlen(s);
	r = malloc(sizeof(char) * (len + 1));
	if (!r)
		return (0);
	i = 0;
	while (*(s + i))
	{
		*(r + i) = *(s + i);
		i++;
	}
	*(r + i) = 0;
	return (r);
}
