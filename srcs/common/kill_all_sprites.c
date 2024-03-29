/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_all_sprites.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:22:30 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/01/26 12:23:02 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	kill_all_sprites(t_mlx *mlx)
{
	kill_sprite(mlx, mlx->tex.p1);
	kill_sprite(mlx, mlx->tex.pnj1);
	kill_sprite(mlx, mlx->tex.pnj2);
	kill_sprite(mlx, mlx->tex.pnj3);
	kill_sprite(mlx, mlx->tex.coins);
	kill_sprite(mlx, mlx->tex.exit);
	kill_sprite(mlx, mlx->tex.bath);
	kill_sprite(mlx, mlx->tex.love);
	kill_sprite(mlx, mlx->tex.money);
}
