/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepennar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:54:46 by fepennar          #+#    #+#             */
/*   Updated: 2025/02/26 17:54:50 by fepennar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*ADVICE
  Following the course of this project from this code is hard since you have to
  understand where the functions are and stuff, for this i suggest to go to the
  URL and replace the .com, with .dev, it will open this same code
  with a VScode extension so you can see how the code's tied with itself!*/
void	ft_error_message(char *message, t_data *game)
{
	ft_printf("ERROR: %s\n", message);
	if (game->map)
		free_maps(game);
	if (game->maptwo)
		free_maps2(game);
	if (game->mapthree)
		free_maps3(game);
	exit(1);
}

void	open_window(t_data *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_error_message("inizialization failed try again", game);
	game->win = mlx_new_window(game->mlx,
			game->cols * 64,
			game->rows * 64,
			"so_long");
	convert_image(game);
	item_to_window(game);
}

int	main(int ac, char **av)
{
	t_data	game;

	init_game(&game);
	if (ac != 2)
		ft_error_message("Only 2 arguments are needed", &game);
	if (!ft_strnstr(av[1] + ft_strlen(av[1]) - 4, ".ber", 4))
		ft_error_message("The map file must be a .ber file !!", &game);
	create_map(&game, av[1]);
	check_map(&game);
	flood_prep(&game);
	open_window(&game);
	mlx_loop_hook(game.mlx, my_loop, &game);
	mlx_hook(game.win, 2, 1L << 0, move_hook, &game);
	mlx_hook(game.win, 17, 0L, power_off, &game);
	mlx_loop(game.mlx);
	exit(0);
}
