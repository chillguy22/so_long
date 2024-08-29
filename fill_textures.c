/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaktimur <eaktimur@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 22:22:23 by eaktimur          #+#    #+#             */
/*   Updated: 2024/08/05 17:07:05 by eaktimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_texture(t_game game, void *xpm, int x, int y)
{
	mlx_put_image_to_window(game.mlx, game.window, xpm, x, y);
}

void	fill_player_texture(t_game game, char key, int x, int y)
{
	if (key == 'w')
		fill_texture(game, game.xpm.player_up, x, y);
	if (key == 's')
		fill_texture(game, game.xpm.player_down, x, y);
	if (key == 'a')
		fill_texture(game, game.xpm.player_left, x, y);
	if (key == 'd')
		fill_texture(game, game.xpm.player_right, x, y);
}

void	fill_collectible_texture(t_game game, int x, int y)
{
	if (game.state == 0)
		fill_texture(game, game.xpm.collectible1, x, y);
	else if (game.state == 1)
		fill_texture(game, game.xpm.collectible2, x, y);
	else if (game.state == 2)
		fill_texture(game, game.xpm.collectible3, x, y);
	else if (game.state == 3)
		fill_texture(game, game.xpm.collectible4, x, y);
	else
		fill_texture(game, game.xpm.collectible5, x, y);
}

void	fill_monster_texture(t_game game, int x, int y)
{
	if (game.state == 0)
		fill_texture(game, game.xpm.monster1, x, y);
	else if (game.state == 1)
		fill_texture(game, game.xpm.monster2, x, y);
	else if (game.state == 2)
		fill_texture(game, game.xpm.monster3, x, y);
	else
		fill_texture(game, game.xpm.monster4, x, y);
}

void	fill_textures(t_game game, char key)
{
	int	i;
	int	j;

	i = -1;
	while (++i, game.map[i])
	{
		j = -1;
		while (++j, game.map[i][j])
		{
			if (game.map[i][j] == '0')
				fill_texture(game, game.xpm.background, j * 50, i * 50);
			if (game.map[i][j] == '1')
				fill_texture(game, game.xpm.wall, j * 50, i * 50);
			if (game.map[i][j] == 'C')
				fill_collectible_texture(game, j * 50, i * 50);
			if (game.map[i][j] == 'P')
				fill_player_texture(game, key, j * 50, i * 50);
			if (game.map[i][j] == 'M')
				fill_monster_texture(game, j * 50, i * 50);
			if (game.map[i][j] == 'E' && are_collectibles_collected(game.map))
				fill_texture(game, game.xpm.exit_open, j * 50, i * 50);
			else if (game.map[i][j] == 'E')
				fill_texture(game, game.xpm.exit, j * 50, i * 50);
		}
	}
}
