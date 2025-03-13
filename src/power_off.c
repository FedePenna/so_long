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
		game->map[i] = NULL;
		game->mapdup[i] = NULL;
		i++;
	}
	free(game->map);
	free(game->mapdup);
	game->map = NULL;
	game->mapdup = NULL;
}

void	free_maps2(t_data *game)
{
	int	i;

	i = 0;
	while (i < game->rows)
	{
		if (game->maptwo)
		{
			free(game->maptwo[i]);
			game->maptwo[i] = NULL;
		}
		i++;
	}
	if (game->maptwo)
	{	
		free(game->maptwo);
		game->maptwo = NULL;
	}
}

void	free_maps3(t_data *game)
{
	int	i;

	i = 0;
	while (i < game->rows)
	{
		if (game->mapthree)
		{
			free(game->mapthree[i]);
			game->mapthree[i] = NULL;
		}
		i++;
	}
	if (game->mapthree)
	{	
		free(game->mapthree);
		game->mapthree = NULL;
	}
}

void	free_textures(t_data *game)
{
	mlx_destroy_image(game->mlx, game->textures.coins);
	mlx_destroy_image(game->mlx, game->textures.exit);
	mlx_destroy_image(game->mlx, game->textures.ground);
	mlx_destroy_image(game->mlx, game->textures.wall);
	mlx_destroy_image(game->mlx, game->textures.player);
	mlx_destroy_image(game->mlx, game->textures.player_left);
	mlx_destroy_image(game->mlx, game->textures.player_right);
	mlx_destroy_image(game->mlx, game->textures.player_down);
	mlx_destroy_image(game->mlx, game->textures.enemy);
}

int	power_off(t_data *game)
{
	free_maps(game);
	free_maps2(game);
	free_maps3(game);
	free_textures(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
	return (0);
}
