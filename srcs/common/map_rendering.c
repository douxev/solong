/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rendering.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:47:49 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/01/13 15:17:03 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_draw_surroundings(t_mlx *mlx, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i][j])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
			ft_draw_wall(mlx, j++, 0);
		i++;
		ft_draw_rvwall(mlx, 0, i);
		ft_draw_vwall(mlx, j - 3, i);
	}
	ft_draw_vwall(mlx, j - 3, 0);
	j = 0;
	while (map[i][j])
		ft_draw_wall(mlx, j++, i);
	ft_draw_rvwall(mlx, 0, i - 1);
	ft_draw_vwall(mlx, j - 3, i - 1);
	ft_draw_rvwall(mlx, 0, 0);
}

void	ft_map(t_mlx *mlx, char **map, int i, int j)
{
	while (map[++i] && map[i + 1])
	{
		j = 0;
		while (map[i][++j] && map[i][j + 1] && map[i][j + 1] != '\n')
		{
			if (map[i][j] == '0')
				ft_draw_empty(mlx, j - 1, i);
			else if (map[i][j] == '1')
				ft_draw_wall(mlx, j - 1, i);
			else if (map[i][j] == 'E')
				ft_draw_exit(mlx, j - 1, i);
			else if (map[i][j] == 'P')
				ft_draw_player(mlx, j - 1, i);
			else if (map[i][j] == 'C')
				ft_draw_coins(mlx, j - 1, i);
			else if (map[i][j] == 'X')
				ft_draw_pnj1(mlx, j - 1, i);
			else if (map[i][j] == 'Y')
				ft_draw_pnj2(mlx, j - 1, i);
			else if (map[i][j] == 'Z')
				ft_draw_pnj3(mlx, j - 1, i);
			else
				print_error("Map items unknown.", mlx);
		}
	}
}

static void	ft_len_map(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (mlx->map[i])
	{
		j = 0;
		while (mlx->map[i][j])
			j++;
		i++;
	}
	mlx->height = TILE * (i + 2);
	mlx->width = TILE * (j);
}

void	check_rectangular(t_mlx *mlx)
{
	int		i;
	size_t	len;

	len = ft_strlen(mlx->map[0]);
	i = 0;
	while (mlx->map[i])
	{
		if (mlx->map && mlx->map[i] && ft_strlen(mlx->map[i]) != len)
			print_error("Map is not rectangular.", mlx);
	}
}

void	init_map(t_mlx *mlx, const char *file)
{
	int		fd;
	int		k;
	char	**map;

	fd = open(file, O_RDONLY);
	if (fd <= 0)
		print_error("File couldn't be read.", mlx);
	k = 0;
	mlx->map = malloc(sizeof (char *) * 19);
	if (!mlx->map)
		print_error("Memory not allocated properly.", mlx);
	map = mlx->map;
	while (k < 1 || (k >= 1 && \
		ft_strlen(map[0]) == ft_strlen(map[k - 1]) && k < 18))
	{
		map[k] = get_next_line(fd);
		if (!map[k++] && !close(fd))
			print_error("Map incorrect.", mlx);
	}
	close(fd);
	if (map[k] < 0)
		print_error("Read Error.", mlx);
	map[k] = NULL;
	ft_len_map(mlx);
	load_textures(mlx);
}
