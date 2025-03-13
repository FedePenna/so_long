/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepennar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:44:27 by fepennar          #+#    #+#             */
/*   Updated: 2025/02/20 14:00:45 by fepennar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../mlx_linux/mlx.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

enum e_thewasd
{
	W = 119,
	A = 97,
	S = 115,
	D = 100,
	ESC = 65307
};

enum e_directions
{
	FRONT,
	BACK,
	LEFT,
	RIGHT
};

typedef struct s_txtrs
{
	void	*ground;
	void	*coins;
	void	*wall;
	void	*player;
	void	*player_left;
	void	*player_right;
	void	*player_down;
	void	*exit;
	void	*enemy;
}	t_textures;

typedef struct s_player
{
	int						row;
	int						col;
	enum e_directions		directions;
}	t_player;

typedef struct s_enemy
{
	int						row;
	int						col;
	enum e_directions		e_dir;
}	t_enemy;

typedef struct s_gamedata
{
	void		*mlx;
	void		*win;
	int			height;
	int			lenght;
	char		**map;
	char		**mapdup;
	char		**maptwo;
	char		**mapthree;
	int			rows;
	int			cols;
	t_player	player_pos;
	t_enemy		enemy_pos;
	int			player;
	int			enemy;
	int			coins;
	int			exit;
	int			moves;
	int			score;
	int			frames;
	t_textures	textures;
}	t_data;

void		ft_error_message(char *message);
void		init_game(t_data *game);
void		create_map(t_data *game, char *mappath);
void		check_map(t_data *game);
void		flood_prep(t_data *game);
void		put_image(t_data *game);
void		open_window(t_data *game);
void		free_textures(t_data *game);
void		free_maps(t_data *game);
void		convert_image(t_data *game);
void		item_to_window(t_data *game);
void		move_check(int keycode, t_data *game);
void		print_ground(t_data *game, int i, int index);
void		print_player(t_data *game, int i, int index);
void		print_coin(t_data *game, int i, int index);
void		print_exit(t_data *game, int i, int index);
void		print_enemy(t_data *game, int i, int index);
void		print_wall(t_data *game, int i, int index);
void		dup_map(t_data *game, int erows, int ecols);
void		find_enemy(t_data *game);
int			check_enemy_moves(t_data *game, int rows, int cols);
int			my_loop(t_data *game);
int			move_hook(int keycode, t_data *game);
int			power_off(t_data *game);
#endif