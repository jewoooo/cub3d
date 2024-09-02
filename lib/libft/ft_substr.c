/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:31:08 by minhulee          #+#    #+#             */
/*   Updated: 2023/10/11 17:08:57 by minhulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t max)
{
	char			*r;
	unsigned int	s_len;

	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (s_len - start < max)
		max = s_len - start;
	r = (char *)malloc(sizeof(char) * (max + 1));
	if (!r)
		return (0);
	ft_strlcpy(r, s + start, max + 1);
	return (r);
}
