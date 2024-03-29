/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lose_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:17:04 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/01/12 17:48:49 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	init_end(t_mlx *mlx)
{
	spwn_image(mlx, &mlx->tex.lose_msg, LOSESCREEN);
}

void	lose_refresh(t_mlx *mlx)
{
	mlx->time.anims = gettime();
	ft_itoi(mlx->end, mlx->tex.lose_msg, \
			mlx->width / 2 - 38, mlx->height / 2 - 20);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->end.img, 0, 0);
}

void	lose_scene(t_mlx *mlx)
{
	mlx->event = LOSEGAME;
	mlx->end.img = mlx_new_image(mlx->ptr, mlx->width, mlx->height);
	if (!mlx->end.img)
		print_error("Image not properly created", mlx);
	mlx->end.addr = mlx_get_data_addr(mlx->end.img, \
	&(mlx->end.bit_pix), &(mlx->end.size_line), &(mlx->end.endian));
	mlx->end.w = mlx->width;
	mlx->end.h = mlx->height;
	init_end(mlx);
	lose_refresh(mlx);
	ft_printf("You died out of Panic.\n");
}
