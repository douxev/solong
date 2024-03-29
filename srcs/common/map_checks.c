/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:35:09 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/01/12 19:14:14 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static int	re_flood(char **map, int x, int y)
{
	if (map[x][y] == 'E')
		map[x][y] = 'e';
	if (map[x][y] != '0' && map[x][y] != 'C' && map[x][y] != 'X'
		&& map[x][y] != 'P')
		return (-1);
	if (map[x][y] == '0')
		map[x][y] = '2';
	if (map[x][y] == 'C' || map[x][y] == 'X')
		map[x][y] += 32;
	if (x > 1 && map[x - 1] && (map[x - 1][y] == '0' || map[x - 1][y] == 'X' \
	|| map[x - 1][y] == 'C' || map[x - 1][y] == 'E'))
		re_flood(map, x - 1, y);
	if (map[x + 1] && (map[x + 1][y] == '0'
		|| map[x + 1][y] == 'X' || map[x + 1][y] == 'C'
		|| map[x + 1][y] == 'E'))
		re_flood(map, x + 1, y);
	if (x > 0 && map[x][y - 1] && map[x][y - 1]
		&& (map[x][y - 1] == '0' || map[x][y - 1] == 'X'
			|| map[x][y - 1] == 'C' || map[x][y - 1] == 'E'))
		re_flood(map, x, y - 1);
	if (map[x] && map[x][y + 1] && (map[x][y + 1] == '0'
		|| map[x][y + 1] == 'X' || map[x][y + 1] == 'C'
		|| map[x][y + 1] == 'E'))
		re_flood(map, x, y + 1);
	return (0);
}

static void	put_back_map(t_mlx *mlx, char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'C')
				print_error("At leat one coin is unreachable.", mlx);
			else if (map[i][j] == '2')
				map[i][j] = '0';
			else if (map[i][j] == 'p' || map[i][j] == 'e' || map[i][j] == 'c')
				map[i][j] -= 32;
			else if (map[i][j] == 'x' && mlx->n.nmy == 3 && mlx->n.nmy--)
				map[i][j] = 'X';
			else if (map[i][j] == 'x' && mlx->n.nmy == 2 && mlx->n.nmy--)
				map[i][j] = 'Y';
			else if (map[i][j] == 'x' && mlx->n.nmy == 1 && mlx->n.nmy--)
				map[i][j] = 'Z';
			else if (map[i][j] == 'E')
				print_error("The exit is unreachable.", mlx);
		}
	}
}

static void	flood_fill(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (mlx->map[i])
	{
		j = 0;
		while (mlx->map[i][j] && mlx->map[i][j] != 'P')
			j++;
		if (mlx->map[i][j] && mlx->map[i][j] == 'P')
			break ;
		i++;
	}
	check_border(mlx);
	re_flood(mlx->map, i, j);
	put_back_map(mlx, mlx->map);
}

static void	item_occurrence(t_mlx *mlx, char **map)
{
	int	i;
	int	j;

	j = -1;
	mlx->n.player = 0;
	mlx->n.nmy = 0;
	mlx->n.exit = 0;
	mlx->n.coins = 0;
	while (map[++j])
	{
		i = -1;
		while (map[j][++i])
		{
			if (map[j][i] == 'C')
				mlx->n.coins++;
			else if (map[j][i] == 'E')
				mlx->n.exit++;
			else if (map[j][i] == 'P')
				mlx->n.player++;
			else if (map[j][i] == 'X' || map[j][i] == 'Y' || map[j][i] == 'Z')
				mlx->n.nmy++;
			else if (map[j][i] != '1' && map[j][i] != '0' && map[j][i] != '\n')
				print_error("Items not recognized.", mlx);
		}
	}
}

void	check_map(t_mlx *mlx)
{
	item_occurrence(mlx, mlx->map);
	flood_fill(mlx);
	if (mlx->n.exit != 1 || mlx->n.player != 1 || mlx->n.nmy > 3)
		print_error("Too many items.", mlx);
}
