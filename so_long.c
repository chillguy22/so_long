/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaktimur <eaktimur@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:42:42 by eaktimur          #+#    #+#             */
/*   Updated: 2024/08/29 11:11:38 by eaktimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(char **map)
{
	int	len;
	int	i;

	i = 0;
	len = map_width(map[i]);
	while (++i, map[i])
		if (map_width(map[i]) != len)
			error(map, "Map should be rectangular");
	is_map_closed(map);
	are_uniques_on_map(map);
	are_uniques_reachable(map);
}

char	*read_map(int fd)
{
	char	*str;
	char	*temp;
	char	*line;

	str = get_next_line(fd);
	if (!str)
		error(NULL, "Map not found.");
	line = get_next_line(fd);
	while (line)
	{
		temp = str;
		str = ft_strjoin(temp, line);
		free(line);
		free(temp);
		line = get_next_line(fd);
	}
	checknewlines(str);
	return (str);
}

char	**parse_map(char *path)
{
	int		fd;
	char	*map_line;
	char	**map;

	fd = open(path, O_RDONLY);
	map_line = read_map(fd);
	map = ft_split(map_line, '\n');
	free(map_line);
	return (map);
}

char	**duplicate_map(char **map)
{
	char	**map_dup;
	int		height;
	int		i;

	height = map_height(map);
	map_dup = malloc(sizeof(char *) * (height + 1));
	if (!map_dup)
		return (NULL);
	map_dup[height] = NULL;
	i = -1;
	while (++i, map[i])
	{
		map_dup[i] = ft_strdup(map[i]);
		if (!map_dup[i])
		{
			free_map(map_dup);
			return (NULL);
		}
	}
	return (map_dup);
}

int	main(int ac, char **av)
{
	t_game	game;
	char	*texture;

	if (ac != 2)
		error(NULL, "Usage: ./so_long <name_of_map_file>");
	game.map = parse_map(av[1]);
	check_map(game.map);
	start_game(game);
	free(game.map);
	return (0);
}
