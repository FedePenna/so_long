/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                        :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: fepennar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:33:48 by fepennar          #+#    #+#             */
/*   Updated: 2025/02/21 14:34:08 by fepennar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	gnl_row(t_data *game, char *mappath)
{
	int		fd;
	char	*line;

	fd = open(mappath, O_RDONLY);
	if (fd < 0)
		ft_error_message("The map wasn't found");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		game->rows++;
	}
	close(fd);
	free(line);
}

void	create_map(t_data *game, char *mappath)
{
	int	i;
	int	fd;

	i = 0;
	gnl_row(game, mappath);
	if (game->rows == 0)
		ft_error_message("the following \"map\" has no rows");
	fd = open (mappath, O_RDONLY);
	if (fd < 0)
		ft_error_message("The map wasn't found");
	game->map = (char **)malloc(sizeof(char *) * (game->rows + 1));
	if (!game->map)
		ft_error_message("The memory allocation for the map's creation failed");
	while (i < game->rows)
	{
		game->map[i] = get_next_line(fd);
		
		if (!(game->map[i]))
			break ;
		i++;
	}
	game->map[i] = NULL;
	game->cols = ft_strlen(game->map[0]) - 1;
	close(fd);
}
