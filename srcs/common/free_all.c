/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:42:07 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/01/26 12:27:08 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	destroy_map(char **map)
{
	int	i;

	i = 0;
	while (map && map[i])
		free(map[i++]);
	if (map)
		free(map);
}

static void	free_image(t_mlx *mlx, t_img *img)
{
	if (img && img->img)
		mlx_destroy_image(mlx->ptr, img->img);
	if (img)
		free(img);
}

void	kill_sprite(t_mlx *mlx, t_img *sprite)
{
	if (sprite && sprite->n && sprite->n->n && sprite->n->n->n)
		free_image(mlx, sprite->n->n->n);
	if (sprite && sprite->n && sprite->n->n)
		free_image(mlx, sprite->n->n);
	if (sprite && sprite->n)
		free_image(mlx, sprite->n);
	if (sprite)
		free_image(mlx, sprite);
}

static void	destroy_images(t_mlx *mlx)
{
	kill_all_sprites(mlx);
	if (mlx->bg.img)
		mlx_destroy_image(mlx->ptr, mlx->bg.img);
	if (mlx->start.img)
		mlx_destroy_image(mlx->ptr, mlx->start.img);
	if (mlx->tex.start1.img)
		mlx_destroy_image(mlx->ptr, mlx->tex.start1.img);
	if (mlx->tex.start2.img)
		mlx_destroy_image(mlx->ptr, mlx->tex.start2.img);
	if (mlx->tex.empty.img)
		mlx_destroy_image(mlx->ptr, mlx->tex.empty.img);
	if (mlx->tex.wall.img)
		mlx_destroy_image(mlx->ptr, mlx->tex.wall.img);
	if (mlx->tex.vwall.img)
		mlx_destroy_image(mlx->ptr, mlx->tex.vwall.img);
	if (mlx->tex.lose_msg.img)
		mlx_destroy_image(mlx->ptr, mlx->tex.lose_msg.img);
	if (mlx->end.img)
		mlx_destroy_image(mlx->ptr, mlx->end.img);
}

int	on_destroy(t_mlx *mlx)
{
	if (!mlx || !mlx->ptr)
		exit(0);
	destroy_images(mlx);
	if (mlx->win)
		mlx_destroy_window(mlx->ptr, mlx->win);
	mlx_destroy_display(mlx->ptr);
	if (mlx->ptr)
		free(mlx->ptr);
	destroy_map(mlx->map);
	mlx->map = NULL;
	exit(0);
}
