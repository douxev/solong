/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pnj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 20:11:07 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/01/12 17:48:26 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_draw_pnj1(t_mlx *mlx, int x, int y)
{
	ft_draw_empty(mlx, x, y);
	ft_itoi(mlx->bg, *(mlx->tex.pnj1), x * TILE + 16, y * TILE);
	mlx->nmy_nb++;
}

void	ft_draw_pnj2(t_mlx *mlx, int x, int y)
{
	ft_draw_empty(mlx, x, y);
	ft_itoi(mlx->bg, *(mlx->tex.pnj2), x * TILE + 16, y * TILE);
	mlx->nmy_nb++;
}

void	ft_draw_pnj3(t_mlx *mlx, int x, int y)
{
	ft_draw_empty(mlx, x, y);
	ft_itoi(mlx->bg, *(mlx->tex.pnj3), x * TILE + 16, y * TILE);
	mlx->nmy_nb++;
}
