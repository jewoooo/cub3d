/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:51:03 by minhulee          #+#    #+#             */
/*   Updated: 2023/10/20 17:51:31 by minhulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	unsigned int	end;

	start = 0;
	while (s1[start])
	{
		if (!ft_strchr(set, s1[start]))
			break ;
		start++;
	}
	end = ft_strlen(s1);
	while (end > 0)
	{
		if (!ft_strchr(set, s1[end - 1]))
			break ;
		end--;
	}
	if (end < start)
		return (ft_strdup(""));
	return (ft_strcut(s1, start, end));
}
