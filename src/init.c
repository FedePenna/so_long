/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepennar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:33:14 by fepennar          #+#    #+#             */
/*   Updated: 2025/02/21 14:33:28 by fepennar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_textures(t_data *game)
{
	game->textures.ground = NULL;
	game->textures.coins = NULL;
	game->textures.wall = NULL;
	game->textures.viktor = NULL;
	game->textures.viktor_left = NULL;
	game->textures.viktor_right = NULL;
	game->textures.viktor_down = NULL;
	game->textures.exit = NULL;
	game->textures.blitzcrank = NULL;
}

void	init_game(t_data *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->height = 0;
	game->lenght = 0;
	game->map = NULL;
	game->mapdup = NULL;
	game->maptwo = NULL;
	game->mapthree = NULL;
	game->rows = 0;
	game->cols = 0;
	game->player_pos.row = 0;
	game->player_pos.col = 0;
	game->enemy_pos.row = 0;
	game->enemy_pos.col = 0;
	game->player_pos.directions = FRONT;
	game->player = 0;
	game->enemy = 0;
	game->coins = 0;
	game->exit = 0;
	game->moves = 0;
	game->score = 0;
	game->frames = 0;
	init_textures(game);
}
