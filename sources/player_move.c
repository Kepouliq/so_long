/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kepouliq <kepouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:35:41 by kepouliq          #+#    #+#             */
/*   Updated: 2024/09/19 17:05:26 by kepouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	switch_picture(t_game *game, void *new_pic, int x, int y)
{
	x *= 48;
	y *= 48;
	mlx_put_image_to_window(game->mlx, game->window, new_pic, x, y);
}

int	move_player(int key_code, t_game *game)
{
	static int	nb_move = 0;
	int			prev_x;
	int			prev_y;

	prev_x = game->player.x;
	prev_y = game->player.y;
	key_pressed(key_code, &nb_move, game);
	if (game->map[game->player.y][game->player.x] == 'C')
	{
		game->map[game->player.y][game->player.x] = '0';
		game->collectible--;
	}
	if (game->map[game->player.y][game->player.x] == 'E'
		&& game->collectible == 0)
	{
		ft_printf(CYAN "GG WP, JGL DIFF !\n" RESET);
		destroy_and_exit(game);
	}
	if (game->map[prev_y][prev_x] != 'E')
		switch_picture(game, game->floor_pic, prev_x, prev_y);
	else
		switch_picture(game, game->exit_pic, prev_x, prev_y);
	switch_picture(game, game->player_pic, game->player.x, game->player.y);
	return (0);
}
