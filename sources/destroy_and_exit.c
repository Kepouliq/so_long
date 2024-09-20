/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_and_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kepouliq <kepouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:18:23 by kepouliq          #+#    #+#             */
/*   Updated: 2024/09/19 17:47:52 by kepouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_and_exit(t_game *game)
{
	if (game->collectible_pic)
		mlx_destroy_image(game->mlx, game->collectible_pic);
	if (game->player_pic)
		mlx_destroy_image(game->mlx, game->player_pic);
	if (game->floor_pic)
		mlx_destroy_image(game->mlx, game->floor_pic);
	if (game->exit_pic)
		mlx_destroy_image(game->mlx, game->exit_pic);
	if (game->wall_pic)
		mlx_destroy_image(game->mlx, game->wall_pic);
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	if (game->map_fd)
		close(game->map_fd);
	if (game->flood_file_check)
		ft_free_tab(game->flood_file_check);
	if (game->map)
		ft_free_tab(game->map);
	free(game->mlx);
	exit(0);
}
