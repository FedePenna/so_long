/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepennar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:00:21 by fepennar          #+#    #+#             */
/*   Updated: 2025/03/12 14:00:24 by fepennar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	craft_map2(t_data *game)
{
	int	i;

	game->mapthree = (char **)malloc(sizeof(char *) * (game->rows + 1));
	if (game->mapthree == NULL)
		ft_error_message("A Memory Allocation has failed", game);
	i = 0;
	while (i < game->rows)
	{
		game->mapthree[i] = ft_strdup(game->mapdup[i]);
		if (game->mapthree[i] == NULL)
			ft_error_message("A Memory Allocation has failed", game);
		i++;
	}
	game->mapthree[i] = NULL;
}

void	craft_map1(t_data *game)
{
	int	i;

	game->maptwo = (char **)malloc(sizeof(char *) * (game->rows + 1));
	if (game->maptwo == NULL)
		ft_error_message("A Memory Allocation has failed", game);
	i = 0;
	while (i < game->rows)
	{
		game->maptwo[i] = ft_strdup(game->mapdup[i]);
		if (game->maptwo[i] == NULL)
			ft_error_message("A Memory Allocation has failed", game);
		i++;
	}
	game->maptwo[i] = NULL;
}

void	dup_map_v(t_data *game, int erows, int ecols)
{
	if (game->mapdup[erows + 1][ecols] == '0')
	{
		game->mapdup[erows][ecols] = '0';
		game->mapdup[erows + 1][ecols] = 'V';
		craft_map1(game);
	}
	if (game->maptwo)
		game->mapdup[erows + 1][ecols] = '0';
	if (game->mapdup[erows - 1][ecols] == '0')
	{
		game->mapdup[erows - 1][ecols] = 'V';
		game->mapdup[erows][ecols] = '0';
		craft_map2(game);
	}
	game->mapdup[erows][ecols] = 'V';
	if (game->mapthree)
		game->mapdup[erows][ecols - 1] = '0';
}

void	dup_map_h(t_data *game, int erows, int ecols)
{
	if (game->mapdup[erows][ecols + 1] == '0')
	{
		game->mapdup[erows][ecols] = '0';
		game->mapdup[erows][ecols + 1] = 'H';
		craft_map1(game);
	}
	if (game->maptwo)
		game->mapdup[erows][ecols + 1] = '0';
	if (game->mapdup[erows][ecols - 1] == '0')
	{
		game->mapdup[erows][ecols - 1] = 'H';
		game->mapdup[erows][ecols] = '0';
		craft_map2(game);
	}
	game->mapdup[erows][ecols] = 'H';
	if (game->mapthree)
		game->mapdup[erows][ecols - 1] = '0';
}

	/* The If (gmaptwo || gmapthree) below was because of something shitty
	   i encountered you may try to remove it if you like Long Story Short
	   i was moving the enemy as response to the player movement but it caused
	   crashes, So i made sure it moved following game->frames and it fixed
	   the problems and the reason i made this if and i was
	   too lazy to fix it (might do it eventually):P*/

void	dup_map(t_data *game, int erows, int ecols)
{
	if (game->mapdup[erows][ecols] == 'H')
		dup_map_h(game, erows, ecols);
	else if (game->mapdup[erows][ecols] == 'V')
		dup_map_v(game, erows, ecols);
	if (!game->maptwo || !game->mapthree)
	{
		free_maps(game);
		free_maps2(game);
		free_maps3(game);
		ft_error_message("The Enemy Cannot Patrol Properly !!", game);
	}
}
