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

static void	move_events(t_data *game)
{
	if (game->map[game->player_pos.row][game->player_pos.col] == 'C')
	{
		game->score++;
		game->coins--;
		ft_printf("Score : %i\n", game->score);
		if (game->coins == '1')
			ft_printf("\nAren't ya feeling a little high crippled man?");
	}
	if (game->map[game->player_pos.row][game->player_pos.col] == 'H' \
		|| game->map[game->player_pos.row][game->player_pos.col] == 'V')
	{
		ft_printf("\nYou should really stop smoking that shit dude");
		power_off(game);
	}
	if (game->map[game->player_pos.row][game->player_pos.col] == 'E' \
		&& game->coins == '0')
	{
		ft_printf("\nKABLOW!!\n How was the anaphylactic shock like? \
			Welcome To Weedheaven");
		power_off(game);
	}
}

static void	move_player(t_data *game, int row, int col)
{
	if (game->map[row][col] == 'E' && game->coins != '0')
	{
		ft_printf("\nYou aren't high enough to cross the hexweed gate");
		ft_printf("\nYou still have %i Hexblunts to smoke", game->coins);
		return ;
	}
	game->map[game->player_pos.row][game->player_pos.col] = '0';
	game->player_pos.row = row;
	game->player_pos.col = col;
	move_events(game);
	game->map[game->player_pos.row][game->player_pos.col] = 'P';
	game->moves++;
	// move_enemy(game, game->enemy_pos.row, game->enemy_pos.col);
	ft_printf("Moves : %i\n", game->moves);
}

void	move_check(int keycode, t_data *game)
{
	game->frames++;
	if (keycode == W)
	{
		game->player_pos.directions = BACK;
		if (game->map[game->player_pos.row - 1][game->player_pos.col] != '1')
			move_player(game, game->player_pos.row - 1, game->player_pos.col);
	}
	if (keycode == A)
	{
		game->player_pos.directions = LEFT;
		if (game->map[game->player_pos.row][game->player_pos.col - 1] != '1')
			move_player(game, game->player_pos.row, game->player_pos.col - 1);
	}
	if (keycode == S)
	{
		game->player_pos.directions = FRONT;
		if (game->map[game->player_pos.row + 1][game->player_pos.col] != '1')
			move_player(game, game->player_pos.row + 1, game->player_pos.col);
	}
	if (keycode == D)
	{
		game->player_pos.directions = RIGHT;
		if (game->map[game->player_pos.row][game->player_pos.col + 1] != '1')
			move_player(game, game->player_pos.row, game->player_pos.col + 1);
	}
}
