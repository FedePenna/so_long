/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loopnhook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepennar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:14:15 by fepennar          #+#    #+#             */
/*   Updated: 2025/03/04 17:14:20 by fepennar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_hook(int keycode, t_data *game)
{
	if (keycode == W || keycode == A || keycode == S || keycode == D)
		move_check(keycode, game);
	else if (keycode == ESC)
		power_off(game);
	return (0);
}

int	my_loop(t_data *game)
{
	game->frames++;
	usleep(40000);
	item_to_window(game);
	return (0);
}
