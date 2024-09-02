/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:20:35 by minhulee          #+#    #+#             */
/*   Updated: 2023/10/11 12:19:41 by minhulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int				flag;
	int				sum;
	unsigned int	i;

	flag = 1;
	sum = 0;
	i = 0;
	while (*(str + i) == 32 || (*(str + i) >= 9 && *(str + i) <= 13))
		i++;
	if (*(str + i) == '-' || *(str + i) == '+')
	{
		if (*(str + i) == '-')
			flag *= -1;
		i++;
	}
	while (*(str + i) >= '0' && *(str + i) <= '9')
	{
		sum *= 10;
		sum += *(str + i) - '0';
		i++;
	}
	return (flag * sum);
}
