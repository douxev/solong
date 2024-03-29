/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_borders.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:23:34 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/01/12 17:48:53 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	is_map_too_big(t_mlx *mlx)
{
	if (mlx->height > 1080 || mlx->width > 1920)
		print_error("Map is too big for the screen.", mlx);
}

void	check_border(t_mlx *mlx)
{
	int	k;
	int	imax;
	int	jmax;

	k = 0;
	imax = mlx->width / TILE - 1;
	jmax = mlx->height / TILE - 3;
	is_map_too_big(mlx);
	while (mlx->map[0] && mlx->map[jmax] && mlx->map[0][k] && mlx->map[jmax][k])
	{
		if ((mlx->map[0][k] && mlx->map[jmax] && mlx->map[jmax][k]
			&& (mlx->map[0][k] != '1' || mlx->map[jmax][k] != '1')))
			print_error("Map has incorrect borders.", mlx);
		k++;
	}
	k = 0;
	while (mlx->map[0] && mlx->map[k] && mlx->map[k][0] && mlx->map[k][imax])
	{
		if ((mlx->map[k][0] && mlx->map[k][imax]
			&& (mlx->map[k][0] != '1' || mlx->map[k][imax] != '1')))
			print_error("Map has incorrect borders.", mlx);
		k++;
	}
	mlx->width -= 2 * TILE;
	mlx->height -= 2 * TILE;
}
