/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:20:56 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/01/12 18:54:47 by jdoukhan         ###   ########.fr       */
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
	if (mlx->time.money && !(gettime() - mlx->time.money >= MONEYTIME))
		ft_itoi(mlx->bg, *(mlx->tex.money), mlx->px - TILE, mlx->py - TILE);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->bg.img, 0, 0);
	print_hud(mlx);
}

int	animate(t_mlx *mlx)
{
	if (!mlx->event && mlx->coins == 0)
		mlx->event = ALLCOINS;
	mlx->time.anims = gettime();
	mlx->tex.p1 = mlx->tex.p1->n;
	mlx->tex.pnj1 = mlx->tex.pnj1->n;
	mlx->tex.pnj2 = mlx->tex.pnj2->n;
	mlx->tex.pnj3 = mlx->tex.pnj3->n;
	mlx->tex.coins = mlx->tex.coins->n;
	mlx->tex.money = mlx->tex.money->n;
	if (mlx->event >= ALLCOINS && mlx->event < DOOROPEN)
	{
		mlx->event++;
		mlx->tex.exit = mlx->tex.exit->n;
	}
	refresh(mlx);
	return (0);
}

int	update(t_mlx *mlx)
{
	if (mlx->event < -2 && gettime() - mlx->time.start >= START_TIME)
	{
		start_scene(mlx);
		return (0);
	}
	else if (mlx->event < -2)
		return (0);
	if (mlx->event == LOSEGAME || mlx->event == HAPPYEND)
	{
		if (mlx->event == LOSEGAME && gettime() - mlx->time.anims >= ANIM_SPEED)
			lose_refresh(mlx);
		if (mlx->event == HAPPYEND && gettime() - mlx->time.anims >= ANIM_SPEED)
			win_refresh(mlx);
		return (0);
	}
	if (gettime() - mlx->time.nmy >= NMY_SPEED)
		move_nmy(mlx);
	if (gettime() - mlx->time.anims >= ANIM_SPEED)
		animate(mlx);
	if (mlx->mv > 999)
		game_over(mlx, 1);
	return (0);
}
