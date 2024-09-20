/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kepouliq <kepouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:38:58 by kepouliq          #+#    #+#             */
/*   Updated: 2024/09/19 15:15:15 by kepouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_up(t_game *game, int *nb_move)
{
	if (game->map[game->player.y - 1][game->player.x] != '1')
	{
		*nb_move += 1;
		game->player.y--;
		ft_printf(MAGENTA "Number of movements : %d\n" RESET, *nb_move);
	}
}

static void	move_down(t_game *game, int *nb_move)
{
	if (game->map[game->player.y + 1][game->player.x] != '1')
	{
		*nb_move += 1;
		game->player.y++;
		ft_printf(MAGENTA "Number of movements : %d\n" RESET, *nb_move);
	}
}

static void	move_left(t_game *game, int *nb_move)
{
	if (game->map[game->player.y][game->player.x - 1] != '1')
	{
		*nb_move += 1;
		game->player.x--;
		ft_printf(MAGENTA "Number of movements : %d\n" RESET, *nb_move);
	}
}

static void	move_right(t_game *game, int *nb_move)
{
	if (game->map[game->player.y][game->player.x + 1] != '1')
	{
		*nb_move += 1;
		game->player.x++;
		ft_printf(MAGENTA "Number of movements : %d\n" RESET, *nb_move);
	}
}

void	key_pressed(int key_value, int *nb_move, t_game *game)
{
	if (key_value == KEY_ESC)
		destroy_and_exit(game);
	else if (key_value == KEY_UP)
		move_up(game, nb_move);
	else if (key_value == KEY_DOWN)
		move_down(game, nb_move);
	else if (key_value == KEY_LEFT)
		move_left(game, nb_move);
	else if (key_value == KEY_RIGHT)
		move_right(game, nb_move);
}
