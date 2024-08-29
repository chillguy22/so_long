# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eaktimur <eaktimur@student.42warsaw.pl>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/03 15:16:09 by eaktimur          #+#    #+#              #
#    Updated: 2024/08/03 16:04:11 by eaktimur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += -s
NAME = so_long
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS =	so_long.c ft_split.c get_next_line.c get_next_line_utils.c \
		utils2.c utils.c handling.c \
		start_game.c check_uniques.c \
		fill_textures.c init_animation.c
OBJS = $(SRCS:.c=.o)

LIBRARY_DIRS = library/minilibx
LIBRARY = mlx Xext X11
LDFLAGS_LIBS = $(addprefix -L, $(LIBRARY_DIRS)) $(addprefix -l, $(LIBRARY))

MINILIBX_REPO = https://github.com/42Paris/minilibx-linux.git
MINILIBX_DIR = library/minilibx

all: $(MINILIBX_DIR) $(LIBRARY) $(NAME)

$(MINILIBX_DIR):
	@if [ ! -d "$(MINILIBX_DIR)" ]; then \
		git clone $(MINILIBX_REPO) $(MINILIBX_DIR); \
	fi

$(LIBRARY):
	$(foreach dir, $(LIBRARY_DIRS), make -C $(dir);)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(LDFLAGS_LIBS) -o $@
	$(MAKE) clean

clean:
	$(RM) $(OBJS)
	$(foreach dir, $(LIBRARY_DIRS), $(RM) $(dir)/*.a)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re $(MINILIBX_DIR)