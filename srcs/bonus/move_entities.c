/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_entities.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 20:08:54 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/01/12 17:49:05 by jdoukhan         ###   ########.fr       */
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

static int	next_nmy_rand(int *x, int *y, size_t seed)
{
	srand(seed);
	if (rand() % 2 == 0)
	{
		if (rand() % 2 == 0)
			*x = 1;
		else
			*x = -1;
		*y = 0;
	}
	else
	{
		if (rand() % 2 == 0)
			*y = 1;
		else
			*y = -1;
		*x = 0;
	}
	return (1);
}

static void	move_to_nmy(t_mlx *mlx, int m, int n, char c)
{
	int		x;
	int		y;
	char	**map;

	map = mlx->map;
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			while (map[y][x] == c && (y + n < 0 || x + m < 0 || (!map[y + n] \
				|| !map[y + n][x + m]) || (map[y + n][x + m] != 'P' \
				&& map[y + n][x + m] != '0')))
				next_nmy_rand(&n, &m, gettime() % 3 + gettime());
			if (map[y][x] == c && map[y + n][x + m] != 'P')
			{
				map[y][x] = '0';
				map[y + n][x + m] = c;
				return ;
			}
			else if (map[y][x] == c && map[y + n][x + m] == 'P')
				game_over(mlx, 1);
		}
	}
}

void	move_nmy(t_mlx *mlx)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	mlx->time.nmy = gettime();
	next_nmy_rand(&x, &y, gettime() + gettime());
	move_to_nmy(mlx, x, y, 'X');
	next_nmy_rand(&x, &y, gettime());
	move_to_nmy(mlx, x, y, 'Y');
	next_nmy_rand(&x, &y, gettime() % 3 + gettime());
	move_to_nmy(mlx, x, y, 'Z');
}
