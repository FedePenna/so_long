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
/*Have fun with your Own Textures 
  So you can have an idea on how you wanna make it look like
  SIDE NOTE
  So Part of the bonus is sprite animation, putting a character that changes
  directions to left/right/back/front is technically considered as such, but
  as a corrector i'd put a 3 out of 5 bonus points on the correction sheet*/

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
	convert_animations(game);
}
/* You may comment this if you  don't have any animations for your Player*/

void	convert_animations(t_data *game)
{
	game->textures.fidle_a = mlx_xpm_file_to_image(game->mlx, \
		"textures/.xpm", &game->lenght, &game->height);
	game->textures.fidle_b = mlx_xpm_file_to_image(game->mlx, \
		"textures/.xpm", &game->lenght, &game->height);
	game->textures.ridle = mlx_xpm_file_to_image(game->mlx, \
		"textures/.xpm", &game->lenght, &game->height);
	game->textures.lidle = mlx_xpm_file_to_image(game->mlx, \
		"textures/.xpm", &game->lenght, &game->height);
	game->textures.bidle_a = mlx_xpm_file_to_image(game->mlx, \
		"textures/.xpm", &game->lenght, &game->height);
	game->textures.bidle_b = mlx_xpm_file_to_image(game->mlx, \
		"textures/.xpm", &game->lenght, &game->height);
}
