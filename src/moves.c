/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepennar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:05:08 by fepennar          #+#    #+#             */
/*   Updated: 2025/03/07 17:05:10 by fepennar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_enemy(t_data *game, int row, int col)
{
	if (game->map[row][col] == 'V')
		move_enemy_y(game, row, col);
	else if (game->map[row][col] == 'H')
		move_enemy_x(game, row, col);
}

static void	move_events(t_data *game)
{
	if (game->map[game->player_pos.row][game->player_pos.col] == 'C')
	{
		game->score++;
		game->coins--;
		ft_printf("Score : %i\n", game->score);
		if (game->coins == 1)
			ft_printf("Message Of Your Choice?\n");
	}
	if (game->map[game->player_pos.row][game->player_pos.col] == 'H' \
		|| game->map[game->player_pos.row][game->player_pos.col] == 'V')
		kill_player(game);
	if (game->map[game->player_pos.row][game->player_pos.col] == 'E' \
		&& game->coins == 0)
	{
		ft_printf("\nKABLOW!!\nHow was the anaphylactic shock like?\n");
		ft_printf("Welcome to Weedheaven\n");
		power_off(game);
	}
}

static void	move_player(t_data *game, int row, int col)
{
	if (game->map[row][col] == 'E' && game->coins != 0)
	{
		ft_printf("\nMessage Of Your Choice");
		ft_printf("\nMessage Of Your Choice %i\n", game->coins);
		return ;
	}
	if (game->map[row][col] != 'H' && game->map[row][col] != 'V')
		game->map[game->player_pos.row][game->player_pos.col] = '0';
	game->player_pos.row = row;
	game->player_pos.col = col;
	move_events(game);
	game->map[game->player_pos.row][game->player_pos.col] = 'P';
	game->moves++;
	ft_printf("Moves : %i\n", game->moves);
}

void	move_check(int keycode, t_data *game)
{
	if (keycode == W)
	{
		game->player_pos.dir = BACK;
		if (game->map[game->player_pos.row - 1][game->player_pos.col] != '1')
			move_player(game, game->player_pos.row - 1, game->player_pos.col);
	}
	if (keycode == A)
	{
		game->player_pos.dir = LEFT;
		if (game->map[game->player_pos.row][game->player_pos.col - 1] != '1')
			move_player(game, game->player_pos.row, game->player_pos.col - 1);
	}
	if (keycode == S)
	{
		game->player_pos.dir = FRONT;
		if (game->map[game->player_pos.row + 1][game->player_pos.col] != '1')
			move_player(game, game->player_pos.row + 1, game->player_pos.col);
	}
	if (keycode == D)
	{
		game->player_pos.dir = RIGHT;
		if (game->map[game->player_pos.row][game->player_pos.col + 1] != '1')
			move_player(game, game->player_pos.row, game->player_pos.col + 1);
	}
}
