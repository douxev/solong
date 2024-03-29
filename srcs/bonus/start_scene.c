/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:10:10 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/01/12 17:49:19 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	second_scene(t_mlx *mlx)
{
	mlx->event = -4;
	mlx->time.start = gettime();
	spwn_image(mlx, &mlx->tex.start2, STARTMSG2);
	ft_itoi(mlx->start, mlx->tex.start2, \
		mlx->width / 2 - 38, mlx->height / 2 - 20);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->start.img, 0, 0);
}

void	start_scene(t_mlx *mlx)
{
	if (mlx->event == -3)
	{
		second_scene(mlx);
		return ;
	}
	else if (mlx->event == -4)
	{
		mlx->event = 0;
		mlx_clear_window(mlx->ptr, mlx->win);
		return ;
	}
	mlx->event = -3;
	mlx->time.start = gettime();
	spwn_image(mlx, &mlx->tex.start1, STARTMSG1);
	mlx->start.img = mlx_new_image(mlx->ptr, mlx->width, mlx->height);
	if (!mlx->start.img)
		print_error("Image not properly created", mlx);
	mlx->start.addr = mlx_get_data_addr(mlx->start.img, \
	&(mlx->start.bit_pix), &(mlx->start.size_line), &(mlx->start.endian));
	mlx->start.w = mlx->width;
	mlx->start.h = mlx->height;
	ft_itoi(mlx->start, mlx->tex.start1, \
			mlx->width / 2 - 38, mlx->height / 2 - 20);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->start.img, 0, 0);
}
