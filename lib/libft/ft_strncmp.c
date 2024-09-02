/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:32:23 by minhulee          #+#    #+#             */
/*   Updated: 2024/08/26 14:04:33 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((*(s1 + i) && *(s2 + i)) && i < n)
	{
		if ((unsigned char)*(s1 + i) != (unsigned char)*(s2 + i))
			return ((unsigned char)*(s1 + i) - (unsigned char)*(s2 + i));
		i++;
	}
	return (0);
}
