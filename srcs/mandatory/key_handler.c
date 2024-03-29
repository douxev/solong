/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:22:19 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/01/12 18:40:02 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	key_is_esc(t_mlx *mlx)
{
	on_destroy(mlx);
	return (0);
}

int	on_pressed(int keycode, t_mlx *mlx)
{
	if (keycode == ESC)
		key_is_esc(mlx);
	if (mlx->event < 0)
		return (0);
	refresh(mlx);
	ft_printf("\033c%i moves | %i coins left.\n", (mlx->mv), mlx->coins);
	if (keycode == UP || keycode == KEY_W)
		key_is_up(mlx);
	else if (keycode == LEFT || keycode == KEY_A)
		key_is_left(mlx);
	else if (keycode == RIGHT || keycode == KEY_D)
		key_is_right(mlx);
	else if (keycode == DOWN || keycode == KEY_S)
		key_is_down(mlx);
	return (0);
}
