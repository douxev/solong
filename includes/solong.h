/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:44:46 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/01/12 18:55:35 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <time.h>
# include "sprites.h"
# include "structs.h"
# include "solong_bonus.h"
# include "solong_defines.h"
# include "minilibft.h"
# include "mlx.h"


# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# include <X11/X.h>
# include <X11/keysym.h>
# include <X11/Xlib.h>

void	start_scene(t_mlx *mlx);
void	refresh(t_mlx *mlx);
int		update(t_mlx *mlx);
void	win_refresh(t_mlx *mlx);
void	win_scene(t_mlx *mlx);
void	lose_scene(t_mlx *mlx);
void	lose_refresh(t_mlx *mlx);
void	game_over(t_mlx *mlx, int lost);

void	check_map(t_mlx *mlx);
void	print_map(t_mlx *mlx);
void	check_border(t_mlx *mlx);
void	is_map_too_big(t_mlx *mlx);
void	print_error(char *str, t_mlx *mlx);

void	ft_map(t_mlx *mlx, char **map, int i, int j);
void	ft_draw_surroundings(t_mlx *mlx, char **map);
void	print_hud(t_mlx *mlx);


int		on_pressed(int keycode, t_mlx *mlx);
int		key_is_up(t_mlx *mlx);
int		key_is_down(t_mlx *mlx);
int		key_is_left(t_mlx *mlx);
int		key_is_right(t_mlx *mlx);

void	got_money(t_mlx *mlx, int x, int y);
void	move_to(t_mlx *mlx, char **map, int m, int n);
void	move_nmy(t_mlx *mlx);

t_img	*malloc_sprite(void);
void	spwn_image(t_mlx *mlx, t_img *f, char *path);
void	bzero_mlx(t_mlx *mlx);
void	load_textures(t_mlx *mlx);
int		on_destroy(t_mlx *mlx);

void	init_map(t_mlx *mlx, const char *file);
void	init_love(t_mlx *mlx);
void	init_money(t_mlx *mlx);
void	init_player(t_mlx *mlx);
void	init_pnj1(t_mlx *mlx);
void	init_pnj2(t_mlx *mlx);
void	init_pnj3(t_mlx *mlx);
void	init_coins(t_mlx *mlx);
void	init_exit(t_mlx *mlx);

void	ft_itoi(t_img dst, t_img src, int x, int y);
void	ft_draw_wall(t_mlx *mlx, int x, int y);
void	ft_draw_vwall(t_mlx *mlx, int x, int y);
void	ft_draw_rvwall(t_mlx *mlx, int x, int y);
void	ft_draw_empty(t_mlx *mlx, int x, int y);
void	ft_draw_exit(t_mlx *mlx, int x, int y);
void	ft_draw_player(t_mlx *mlx, int x, int y);
void	ft_draw_coins(t_mlx *mlx, int x, int y);
void	ft_draw_pnj1(t_mlx *mlx, int x, int y);
void	ft_draw_pnj2(t_mlx *mlx, int x, int y);
void	ft_draw_pnj3(t_mlx *mlx, int x, int y);

#endif