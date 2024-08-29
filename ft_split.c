/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaktimur <eaktimur@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:28:48 by eaktimur          #+#    #+#             */
/*   Updated: 2024/08/01 16:29:06 by eaktimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	words_count(const char *str, char splitter)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (str == 0)
		return (count);
	while (str[i] != '\0')
	{
		if ((str[i + 1] == splitter || str[i + 1] == '\0')
			&& (!(str[i] == splitter || str[i] == '\0')))
			count++;
		i++;
	}
	return (count);
}

char	**extract(char const *s, char c, char	**split, size_t	len)
{
	size_t	i;
	size_t	j;
	size_t	size;

	i = 0;
	j = 0;
	size = 0;
	while (i < len + 1 && len > 0)
	{
		if ((s[i] == c || s[i] == '\0'))
		{
			if (size > 0)
			{
				split[j] = (char *)ft_calloc(sizeof(char), size + 1);
				if (split[j] != (NULL))
					ft_strlcpy(split[j], &s[i - size], size + 1);
				size = 0;
				j++;
			}
		}
		else
			size++;
		i++;
	}
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	words;
	size_t	len;

	len = ft_strlen((char *)s);
	words = words_count(s, c);
	split = (char **)ft_calloc(sizeof(char *), words + 1);
	if (!split)
		return (NULL);
	split = extract(s, c, split, len);
	split[words] = 0;
	return (split);
}
