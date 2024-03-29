/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:05:52 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/01/12 18:39:51 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	init_end(t_mlx *mlx)
{
	mlx->tex.bath = malloc_sprite();
	if (!mlx->tex.bath)
		on_destroy(mlx);
	spwn_image(mlx, mlx->tex.bath, BATH1);
	spwn_image(mlx, mlx->tex.bath->n, BATH2);
	spwn_image(mlx, mlx->tex.bath->n->n, BATH3);
	spwn_image(mlx, mlx->tex.bath->n->n->n, BATH4);
}

void	win_scene(t_mlx *mlx)
{
	mlx->event = HAPPYEND;
	mlx->end.img = mlx_new_image(mlx->ptr, mlx->width, mlx->height);
	if (!mlx->end.img)
		on_destroy(mlx);
	mlx->end.addr = mlx_get_data_addr(mlx->end.img, \
	&(mlx->end.bit_pix), &(mlx->end.size_line), &(mlx->end.endian));
	mlx->end.w = mlx->width;
	mlx->end.h = mlx->height;
	init_end(mlx);
	init_love(mlx);
	ft_printf("YOU DID IT !\n");
	ft_itoi(mlx->end, *(mlx->tex.p1), mlx->width / 2 - 70, mlx->height / 2);
	ft_itoi(mlx->end, *(mlx->tex.love), \
			mlx->width / 2 - 50, mlx->height / 2 - 15);
	ft_itoi(mlx->end, *(mlx->tex.bath), \
			mlx->width / 2 - 24, mlx->height / 2 - 54);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->end.img, 0, 0);
}
