/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 20:12:52 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/01/12 17:48:23 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_draw_player(t_mlx *mlx, int x, int y)
{
	ft_draw_empty(mlx, x, y);
	ft_itoi(mlx->bg, *(mlx->tex.p1), x * TILE + 16, y * TILE);
}

void	ft_draw_coins(t_mlx *mlx, int x, int y)
{
	mlx->coins++;
	ft_draw_empty(mlx, x, y);
	ft_itoi(mlx->bg, *(mlx->tex.coins), x * TILE + 16, y * TILE + 16);
}

void	ft_draw_emojis(t_mlx *mlx, int x, int y)
{
	ft_itoi(mlx->bg, *(mlx->tex.money), x * TILE + 16, y * TILE);
}
