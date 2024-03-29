/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_emoji_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:57:40 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/01/12 17:49:08 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	init_money(t_mlx *mlx)
{
	mlx->tex.money = malloc_sprite();
	if (!mlx->tex.money)
		on_destroy(mlx);
	spwn_image(mlx, mlx->tex.money, MONEY1);
	spwn_image(mlx, mlx->tex.money->n, MONEY2);
	spwn_image(mlx, mlx->tex.money->n->n, MONEY1);
	spwn_image(mlx, mlx->tex.money->n->n->n, MONEY2);
}

void	init_love(t_mlx *mlx)
{
	mlx->tex.love = malloc_sprite();
	if (!mlx->tex.love)
		on_destroy(mlx);
	spwn_image(mlx, mlx->tex.love, LOVE1);
	spwn_image(mlx, mlx->tex.love->n, LOVE2);
	spwn_image(mlx, mlx->tex.love->n->n, LOVE2);
	spwn_image(mlx, mlx->tex.love->n->n->n, LOVE2);
}

void	init_coins(t_mlx *mlx)
{
	mlx->tex.coins = malloc_sprite();
	if (!mlx->tex.coins)
		on_destroy(mlx);
	spwn_image(mlx, mlx->tex.coins, COIN1);
	spwn_image(mlx, mlx->tex.coins->n, COIN2);
	spwn_image(mlx, mlx->tex.coins->n->n, COIN3);
	spwn_image(mlx, mlx->tex.coins->n->n->n, COIN4);
}
