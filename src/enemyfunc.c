/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemyfunc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepennar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:38:01 by fepennar          #+#    #+#             */
/*   Updated: 2025/03/07 17:04:35 by fepennar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_enemy(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->rows)
	{
		j = 0;
		while (j < game->cols)
		{
			if (game->map[i][j] == 'V' || game->map[i][j] == 'H')
			{
				game->enemy++;
				game->enemy_pos.row = i;
				game->enemy_pos.col = j;
			}
			j++;
		}
		i++;
	}
}


void	print_enemy(t_data *game, int i, int index)
{
	print_ground(game, i, index);
	mlx_put_image_to_window(game->mlx, game->win, \
		game->textures.blitzcrank, i * 64, (index * 64));
}
