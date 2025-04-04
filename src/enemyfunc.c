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
/*SIDE NOTE
  My Enemies move like this 0H0->00H->0H0->H00->0H0 and so on,
  same thing for vertical But i don't think you need another scheme
  to understand how it moves*/

void	kill_player(t_data *game)
{
	ft_printf("Message Of Your Choice\n");
	power_off(game);
}

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
				if (game->map[i][j] == 'H')
					game->enemy_pos.e_dir = RIGHT;
				else if (game->map[i][j] == 'V')
					game->enemy_pos.e_dir = BACK;
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
		game->textures.enemy, i * 64, (index * 64));
}

void	move_enemy_x(t_data *game, int rows, int cols)
{
	static int	sign;

	if (game->maptwo && game->enemy_pos.e_dir == RIGHT && sign != 1)
	{
		move_right_x(game, rows, cols);
		sign = 1;
	}
	else if (game->mapthree && game->enemy_pos.e_dir == LEFT && sign != 1)
	{
		if (game->map[rows][cols - 1] == 'P')
			kill_player(game);
		game->map[rows][cols - 1] = 'H';
		game->map[rows][cols] = '0';
		game->enemy_pos.col -= 1;
		game->enemy_pos.e_dir = RIGHT;
		sign = 1;
	}
	else if (sign == 1)
	{
		move_mid_x(game, rows, cols);
		sign = 0;
	}
}

void	move_enemy_y(t_data *game, int rows, int cols)
{
	static int	sign;

	if (game->maptwo && game->enemy_pos.e_dir == FRONT && sign != 1)
	{
		move_right_y(game, rows, cols);
		sign = 1;
	}
	else if (game->mapthree && game->enemy_pos.e_dir == BACK && sign != 1)
	{
		if (game->map[rows - 1][cols] == 'P')
			kill_player(game);
		game->map[rows - 1][cols] = 'V';
		game->map[rows][cols] = '0';
		game->enemy_pos.row -= 1;
		game->enemy_pos.e_dir = FRONT;
		sign = 1;
	}
	else if (sign == 1)
	{
		move_mid_y(game, rows, cols);
		sign = 0;
	}
}
