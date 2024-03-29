/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:10:01 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/01/12 18:51:25 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static char	*process_file(t_mlx *mlx, char *path)
{
	int	len;

	len = ft_strlen(path) - 1;
	if ((len <= 3 || !(path[len] == 'r' && path[len - 1] == 'e' \
			&& path[len - 2] == 'b' && path[len - 3] == '.')))
		print_error("File extension incorrect.", mlx);
	return (path);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	char	*path;

	bzero_mlx(&mlx);
	mlx.time.anims = gettime();
	mlx.time.nmy = gettime();
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
	mlx_hook(mlx.win, KeyPress, KeyPressMask, &on_pressed, &mlx);
	mlx_hook(mlx.win, DestroyNotify, StructureNotifyMask, &on_destroy, &mlx);
	mlx_loop_hook(mlx.ptr, &update, &mlx);
	mlx_loop(mlx.ptr);
	return (0);
}
