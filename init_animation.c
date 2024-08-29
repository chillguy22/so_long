/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaktimur <eaktimur@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 22:42:23 by eaktimur          #+#    #+#             */
/*   Updated: 2024/08/05 16:54:05 by eaktimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_monster_textures(t_game *game)
{
	game->xpm.monster1 = mlx_xpm_file_to_image(game->mlx,
			"textures/monster_red.xpm", &(game->width), &(game->height));
	game->xpm.monster2 = mlx_xpm_file_to_image(game->mlx,
			"textures/monster_green.xpm", &(game->width), &(game->height));
	game->xpm.monster3 = mlx_xpm_file_to_image(game->mlx,
			"textures/monster_blue.xpm", &(game->width), &(game->height));
	game->xpm.monster4 = mlx_xpm_file_to_image(game->mlx,
			"textures/monster_orange.xpm", &(game->width), &(game->height));
}

void	init_collectible_textures(t_game *game)
{
	game->xpm.collectible1 = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible1.xpm", &(game->width), &(game->height));
	game->xpm.collectible2 = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible2.xpm", &(game->width), &(game->height));
	game->xpm.collectible3 = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible5.xpm", &(game->width), &(game->height));
	game->xpm.collectible4 = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible4.xpm", &(game->width), &(game->height));
}

void	init_player_textures(t_game *game)
{
	game->xpm.player_up = mlx_xpm_file_to_image(game->mlx,
			"textures/player_up.xpm", &(game->width), &(game->height));
	game->xpm.player_down = mlx_xpm_file_to_image(game->mlx,
			"textures/player_down.xpm", &(game->width), &(game->height));
	game->xpm.player_left = mlx_xpm_file_to_image(game->mlx,
			"textures/player_left.xpm", &(game->width), &(game->height));
	game->xpm.player_right = mlx_xpm_file_to_image(game->mlx,
			"textures/player_right.xpm", &(game->width), &(game->height));
}

void	init_textures(t_game *game)
{
	init_monster_textures(game);
	init_collectible_textures(game);
	init_player_textures(game);
	game->xpm.background = mlx_xpm_file_to_image(game->mlx,
			"textures/terrain.xpm", &(game->width), &(game->height));
	game->xpm.wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
			&(game->width), &(game->height));
	game->xpm.exit = mlx_xpm_file_to_image(game->mlx,
			"textures/exit_closed.xpm", &(game->width), &(game->height));
	game->xpm.exit_open = mlx_xpm_file_to_image(game->mlx,
			"textures/exit_open.xpm", &(game->width), &(game->height));
}
