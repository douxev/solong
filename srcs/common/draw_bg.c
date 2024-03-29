/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 20:11:49 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/01/12 17:48:19 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_draw_rvwall(t_mlx *mlx, int x, int y)
{
	ft_itoi(mlx->bg, mlx->tex.vwall, x * TILE - 50, y * TILE);
}

void	ft_draw_vwall(t_mlx *mlx, int x, int y)
{
	ft_itoi(mlx->bg, mlx->tex.vwall, x * TILE, y * TILE);
}

void	ft_draw_wall(t_mlx *mlx, int x, int y)
{
	ft_itoi(mlx->bg, mlx->tex.wall, x * TILE, y * TILE);
}

void	ft_draw_empty(t_mlx *mlx, int x, int y)
{
	ft_itoi(mlx->bg, mlx->tex.empty, x * TILE, y * TILE);
}

void	ft_draw_exit(t_mlx *mlx, int x, int y)
{
	ft_itoi(mlx->bg, *(mlx->tex.exit), x * TILE, y * TILE);
}
