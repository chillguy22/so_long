/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaktimur <eaktimur@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 13:28:46 by eaktimur          #+#    #+#             */
/*   Updated: 2024/07/23 15:53:45 by eaktimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	if (!s)
		return (0);
	if (c == '\0')
		return (s + ft_strlen(s));
	if (c > 256)
		c %= 256;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (s + i);
		i++;
	}
	return (0);
}

char	*ft_strdup(const char *str)
{
	char	*arr;
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
		i++;
	arr = (char *)malloc(sizeof(char) * (i + 1));
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		arr[i] = str[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

char	*ft_strjoin1(char *leftover, char *buffer)
{
	int		i;
	int		j;
	char	*line;

	if (!leftover)
		leftover = ft_strdup("");
	if (!leftover || !buffer)
		return (NULL);
	j = ft_strlen(leftover) + ft_strlen(buffer);
	line = (char *)malloc(sizeof(char) * (j + 1));
	if (line == NULL)
		return (NULL);
	i = -1;
	if (leftover)
		while (leftover[++i])
			line[i] = leftover[i];
	j = 0;
	while (buffer[j])
		line[i++] = buffer[j++];
	line[ft_strlen(leftover) + ft_strlen(buffer)] = 0;
	free(leftover);
	return (line);
}
