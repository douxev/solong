/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 22:00:37 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/01/12 19:15:02 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	game_over(t_mlx *mlx, int lost)
{
	if (lost == 1)
		lose_scene(mlx);
	else
		win_scene(mlx);
}

void	got_money(t_mlx *mlx, int x, int y)
{
	mlx->mv++;
	mlx->map[y][x] = 'P';
	refresh(mlx);
}
