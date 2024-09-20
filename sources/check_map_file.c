/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kepouliq <kepouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 21:26:59 by kepouliq          #+#    #+#             */
/*   Updated: 2024/09/19 17:46:49 by kepouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*read_map(int fd)
{
	char	*map_data;
	char	*buff;
	char	*temp;
	int		read_return ;

	buff = ft_calloc((10000 + 1), sizeof(char));
	if (!buff)
		return (NULL);
	read_return = 1;
	map_data = NULL;
	map_data = ft_strdup("");
	while (read_return)
	{
		read_return = (read(fd, buff, 10000));
		if (read_return == -1)
			return (free(map_data), free(buff), NULL);
		buff[read_return] = '\0';
		temp = map_data;
		map_data = ft_strjoin(map_data, buff);
		free(temp);
	}
	if (!map_data || !map_data[0])
		return (free(map_data), free(buff), NULL);
	return (free(buff), close(fd), map_data);
}

static int	check_extension(char *file_name)
{
	int	i;
	int	_return_;

	i = ft_strlen(file_name);
	if (i < 4)
		return (0);
	_return_ = ft_strncmp(file_name + i - 4, ".ber", 4);
	return (_return_ == 0);
}

int	check_map_file(char *map_file, t_game *game)
{
	char	*map_content;

	if (!check_extension(map_file))
		return (ft_printf(RED "Error with map file ?!\n" RESET), 0);
	game->map_fd = open(map_file, O_RDONLY);
	if (game->map_fd == -1)
		return (ft_printf(RED "Map file exist ?!\n" RESET),
			destroy_and_exit(game), 0);
	map_content = read_map(game->map_fd);
	if (!map_content)
		return (ft_printf(RED "Map content empty ?!\n" RESET),
			destroy_and_exit(game), 0);
	if (ft_strnstr(map_content, "\n\n", ft_strlen(map_content)))
		return (ft_printf(RED "Double newline detected ?!\n"
				RESET), free(map_content), destroy_and_exit(game), 0);
	game->flood_file_check = ft_split(map_content, '\n');
	game->map = ft_split(map_content, '\n');
	if (!game->map || !game->flood_file_check)
		return (free(map_content), destroy_and_exit(game), 0);
	free(map_content);
	return (0);
}
