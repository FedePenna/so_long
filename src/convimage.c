/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convimage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepennar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:03:02 by fepennar          #+#    #+#             */
/*   Updated: 2025/03/07 17:03:04 by fepennar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	convert_image(t_data *game)
{
	game->textures.ground = mlx_xpm_file_to_image(game->mlx, \
		"textures/.xpm", &game->lenght, &game->height);
	game->textures.coins = mlx_xpm_file_to_image(game->mlx, \
		"textures/.xpm", &game->lenght, &game->height);
	game->textures.exit = mlx_xpm_file_to_image(game->mlx, \
		"textures/.xpm", &game->lenght, &game->height);
	game->textures.wall = mlx_xpm_file_to_image(game->mlx, \
		"textures/.xpm", &game->lenght, &game->height);
	game->textures.player = mlx_xpm_file_to_image(game->mlx, \
		"textures/.xpm", &game->lenght, &game->height);
	game->textures.player_left = mlx_xpm_file_to_image(game->mlx, \
		"textures/.xpm", &game->lenght, &game->height);
	game->textures.player_right = mlx_xpm_file_to_image(game->mlx, \
		"textures/.xpm", &game->lenght, &game->height);
	game->textures.player_down = mlx_xpm_file_to_image(game->mlx, \
		"textures/.xpm", &game->lenght, &game->height);
	game->textures.enemy = mlx_xpm_file_to_image(game->mlx, \
		"textures/.xpm", &game->lenght, &game->height);
}
