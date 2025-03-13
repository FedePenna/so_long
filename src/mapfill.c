/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapfill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepennar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 16:54:02 by fepennar          #+#    #+#             */
/*   Updated: 2025/03/07 17:00:15 by fepennar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_elements(t_data *game, char *line, int index)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == 'P')
			print_player(game, i, index);
		else if (line[i] == 'C')
			print_coin(game, i, index);
		else if (line[i] == 'E')
			print_exit(game, i, index);
		else if (line[i] == '1')
			print_wall(game, i, index);
		else if (line[i] == '0')
			print_ground(game, i, index);
		else if (line[i] == 'H' || line[i] == 'V')
			print_enemy(game, i, index);
	}
}

void	item_to_window(t_data *game)
{
	int		i;
	char	*moves;
	char	*points;

	i = 0;
	moves = ft_itoa(game->moves);
	points = ft_itoa(game->score);
	while (game->map[i] != NULL)
	{	
		print_elements(game, game->map[i], i);
		i++;
	}
	mlx_string_put(game->mlx, game->win, 64 + 30, \
		(game->rows * 64) - 10, 0x000000, "Moves :");
	mlx_string_put(game->mlx, game->win, 64 + 80, \
	(game->rows * 64) - 10, 0x000000, moves);
	mlx_string_put(game->mlx, game->win, 64 + 120, \
	(game->rows * 64) - 10, 0x000000, "Score :");
	mlx_string_put(game->mlx, game->win, 64 + 170, \
	(game->rows * 64) - 10, 0x000000, points);
	free(moves);
	free(points);
}
