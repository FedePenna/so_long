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
/* SIDE NOTE
   The Following Function compiles only with the TIMER flag in the makefile,
   if you want to have the countdown just do "make timer"*/
int	countdown(t_data *game, char *moves, char *points)
{
	static int	countdown;
	static int	sign;

	if (sign != 1)
	{
		countdown = 20;
		sign = 1;
	}
	if (game->frames == 200)
	{
		countdown--;
		ft_printf("\nMessage of your choice, you have %i seconds left\n", \
			countdown);
	}
	if (countdown == 0)
	{
		ft_printf("\nMessage of your choice");
		free(moves);
		free(points);
		power_off(game);
	}
	return (1);
}

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
		(game->rows * 64) - 10, 0xFFFFFF, "Moves :");
	mlx_string_put(game->mlx, game->win, 64 + 80, \
	(game->rows * 64) - 10, 0xFFFFFF, moves);
	mlx_string_put(game->mlx, game->win, 64 + 120, \
	(game->rows * 64) - 10, 0xFFFFFF, "Score :");
	mlx_string_put(game->mlx, game->win, 64 + 170, \
	(game->rows * 64) - 10, 0xFFFFFF, points);
	if (TIMER == 1)
		countdown(game, moves, points);
	free(moves);
	free(points);
}
