/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaktimur <eaktimur@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:32:23 by eaktimur          #+#    #+#             */
/*   Updated: 2024/08/22 19:25:37 by eaktimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_moves(t_game *game)
{
	char	*str;

	str = ft_itoa(game->moves);
	mlx_string_put(game->mlx, game->window, 10, 20, 0xFFFFFFFF, "# of Moves: ");
	mlx_string_put(game->mlx, game->window, 85, 20, 0xFFFFFFFF, str);
	free(str);
}

int	close_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->xpm.monster1);
	mlx_destroy_image(game->mlx, game->xpm.monster2);
	mlx_destroy_image(game->mlx, game->xpm.monster3);
	mlx_destroy_image(game->mlx, game->xpm.monster4);
	mlx_destroy_image(game->mlx, game->xpm.background);
	mlx_destroy_image(game->mlx, game->xpm.wall);
	mlx_destroy_image(game->mlx, game->xpm.collectible1);
	mlx_destroy_image(game->mlx, game->xpm.collectible2);
	mlx_destroy_image(game->mlx, game->xpm.collectible3);
	mlx_destroy_image(game->mlx, game->xpm.collectible4);
	mlx_destroy_image(game->mlx, game->xpm.player_up);
	mlx_destroy_image(game->mlx, game->xpm.player_down);
	mlx_destroy_image(game->mlx, game->xpm.player_left);
	mlx_destroy_image(game->mlx, game->xpm.player_right);
	mlx_destroy_image(game->mlx, game->xpm.exit);
	mlx_destroy_image(game->mlx, game->xpm.exit_open);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_map(game->map);
	exit(0);
}

void	process_key_event(t_game *game, int x_off, int y_off, char key)
{
	game->x_off = x_off;
	game->y_off = y_off;
	game->last_key = key;
	move_player(game, key);
}

int	handle_key_events(int keycode, t_game *game)
{
	if (keycode == 119 || keycode == 65362)
		process_key_event(game, -1, 0, 'w');
	else if (keycode == 115 || keycode == 65364)
		process_key_event(game, 1, 0, 's');
	else if (keycode == 97 || keycode == 65361)
		process_key_event(game, 0, -1, 'a');
	else if (keycode == 100 || keycode == 65363)
		process_key_event(game, 0, 1, 'd');
	else if (keycode == 65307)
		close_game(game);
	return (0);
}

int	update_game(t_game *game)
{
	game->frame++;
	if (game->frame >= 5000)
	{
		game->state = (game->state + 1) % 4;
		game->frame = 0;
		fill_textures(*game, game->last_key);
		display_moves(game);
	}
	return (0);
}
