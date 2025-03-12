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
		ft_error_message("A Memory Allocation has failed");
	i = 0;
	while (i < game->rows)
	{
		game->mapthree[i] = ft_strdup(game->mapdup[i]);
		if (game->mapthree[i] == NULL)
			ft_error_message("A Memory Allocation has failed");
		i++;
	}
	game->mapthree[i] = NULL;
}

void	craft_map1(t_data *game)
{
	int	i;

	game->maptwo = (char **)malloc(sizeof(char *) * (game->rows + 1));
	if (game->maptwo == NULL)
		ft_error_message("A Memory Allocation has failed");
	i = 0;
	while (i < game->rows)
	{
		game->maptwo[i] = ft_strdup(game->mapdup[i]);
		if (game->maptwo[i] == NULL)
			ft_error_message("A Memory Allocation has failed");
		i++;
	}
	game->maptwo[i] = NULL;
}

void	dup_map_v(t_data *game, int erows, int ecols)
{
	int	sign[2];

	if (game->mapdup[erows + 1][ecols] == '0')
	{
		game->mapdup[erows][ecols] = '0';
		game->mapdup[erows + 1][ecols] = 'V';
		sign[0] = 1;
		craft_map1(game);
	}
	if (sign[0] == 1)
		game->mapdup[erows + 1][ecols] = '0';
	if (game->mapdup[erows - 1][ecols] == '0')
	{
		game->mapdup[erows - 1][ecols] = 'V';
		game->mapdup[erows][ecols] = '0';
		sign[1] = 1;
		craft_map2(game);
	}
	game->mapdup[erows][ecols] = 'V';
	if (sign[1] == 1)
		game->mapdup[erows][ecols - 1] = '0';
}

void	dup_map_h(t_data *game, int erows, int ecols)
{
	int	sign[2];

	if (game->mapdup[erows][ecols + 1] == '0')
	{
		game->mapdup[erows][ecols] = '0';
		game->mapdup[erows][ecols + 1] = 'H';
		sign[0] = 1;
		craft_map1(game);
	}
	if (sign[0] == 1)
		game->mapdup[erows][ecols + 1] = '0';
	if (game->mapdup[erows][ecols - 1] == '0')
	{
		game->mapdup[erows][ecols - 1] = 'H';
		game->mapdup[erows][ecols] = '0';
		sign[1] = 1;
		craft_map2(game);
	}
	game->mapdup[erows][ecols] = 'H';
	if (sign[1] == 1)
		game->mapdup[erows][ecols - 1] = '0';
}

void	dup_map(t_data *game, int erows, int ecols)
{
	if (game->mapdup[erows][ecols] == 'H')
		dup_map_h(game, erows, ecols);
	else if (game->mapdup[erows][ecols] == 'V')
		dup_map_v(game, erows, ecols);
}
