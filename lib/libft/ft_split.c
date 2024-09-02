/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:14:29 by minhulee          #+#    #+#             */
/*   Updated: 2024/08/26 13:47:35 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*free_split(char **r)
{
	size_t	i;

	i = 0;
	while (r[i])
	{
		free(r[i]);
		i++;
	}
	free(r);
	return (0);
}

size_t	count_words(char const *s, char c)
{
	unsigned int	i;
	size_t			len;

	i = 0;
	len = 0;
	if (!s[i])
		return (0);
	if (s[i] != c)
		len++;
	while (s[i + 1])
	{
		if (s[i] == c && s[i + 1] != c)
			len++;
		i++;
	}
	return (len);
}

unsigned int	copy_words(char const *s, char c, char **r)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	*r = (char *)ft_calloc(i + 1, sizeof(char));
	if (!(*r))
		return (0);
	i = 0;
	while (s[i] != c && s[i])
	{
		(*r)[i] = s[i];
		i++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char			**r;
	size_t			i;
	size_t			i2;
	unsigned int	flag;

	r = (char **)ft_calloc(count_words(s, c) + 1, sizeof(char *));
	if (!r)
		return (0);
	i = 0;
	i2 = 0;
	while (s[i] && i2 < count_words(s, c))
	{
		if (s[i] != c)
		{
			flag = copy_words((s + i), c, r + i2);
			if (!flag)
				return (free_split(r));
			i += flag;
			i2++;
		}
		else
			i++;
	}
	return (r);
}
