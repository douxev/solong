/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_main_textures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:13:54 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/01/12 18:08:38 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	bzero_img(t_mlx *mlx)
{
	mlx->bg.img = NULL;
	mlx->end.img = NULL;
	mlx->start.img = NULL;
	mlx->tex.vwall.img = NULL;
	mlx->tex.wall.img = NULL;
	mlx->tex.empty.img = NULL;
	mlx->tex.lose_msg.img = NULL;
	mlx->tex.start1.img = NULL;
	mlx->tex.start2.img = NULL;
	mlx->tex.bath = NULL;
	mlx->tex.coins = NULL;
	mlx->tex.exit = NULL;
	mlx->tex.p1 = NULL;
	mlx->tex.pnj1 = NULL;
	mlx->tex.pnj2 = NULL;
	mlx->tex.pnj3 = NULL;
	mlx->tex.money = NULL;
	mlx->tex.love = NULL;
	mlx->win = NULL;
	mlx->ptr = NULL;
}

void	bzero_mlx(t_mlx *mlx)
{
	mlx->event = -100;
	bzero_img(mlx);
	mlx->mv = 0;
	mlx->px = 0;
	mlx->py = 0;
	mlx->coins = 1;
	mlx->time.money = 0;
	mlx->time.start = 0;
}

static void	init_all(t_mlx *mlx)
{
	init_player(mlx);
	init_pnj1(mlx);
	init_pnj2(mlx);
	init_pnj3(mlx);
	init_coins(mlx);
	init_exit(mlx);
	init_money(mlx);
}

void	load_textures(t_mlx *mlx)
{
	check_map(mlx);
	mlx->bg.img = mlx_new_image(mlx->ptr, mlx->width, mlx->height);
	if (!mlx->bg.img)
		print_error("Image not properly created", mlx);
	mlx->bg.addr = mlx_get_data_addr(mlx->bg.img, \
	&(mlx->bg.bit_pix), &(mlx->bg.size_line), &(mlx->bg.endian));
	mlx->bg.w = mlx->width;
	mlx->bg.h = mlx->height;
	spwn_image(mlx, &(mlx->tex.wall), WALL);
	spwn_image(mlx, &(mlx->tex.empty), EMPTY);
	spwn_image(mlx, &(mlx->tex.vwall), VWALL);
	init_all(mlx);
	mlx->win = mlx_new_window(mlx->ptr, mlx->width, mlx->height, \
								PRG_NAME);
	if (!mlx->win)
		print_error("Window couldn't be created.", mlx);
	if (mlx->event == -100)
		start_scene(mlx);
	else
	{
		mlx->event = 0;
		refresh(mlx);
	}
}
