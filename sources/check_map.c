/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kepouliq <kepouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:40:21 by kepouliq          #+#    #+#             */
/*   Updated: 2024/09/19 17:44:33 by kepouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_map_letters(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] != '1' && (game->map[y][x] != 'P')
				&& (game->map[y][x] != 'C') && (game->map[y][x] != 'E')
				&& (game->map[y][x] != '0'))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

static int	check_rectangular_and_epc(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->number_of_player++;
				game->player = (t_player){.x = x, .y = y};
			}
			game->collectible += (game->map[y][x] == 'C');
			game->end += (game->map[y][x] == 'E');
			if (ft_strlen(game->map[0]) != ft_strlen(game->map[y]))
				return (0);
			x++;
		}
		y++;
	}
	return (game->width = x, game->height = y, 1);
}

static int	check_if_map_closed(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		if (game->map[i][0] != '1' || game->map[i][game->width - 1] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (game->map[0][i])
	{
		if (game->map[0][i] != '1' || game->map[game->height - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_map(t_game *game)
{
	if (!check_map_letters(game))
		return (ft_printf(RED "Wron character deteted ?!\n" RESET),
			destroy_and_exit(game), 0);
	if (!check_rectangular_and_epc(game))
		return (ft_printf(RED "Map not rectagular ?!\n" RESET),
			destroy_and_exit(game), 0);
	if (game->collectible == 0 || game->end != 1 || game->number_of_player != 1)
		return (ft_printf(RED "Map not vadid (number of P,E or C) ?!\n" RESET),
			destroy_and_exit(game), 0);
	if (game->width > 40 || game->height > 21)
		return (ft_printf(RED "Map too big ?!\n" RESET), destroy_and_exit(game),
			0);
	if (!check_if_map_closed(game))
		return (ft_printf(RED "Map not closed ?!\n" RESET),
			destroy_and_exit(game), 0);
	return (0);
}
