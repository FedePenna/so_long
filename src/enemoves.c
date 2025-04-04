/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemoves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepennar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:22:58 by fepennar          #+#    #+#             */
/*   Updated: 2025/03/18 16:23:01 by fepennar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right_x(t_data *game, int rows, int cols)
{
	if (game->map[rows][cols + 1] == 'P')
		kill_player(game);
	game->map[rows][cols + 1] = 'H';
	game->map[rows][cols] = '0';
	game->enemy_pos.col += 1;
	game->enemy_pos.e_dir = LEFT;
}

void	move_mid_x(t_data *game, int rows, int cols)
{
	if (game->enemy_pos.e_dir == LEFT)
	{
		game->map[rows][cols] = '0';
		if (game->map[rows][cols - 1] == 'P')
			kill_player(game);
		game->map[rows][cols - 1] = 'H';
		game->enemy_pos.col -= 1;
	}
	else
	{
		game->map[rows][cols] = '0';
		if (game->map[rows][cols + 1] == 'P')
			kill_player(game);
		game->map[rows][cols + 1] = 'H';
		game->enemy_pos.col += 1;
	}
}

void	move_right_y(t_data *game, int rows, int cols)
{
	if (game->map[rows + 1][cols] == 'P')
		kill_player(game);
	game->map[rows + 1][cols] = 'V';
	game->map[rows][cols] = '0';
	game->enemy_pos.row += 1;
	game->enemy_pos.e_dir = BACK;
}

void	move_mid_y(t_data *game, int rows, int cols)
{
	if (game->enemy_pos.e_dir == BACK)
	{
		game->map[rows][cols] = '0';
		if (game->map[rows - 1][cols] == 'P')
			kill_player(game);
		game->map[rows - 1][cols] = 'V';
		game->enemy_pos.row -= 1;
	}
	else
	{
		game->map[rows][cols] = '0';
		if (game->map[rows + 1][cols] == 'P')
			kill_player(game);
		game->map[rows + 1][cols] = 'V';
		game->enemy_pos.row += 1;
	}
}
