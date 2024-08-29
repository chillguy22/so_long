/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaktimur <eaktimur@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:17:07 by eaktimur          #+#    #+#             */
/*   Updated: 2024/08/03 15:17:09 by eaktimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	error(char **map, char *msg)
{
	if (map)
		free_map(map);
	write(1, "Error\n", 6);
	write(1, msg, ft_strlen(msg));
	write(1, "\n", 1);
	exit(0);
}

int	map_width(char *map)
{
	int	i;

	i = 0;
	while (map[i] != '\n' && map[i] != '\0')
		i++;
	return (i);
}

int	map_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	are_collectibles_collected(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (++i, map[i])
	{
		j = -1;
		while (++j, map[i][j])
			if (map[i][j] == 'C')
				return (0);
	}
	return (1);
}
