/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaktimur <eaktimur@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:26:32 by eaktimur          #+#    #+#             */
/*   Updated: 2024/08/03 15:17:15 by eaktimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*st;
	int		i;

	if (!s1 || !s2)
		return (0);
	st = (char *)malloc((ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1));
	if (!st)
		return (0);
	i = 0;
	while (*s1)
	{
		st[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		st[i] = *s2;
		s2++;
		i++;
	}
	st[i] = 0;
	return (st);
}

void	*ft_calloc(size_t number, size_t size)
{
	void	*ptr;
	size_t	i;

	if (number != 0 && (number * size) / number != size)
		return (NULL);
	ptr = (void *)malloc(size * number);
	if (!ptr)
		return (NULL);
	if (size == 0)
		return (ptr);
	i = 0;
	while (i < (number * size))
	{
		((unsigned char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	j;
	size_t	len;

	j = 0;
	while (src[j])
		j++;
	len = j;
	if (size == 0)
		return (len);
	j = 0;
	while (j < (size - 1) && src[j] != '\0')
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';
	return (len);
}

int	digit_count(int n)
{
	int		count;
	long	result;

	result = n;
	count = 1;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		count++;
		result *= (-1);
	}
	while (result >= 10)
	{
		result /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int				len;
	char			*tab;
	unsigned int	temp;

	temp = (unsigned int)n;
	len = digit_count(n);
	if (n < 0)
		temp *= -1;
	tab = malloc(sizeof(char) * len + 1);
	if (!(tab))
		return (NULL);
	tab[len--] = '\0';
	while (len >= 0)
	{
		tab[len] = temp % 10 + '0';
		temp /= 10;
		len--;
	}
	if (n < 0)
		tab[0] = '-';
	return (tab);
}
