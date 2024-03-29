/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:27:22 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/01/12 17:48:42 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	key_is_up(t_mlx *mlx)
{
	move_to(mlx, mlx->map, 0, -1);
	return (0);
}

int	key_is_down(t_mlx *mlx)
{
	move_to(mlx, mlx->map, 0, 1);
	return (0);
}

int	key_is_left(t_mlx *mlx)
{
	move_to(mlx, mlx->map, -1, 0);
	return (0);
}

int	key_is_right(t_mlx *mlx)
{
	move_to(mlx, mlx->map, 1, 0);
	return (0);
}
