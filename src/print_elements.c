/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepennar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:04:52 by fepennar          #+#    #+#             */
/*   Updated: 2025/03/07 17:04:54 by fepennar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_ground(t_data *game, int i, int index)
{
	mlx_put_image_to_window(game->mlx, game->win, \
		game->textures.ground, i * 64, index * 64);
}

void	print_coin(t_data *game, int i, int index)
{
	print_ground(game, i, index);
	mlx_put_image_to_window(game->mlx, game->win, \
		game->textures.coins, i * 64, (index * 64));
}

void	print_player(t_data *game, int i, int index)
{
	print_ground(game, i, index);
	if (game->player_pos.directions == FRONT)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->textures.player, i * 64, (index * 64));
	else if (game->player_pos.directions == BACK)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->textures.player_down, i * 64, (index * 64));
	else if (game->player_pos.directions == LEFT)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->textures.player_left, i * 64, (index * 64));
	else if (game->player_pos.directions == RIGHT)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->textures.player_right, i * 64, (index * 64));
}

void	print_exit(t_data *game, int i, int index)
{
	print_ground(game, i, index);
	mlx_put_image_to_window(game->mlx, game->win, \
		game->textures.exit, i * 64, (index * 64));
}

void	print_wall(t_data *game, int i, int index)
{
	mlx_put_image_to_window(game->mlx, game->win, \
		game->textures.wall, i * 64, (index * 64));
}
