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

void	ft_error_message(char *message)
{
	ft_printf("ERROR: %s\n", message);
	exit(1);
}

void	open_window(t_data *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_error_message("inizialization failed try again");
	game->win = mlx_new_window(game->mlx,
			game->cols * 64,
			game->rows * 64,
			"Quest For The Hexblunt");
	convert_image(game);
	item_to_window(game);
}

int	main(int ac, char **av)
{
	t_data	game;

	if (ac != 2)
		ft_error_message("Only 2 arguments are needed");
	if (!ft_strnstr(av[1], ".ber", ft_strlen(av[1])))
		ft_error_message("The map file must be a .ber file !!");
	init_game(&game);
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
