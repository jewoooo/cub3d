/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:53:49 by minhulee          #+#    #+#             */
/*   Updated: 2023/10/11 17:09:03 by minhulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*r;
	size_t			len;

	len = ft_strlen(s1) + ft_strlen(s2);
	r = (char *)malloc(sizeof(char) * (len + 1));
	if (!r)
		return (0);
	ft_strlcpy(r, s1, ft_strlen(s1) + 1);
	ft_strlcat(r, s2, len + 1);
	return (r);
}
