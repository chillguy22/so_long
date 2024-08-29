/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaktimur <eaktimur@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:32:53 by eaktimur          #+#    #+#             */
/*   Updated: 2024/07/23 15:53:53 by eaktimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_content(char *leftover, int fd, char *buffer)
{
	int	bytes_read;

	bytes_read = 999;
	while (bytes_read != 0 && !ft_strchr(leftover, '\n'))
	{
		bytes_read = read(fd, buffer, 42);
		if (bytes_read == -1)
		{
			free(buffer);
			free(leftover);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		leftover = ft_strjoin1(leftover, buffer);
	}
	free(buffer);
	return (leftover);
}

char	*make_line(char *leftover)
{
	int		i;
	char	*line;

	if (leftover[0] == '\0')
		return (NULL);
	i = 0;
	while (leftover[i] && leftover[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (leftover[i] != 0 && leftover[i] != '\n')
	{
		line[i] = leftover[i];
		i++;
	}
	if (leftover[i] == '\n')
	{
		line[i] = leftover[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*new_leftover(char *leftover)
{
	int		i;
	int		j;
	char	*new_leftover;

	i = 0;
	while (leftover[i] != '\n' && leftover[i] != 0)
		i++;
	if (leftover[i] == '\0')
	{
		free(leftover);
		return (NULL);
	}
	new_leftover = (char *)malloc(sizeof(char) * (ft_strlen(leftover) - i + 1));
	if (!new_leftover)
		return (NULL);
	i++;
	j = 0;
	while (leftover[i] != '\0')
		new_leftover[j++] = leftover[i++];
	new_leftover[j] = '\0';
	free(leftover);
	return (new_leftover);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*leftover[4096];
	char		*buffer;

	if (fd < 0 || fd >= 4096 || 42 <= 0)
		return (NULL);
	buffer = (char *)malloc((1 + 42) * sizeof(char));
	if (!buffer)
		return (NULL);
	leftover[fd] = read_content(leftover[fd], fd, buffer);
	if (!leftover[fd])
		return (NULL);
	line = make_line(leftover[fd]);
	leftover[fd] = new_leftover(leftover[fd]);
	return (line);
}
