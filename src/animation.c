/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepennar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:39:29 by fepennar          #+#    #+#             */
/*   Updated: 2025/03/28 17:39:32 by fepennar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	animate_f(t_data *game, int i, int index)
{
	if (game->frames >= 0 && game->frames <= 200)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->textures.player, i * 64, (index * 64));
	if (game->frames >= 201 && game->frames <= 400)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->textures.fidle_a, i * 64, (index * 64));
	if (game->frames >= 401 && game->frames <= 600)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->textures.player, i * 64, (index * 64));
	if (game->frames >= 601 && game->frames <= 800)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->textures.fidle_b, i * 64, (index * 64));
}

void	animate_b(t_data *game, int i, int index)
{
	if (game->frames >= 0 && game->frames <= 200)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->textures.player_down, i * 64, (index * 64));
	if (game->frames >= 201 && game->frames <= 400)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->textures.bidle_a, i * 64, (index * 64));
	if (game->frames >= 401 && game->frames <= 600)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->textures.player_down, i * 64, (index * 64));
	if (game->frames >= 601 && game->frames <= 800)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->textures.bidle_b, i * 64, (index * 64));
}

void	animate_l(t_data *game, int i, int index)
{
	if (game->frames >= 0 && game->frames <= 200)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->textures.player_left, i * 64, (index * 64));
	if (game->frames >= 201 && game->frames <= 400)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->textures.lidle, i * 64, (index * 64));
	if (game->frames >= 401 && game->frames <= 600)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->textures.player_left, i * 64, (index * 64));
	if (game->frames >= 601 && game->frames <= 800)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->textures.lidle, i * 64, (index * 64));
}

void	animate_r(t_data *game, int i, int index)
{
	if (game->frames >= 0 && game->frames <= 200)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->textures.player_right, i * 64, (index * 64));
	if (game->frames >= 201 && game->frames <= 400)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->textures.ridle, i * 64, (index * 64));
	if (game->frames >= 401 && game->frames <= 600)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->textures.player_right, i * 64, (index * 64));
	if (game->frames >= 601 && game->frames <= 800)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->textures.ridle, i * 64, (index * 64));
}

void	animate(t_data *game, int i, int index)
{
	if (game->player_pos.dir == FRONT)
		animate_f(game, i, index);
	else if (game->player_pos.dir == BACK)
		animate_b(game, i, index);
	else if (game->player_pos.dir == LEFT)
		animate_l(game, i, index);
	else if (game->player_pos.dir == RIGHT)
		animate_r(game, i, index);
}
