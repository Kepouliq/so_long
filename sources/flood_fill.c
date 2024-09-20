/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kepouliq <kepouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:39:05 by kepouliq          #+#    #+#             */
/*   Updated: 2024/09/19 17:04:35 by kepouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	flood_fill(t_game *game, int x, int y)
{
	game->flood_file_check[y][x] = 'K';
	if (game->flood_file_check[y - 1][x] != '1' && game->flood_file_check[y
		- 1][x] != 'K')
		flood_fill(game, x, y - 1);
	if (game->flood_file_check[y + 1][x] != '1' && game->flood_file_check[y
		+ 1][x] != 'K')
		flood_fill(game, x, y + 1);
	if (game->flood_file_check[y][x - 1] != '1' && game->flood_file_check[y][x
		- 1] != 'K')
		flood_fill(game, x - 1, y);
	if (game->flood_file_check[y][x + 1] != '1' && game->flood_file_check[y][x
		+ 1] != 'K')
		flood_fill(game, x + 1, y);
}

void	check_flood_fill(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	flood_fill(game, game->player.x, game->player.y);
	while (game->flood_file_check[y])
	{
		x = 0;
		while (game->flood_file_check[y][x])
		{
			if (game->flood_file_check[y][x] == 'C'
				|| game->flood_file_check[y][x] == 'E')
			{
				ft_printf(RED "Exit or collectible not accessible !?\n" RESET);
				destroy_and_exit(game);
			}
			x++;
		}
		y++;
	}
}
