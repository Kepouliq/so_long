/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kepouliq <kepouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 22:09:29 by kepouliq          #+#    #+#             */
/*   Updated: 2024/09/19 17:48:09 by kepouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf(RED "ERROR ! Incorrect number of args.\n" RESET);
		return (0);
	}
	ft_bzero(&game, sizeof(game));
	check_map_file(argv[1], &game);
	check_map(&game);
	check_flood_fill(&game);
	render(&game);
	mlx_key_hook(game.window, move_player, &game);
	mlx_hook(game.window, 33, 0, (void *)destroy_and_exit, &game);
	mlx_loop(game.mlx);
}
