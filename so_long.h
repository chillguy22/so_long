/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaktimur <eaktimur@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:16:55 by eaktimur          #+#    #+#             */
/*   Updated: 2024/08/29 11:11:18 by eaktimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "library/minilibx/mlx.h"
# include <fcntl.h>
# include <limits.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# define HEADER_SIZE 54

typedef struct s_xpm
{
	void	*background;
	void	*wall;
	void	*collectible1;
	void	*collectible2;
	void	*collectible3;
	void	*collectible4;
	void	*collectible5;
	void	*player_up;
	void	*player_down;
	void	*player_left;
	void	*player_right;
	void	*monster1;
	void	*monster2;
	void	*monster3;
	void	*monster4;
	void	*exit;
	void	*exit_open;
}			t_xpm;

typedef struct s_game
{
	char	**map;
	int		width;
	int		height;
	int		player_xy[2];
	int		exit_xy[2];
	int		**monster_xy;
	void	*mlx;
	void	*window;
	int		x_off;
	int		y_off;
	int		state;
	char	last_key;
	int		frame;
	int		moves;
	t_xpm	xpm;
}			t_game;

// utils.c
void		free_map(char **map);
void		error(char **map, char *msg);
int			map_width(char *map);
int			map_height(char **map);
int			are_collectibles_collected(char **map);

// so_long.c
void		check_map(char **map);
char		*read_map(int fd);
char		**parse_map(char *path);
char		**duplicate_map(char **map);
// int 		main(int argc, char **argv);

// init_animation.c
void		init_textures(t_game *game);
void		init_monster_textures(t_game *game);
void		init_collectible_textures(t_game *game);
void		init_player_textures(t_game *game);

// fill_textures.c
void		fill_texture(t_game game, void *xpm, int x, int y);
void		fill_player_texture(t_game game, char key, int x, int y);
void		fill_monster_texture(t_game game, int x, int y);
void		fill_collectible_texture(t_game game, int x, int y);
void		fill_textures(t_game game, char key);

// start_game.c
void		start_game(t_game game);
void		move_player(t_game *game, char key);
void		get_position(char **map, int *player_xy, int *exit_xy);
void		is_map_closed(char **map);
int			checknewlines(char *str);

// handling.c
void		display_moves(t_game *game);
int			close_game(t_game *game);
void		process_key_event(t_game *game, int x_off, int y_off, char key);
int			handle_key_events(int keycode, t_game *game);
int			update_game(t_game *game);

// utils2
char		*ft_strjoin(char const *s1, char const *s2);
void		*ft_calloc(size_t number, size_t size);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
int			digit_count(int n);
char		*ft_itoa(int n);

// ft_split
int			words_count(const char *str, char splitter);
char		**extract(char const *s, char c, char **split, size_t len);
char		**ft_split(char const *s, char c);

// gnl
char		*read_content(char *leftover, int fd, char *buffer);
char		*make_line(char *leftover);
char		*new_leftover(char *leftover);
char		*get_next_line(int fd);

// gnl utils
int			ft_strlen(char *s);
char		*ft_strchr(char *s, int c);
char		*ft_strdup(const char *str);
char		*ft_strjoin1(char *leftover, char *buffer);

// check_uniqes.c
int			check_uniques(char unique, int *player, int *exit,
				int *collectibles);
void		are_uniques_on_map(char **map);
int			are_uniques_collected(char **map);
void		flood_fill(char **map, int height, int y, int x);
void		are_uniques_reachable(char **map);

#endif