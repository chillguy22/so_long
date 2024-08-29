/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_uniques.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaktimur <eaktimur@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 22:41:33 by eaktimur          #+#    #+#             */
/*   Updated: 2024/08/12 16:07:11 by eaktimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_uniques(char unique, int *player, int *exit, int *collectibles)
{
	if (unique == 'P')
		(*player)++;
	else if (unique == 'E')
		(*exit)++;
	else if (unique == 'C')
		(*collectibles)++;
	else if (unique != '0' && unique != '1' && unique != 'M')
		return (0);
	return (1);
}

void	are_uniques_on_map(char **map)
{
	int	player;
	int	exit;
	int	collectibles;
	int	i;
	int	j;

	player = 0;
	exit = 0;
	collectibles = 0;
	i = -1;
	while (++i, map[i])
	{
		j = -1;
		while (++j, map[i][j])
			if (!check_uniques(map[i][j], &player, &exit, &collectibles))
				error(map, "Map should have P, E and C.");
	}
	if (player != 1)
		error(map, "There must be exactly 1 player (P) on the map.");
	if (exit != 1)
		error(map, "There must be exactly 1 exit (E) on the map.");
	if (collectibles < 1)
		error(map, "There must be at least 1 collectible (C) on the map.");
}

int	are_uniques_collected(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (++i, map[i])
	{
		j = -1;
		while (++j, map[i][j])
			if (map[i][j] == 'C' || map[i][j] == 'E')
				return (0);
	}
	return (1);
}

void	flood_fill(char **map, int height, int y, int x)
{
	int	width;

	width = map_width(map[0]);
	if (y < 0 || y >= height || x < 0 || x >= width || map[y][x] == 'D'
		|| map[y][x] == '1' || map[y][x] == 'M')
		return ;
	map[y][x] = 'D';
	flood_fill(map, height, y - 1, x);
	flood_fill(map, height, y + 1, x);
	flood_fill(map, height, y, x - 1);
	flood_fill(map, height, y, x + 1);
}

void	are_uniques_reachable(char **map)
{
	char	**map_dup;
	int		player_xy[2];
	int		height;

	height = map_height(map);
	map_dup = duplicate_map(map);
	if (!map_dup)
		error(map, "error copying map.");
	get_position(map_dup, player_xy, NULL);
	flood_fill(map_dup, height, player_xy[0], player_xy[1]);
	if (!are_uniques_collected(map_dup))
	{
		free_map(map_dup);
		error(map, "error finishing map.");
	}
	free_map(map_dup);
}
