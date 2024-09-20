/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kepouliq <kepouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 21:06:06 by kepouliq          #+#    #+#             */
/*   Updated: 2024/09/19 16:58:17 by kepouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf.h"
# include "libft.h"
# include "mlx.h"
# include <X11/Xlib.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>

# define RESET "\e[0m"
# define RED "\e[1;91m"
# define GREEN "\e[1;92m"
# define BLUE "\e[1;94m"
# define YELLOW "\e[1;93m"
# define MAGENTA "\e[1;95m"
# define CYAN "\e[1;96m"
# define WHITE "\e[1;97m"
# define BLACK "\e[1;90m"
# define GRAY "\e[1;37m"

# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100

typedef struct s_player
{
	int			x;
	int			y;
}				t_player;

typedef struct s_game
{
	int			height;
	int			width;
	int			end;
	int			number_of_player;
	int			map_fd;
	int			collectible;
	char		**flood_file_check;
	char		**map;
	void		*mlx;
	void		*window;
	void		*wall_pic;
	void		*player_pic;
	void		*floor_pic;
	void		*collectible_pic;
	void		*exit_pic;
	t_player	player;
}				t_game;

// CHECKS :

int				check_map_file(char *map_file, t_game *game);
int				check_map(t_game *game);
void			check_flood_fill(t_game *game);

// RENDER :

int				render(t_game *game);

// MOVES :

void			key_pressed(int key_value, int *nb_move, t_game *game);
int				move_player(int key_code, t_game *game);

// EXIT

void			destroy_and_exit(t_game *game);

#endif