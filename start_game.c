/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaktimur <eaktimur@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 22:45:22 by eaktimur          #+#    #+#             */
/*   Updated: 2024/08/29 11:14:23 by eaktimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// https://harm-smits.github.io/42docs/libs/minilibx/prototypes.html

void	start_game(t_game game)
{
	game.mlx = mlx_init();
	game.width = map_width(game.map[0]);
	game.height = map_height(game.map);
	game.window = mlx_new_window(game.mlx, game.width * 50, game.height * 50,
			"so_long");
	get_position(game.map, game.player_xy, game.exit_xy);
	init_textures(&game);
	game.frame = 0;
	game.state = 0;
	game.last_key = 'w';
	game.moves = 0;
	fill_textures(game, 'w');
	mlx_hook(game.window, 17, 0, close_game, &game);
	mlx_key_hook(game.window, handle_key_events, &game);
	mlx_loop_hook(game.mlx, update_game, &game);
	mlx_loop(game.mlx);
}

void	move_player(t_game *game, char key)
{
	static int	moves;
	int			x;
	int			y;

	x = game->player_xy[0] + game->x_off;
	y = game->player_xy[1] + game->y_off;
	if (game->map[x][y] == '1')
		return ;
	if (game->map[x][y] == 'M')
		close_game(game);
	game->moves++;
	if (game->map)
		game->map[x][y] = 'P';
	if (x == game->exit_xy[0] && y == game->exit_xy[1])
		if (are_uniques_collected(game->map))
			close_game(game);
	if (game->player_xy[0] == game->exit_xy[0]
		&& game->player_xy[1] == game->exit_xy[1])
		game->map[game->player_xy[0]][game->player_xy[1]] = 'E';
	else
		game->map[game->player_xy[0]][game->player_xy[1]] = '0';
	game->player_xy[0] = x;
	game->player_xy[1] = y;
	fill_textures(*game, key);
	display_moves(game);
}

void	get_position(char **map, int *player_xy, int *exit_xy)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P' && player_xy)
			{
				player_xy[0] = i;
				player_xy[1] = j;
			}
			if (map[i][j] == 'E' && exit_xy)
			{
				exit_xy[0] = i;
				exit_xy[1] = j;
			}
			j++;
		}
		i++;
	}
}

void	is_map_closed(char **map)
{
	int	i;
	int	j;
	int	width;
	int	height;

	i = -1;
	width = map_width(map[0]) - 1;
	height = map_height(map) - 1;
	while (++i, map[i])
	{
		j = -1;
		while (++j, map[i][j])
			if (i == 0 || i == height || j == 0 || j == width)
				if (map[i][j] != '1')
					error(map, "Map should be surrounded by walls");
	}
}

int	checknewlines(char *str)
{
	int	i;

	if (str[0] == '\n')
	{
		free(str);
		error(NULL, "Map should be rectangular");
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
		{
			free(str);
			error(NULL, "Map should be rectangular");
		}
		if (str[i] == '\n' && str[i + 1] == '\0')
		{
			free(str);
			error(NULL, "Map should be rectangular");
		}
		i++;
	}
	return (0);
}
