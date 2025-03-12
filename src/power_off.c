/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power_off.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepennar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:05:57 by fepennar          #+#    #+#             */
/*   Updated: 2025/03/07 17:05:27 by fepennar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_maps(t_data *game)
{
	int	i;

	i = 0;
	while (i < game->rows)
	{
		free(game->map[i]);
		free(game->mapdup[i]);
		free(game->maptwo[i]);
		free(game->mapthree[i]);
		game->map[i] = NULL;
		game->mapdup[i] = NULL;
		game->maptwo[i] = NULL;
		game->mapthree[i] = NULL;
		i++;
	}
	free(game->map);
	free(game->mapdup);
	free(game->maptwo);
	free(game->mapthree);
	free_textures(game);
	game->map = NULL;
	game->mapdup = NULL;
	game->maptwo = NULL;
	game->mapthree = NULL;
}

void	free_textures(t_data *game)
{
	mlx_destroy_image(game->mlx, game->textures.coins);
	mlx_destroy_image(game->mlx, game->textures.exit);
	mlx_destroy_image(game->mlx, game->textures.ground);
	mlx_destroy_image(game->mlx, game->textures.wall);
	mlx_destroy_image(game->mlx, game->textures.viktor);
	mlx_destroy_image(game->mlx, game->textures.viktor_left);
	mlx_destroy_image(game->mlx, game->textures.viktor_right);
	mlx_destroy_image(game->mlx, game->textures.viktor_down);
	mlx_destroy_image(game->mlx, game->textures.blitzcrank);
}

int	power_off(t_data *game)
{
	free_maps(game);
	free_textures(game);
	mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	exit(0);
	return (0);
}
