/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:10:01 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/01/12 18:54:32 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	refresh(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	mlx->coins = 0;
	mlx->nmy_nb = 0;
	ft_map(mlx, mlx->map, i, j);
	ft_draw_surroundings(mlx, mlx->map);
	if (mlx->event == 0 && mlx->coins == 0)
	{
		mlx->event = DOOROPEN;
		mlx->tex.exit = mlx->tex.exit->n->n->n;
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->bg.img, 0, 0);
}

static char	*process_file(t_mlx *mlx, char *path)
{
	int	len;

	len = ft_strlen(path) - 1;
	if ((len <= 3 || !(path[len] == 'r' && path[len - 1] == 'e'
				&& path[len - 2] == 'b' && path[len - 3] == '.')))
		print_error("File extension incorrect.", mlx);
	return (path);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	char	*path;

	bzero_mlx(&mlx);
	mlx.event = 0;
	if (argc != 2)
		return (print_error("No map given.", &mlx), 0);
	path = process_file(&mlx, argv[1]);
	mlx.ptr = mlx_init();
	if (!mlx.ptr)
		return (1);
	mlx.map = NULL;
	init_map(&mlx, path);
	if (!mlx.win)
		return (free(mlx.ptr), 1);
	ft_printf("\033c%i moves | %i coins left.\n", (mlx.mv), mlx.coins);
	mlx_hook(mlx.win, KeyPress, KeyPressMask, &on_pressed, &mlx);
	mlx_hook(mlx.win, DestroyNotify, StructureNotifyMask, &on_destroy, &mlx);
	mlx_loop(mlx.ptr);
	return (0);
}
