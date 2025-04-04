/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepennar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:46:20 by fepennar          #+#    #+#             */
/*   Updated: 2025/02/24 12:46:24 by fepennar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*SIDE NOTE
  0 = FREE_SPACE
  1 = WALLS
  H & V = ENEMIES (horizontal or vertical movement)
  C = COLLECTIBLES
  P = You wouldn't guess!!
  E = EXIT*/

void	border_check(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->rows)
	{
		j = 0;
		while (j < game->cols)
		{
			if (i == 0 || i == (game->rows - 1))
				if (game->map[i][j] != '1')
					ft_error_message("The map wasn't closed properly", game);
			if (j == 0 || j == (game->cols - 1))
				if (game->map[i][j] != '1')
					ft_error_message("The map wasn't closed properly", game);
			j++;
		}
		i++;
	}
}

void	rows_check(t_data *game)
{
	int	i;

	i = 0;
	while (i < game->cols)
	{
		if (game->map[game->rows - 1][i] != '1')
			ft_error_message("Invalid map", game);
		i++;
	}
	if (game->map[game->rows - 1][i] != '\0' && \
		game->map[game->rows - 1][i] != '\n')
		ft_error_message("Invalid map.", game);
}

void	is_rectangular(t_data *game)
{
	int	i;

	i = 0;
	while (i < game->rows - 1)
	{
		if ((int) ft_strlen(game->map[i]) - 1 != game->cols)
			ft_error_message("The map isn't rectangular", game);
		i++;
	}
	if (game->cols == game->rows)
		ft_error_message("This map is a square", game);
	if (game->cols < 3 || game->rows < 3)
		ft_error_message("This map isn't a map LOL", game);
}

void	update_elements(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->rows)
	{
		j = -1;
		while (++j < game->cols)
		{
			if (game->map[i][j] == 'P')
			{
				game->player++;
				game->player_pos.row = i;
				game->player_pos.col = j;
			}
			else if (game->map[i][j] == 'C')
				game->coins++;
			else if (game->map[i][j] == 'E')
				game->exit++;
			else if (game->map[i][j] != '1' && game->map[i][j] != '0'
				&& game->map[i][j] != 'V' && game->map[i][j] != 'H')
				ft_error_message("Unrecognized element was found", game);
		}
		i++;
	}
}

void	check_map(t_data *game)
{
	border_check(game);
	rows_check(game);
	is_rectangular(game);
	update_elements(game);
	find_enemy(game);
	if (game->exit != 1 || game->coins < 1
		|| game->player != 1 || game->enemy > 1)
	{
		free_maps(game);
		ft_error_message("Invalid map.", game);
	}
}
