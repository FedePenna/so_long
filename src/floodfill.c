/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepennar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:12:35 by fepennar          #+#    #+#             */
/*   Updated: 2025/02/24 15:13:40 by fepennar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	flood_check(t_data *game, char **map)
{
	int	i;
	int	j;

	i = 0;
	if (!map)
		return (1);
	while (i < game->rows)
	{
		j = 0;
		while (j < game->cols)
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static void	floodfill(char **map, int rows, int cols)
{
	if (map[rows][cols] == 'F' || map[rows][cols] == '1' || \
		map[rows][cols] == 'H')
		return ;
	map[rows][cols] = 'F';
	floodfill(map, rows - 1, cols);
	floodfill(map, rows + 1, cols);
	floodfill(map, rows, cols - 1);
	floodfill(map, rows, cols + 1);
}

void	enemy_search(t_data *game, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->rows)
	{
		j = 0;
		while (j < game->cols)
		{
			if (map[i][j] == 'H' || map[i][j] == 'V')
				dup_map(game, i, j);
			j++;
		}
		i++;
	}
}

void	flood_prep(t_data *game)
{
	int	i;

	game->mapdup = (char **)malloc(sizeof(char *) * (game->rows + 1));
	if (game->mapdup == NULL)
		ft_error_message("A Memory Allocation has failed");
	i = 0;
	while (i < game->rows)
	{
		game->mapdup[i] = ft_strdup(game->map[i]);
		if (game->mapdup[i] == NULL)
			ft_error_message("A Memory Allocation has failed");
		i++;
	}
	game->mapdup[i] = NULL;
	enemy_search(game, game->mapdup);
	floodfill(game->mapdup, game->player_pos.row, game->player_pos.col);
	if (game->maptwo != NULL)
		floodfill(game->maptwo, game->player_pos.row, game->player_pos.col);
	if (game->mapthree != NULL)
		floodfill(game->mapthree, game->player_pos.row, game->player_pos.col);
	if (flood_check(game, game->mapdup) == 1 && \
		flood_check(game, game->maptwo) == 1 && \
		flood_check(game, game->mapthree) == 1)
		ft_error_message("The enemy is blocking the exit!!");
}
