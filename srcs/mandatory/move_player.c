/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_entities.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 20:08:54 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/01/12 18:10:53 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	move_to(t_mlx *mlx, char **map, int m, int n)
{
	int	x;
	int	y;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x] && ((x == 0) || (x > 0 && map[y][x - 1] != 'P')))
		{
			if (map[y][x] == 'P' && y + n >= 0 && x + m >= 0
				&& map[y + n] && map[y + n][x + m])
			{
				if ((map[y + n][x + m] == '0' || map[y + n][x + m] == 'C'))
				{
					got_money(mlx, x + m, y + n);
					map[y][x] = '0';
					return (refresh(mlx));
				}
				else if (map[y + n][x + m] == 'E' && mlx->event == DOOROPEN)
					game_over(mlx, 0);
				else if (map[y + n][x + m] >= 'X' && map[y + n][x + m] <= 'Z')
					game_over(mlx, 1);
			}
		}
	}
}
