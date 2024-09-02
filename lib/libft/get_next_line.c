/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:53:14 by minhulee          #+#    #+#             */
/*   Updated: 2023/11/23 16:13:39 by minhulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	double_backup(char **backup, int len)
{
	char	*tmp;

	tmp = *backup;
	if (512 < BUFFER_SIZE)
		len += BUFFER_SIZE;
	else
		len += 512;
	*backup = (char *)malloc((len + 1) * sizeof(char));
	if (!*backup)
	{
		*backup = tmp;
		return (-1);
	}
	(*backup)[0] = '\0';
	gnl_strcat(*backup, tmp);
	free(tmp);
	return (len);
}

int	get_next_buff(int fd, char **backup)
{
	int	read_size;
	int	total;
	int	len;

	total = gnl_strlen(*backup);
	len = gnl_strlen(*backup);
	while (gnl_strchr(*backup, '\n') < 0)
	{
		if (total + BUFFER_SIZE > len)
		{
			len = double_backup(backup, len);
			if (len < 0)
				return (-1);
		}
		read_size = read(fd, *backup + total, BUFFER_SIZE);
		total += read_size;
		if (read_size < 0)
			return (-1);
		(*backup)[total] = '\0';
		if (read_size == 0)
			return (0);
	}
	(*backup)[total] = '\0';
	return (1);
}

char	*get_reach_eof(char **backup)
{
	char	*result;

	result = gnl_strcut(*backup, 0, gnl_strlen(*backup));
	if (*backup)
	{
		free(*backup);
		*backup = 0;
	}
	return (result);
}

char	*get_reach_newline(char **backup, int std)
{
	char	*result;
	char	*tmp;

	result = gnl_strcut(*backup, 0, std + 1);
	tmp = gnl_strcut(*backup, std + 1, gnl_strlen(*backup));
	if (!result || !tmp)
	{
		if (result)
			free(result);
		if (tmp)
			free(tmp);
		result = NULL;
		tmp = NULL;
	}
	free(*backup);
	*backup = tmp;
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	int			result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	result = get_next_buff(fd, &backup);
	if (result == -1)
	{
		if (backup)
			free(backup);
		backup = NULL;
		return (NULL);
	}
	if (result == 0)
		return (get_reach_eof(&backup));
	return (get_reach_newline(&backup, gnl_strchr(backup, '\n')));
}
