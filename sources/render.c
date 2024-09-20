/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kepouliq <kepouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:47:40 by kepouliq          #+#    #+#             */
/*   Updated: 2024/09/19 17:11:04 by kepouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	display_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	game->window = mlx_new_window(game->mlx, game->width * 48, game->height
			* 48, "so_long");
	if (!game->window)
		return (0);
	return (1);
}

static int	pictures_loading(t_game *game)
{
	int	dont_care;

	game->collectible_pic = mlx_xpm_file_to_image(game->mlx,
			"./textures/coins.xpm", &dont_care, &dont_care);
	game->player_pic = mlx_xpm_file_to_image(game->mlx, "./textures/perso.xpm",
			&dont_care, &dont_care);
	game->floor_pic = mlx_xpm_file_to_image(game->mlx, "./textures/floor.xpm",
			&dont_care, &dont_care);
	game->exit_pic = mlx_xpm_file_to_image(game->mlx, "./textures/exit.xpm",
			&dont_care, &dont_care);
	game->wall_pic = mlx_xpm_file_to_image(game->mlx,
			"./textures/wall_tree.xpm", &dont_care, &dont_care);
	if (!game->collectible_pic || !game->player_pic || !game->floor_pic
		|| !game->exit_pic || !game->wall_pic)
		return (0);
	return (1);
}

static void	choice_pictures(t_game *game, int y, int x)
{
	if (game->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->window,
			game->floor_pic, x * 48, y * 48);
	else if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->window,
			game->wall_pic, x * 48, y * 48);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->window,
			game->collectible_pic, x * 48, y * 48);
	else if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->window,
			game->player_pic, x * 48, y * 48);
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->window,
			game->exit_pic, x * 48, y * 48);
}

static void	putting_pictures(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			choice_pictures(game, y, x);
			x++;
		}
		y++;
	}
}

int	render(t_game *game)
{
	if (!display_window(game))
		return (destroy_and_exit(game), 0);
	if (!pictures_loading(game))
		return (destroy_and_exit(game), 0);
	putting_pictures(game);
	return (0);
}
