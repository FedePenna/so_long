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
		"textures/terra.xpm", &game->lenght, &game->height);
	game->textures.coins = mlx_xpm_file_to_image(game->mlx, \
		"textures/.hexblunts.xpm", &game->lenght, &game->height);
	game->textures.exit = mlx_xpm_file_to_image(game->mlx, \
		"textures/exit.xpm", &game->lenght, &game->height);
	game->textures.wall = mlx_xpm_file_to_image(game->mlx, \
		"textures/wall.xpm", &game->lenght, &game->height);
	game->textures.viktor = mlx_xpm_file_to_image(game->mlx, \
		"textures/viktor.xpm", &game->lenght, &game->height);
	game->textures.viktor_left = mlx_xpm_file_to_image(game->mlx, \
		"textures/viktor.xpm", &game->lenght, &game->height);
	game->textures.viktor_right = mlx_xpm_file_to_image(game->mlx, \
		"textures/viktor.xpm", &game->lenght, &game->height);
	game->textures.viktor_down = mlx_xpm_file_to_image(game->mlx, \
		"textures/viktor.xpm", &game->lenght, &game->height);
	game->textures.blitzcrank = mlx_xpm_file_to_image(game->mlx, \
		"textures/blitzcrank.xpm", &game->lenght, &game->height);
}
