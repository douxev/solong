/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:27:25 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/01/12 17:49:12 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	init_pnj1(t_mlx *mlx)
{
	mlx->tex.pnj1 = malloc_sprite();
	if (!mlx->tex.pnj1)
		print_error("Image not properly created", mlx);
	spwn_image(mlx, mlx->tex.pnj1, PNJA1);
	spwn_image(mlx, mlx->tex.pnj1->n, PNJA2);
	spwn_image(mlx, mlx->tex.pnj1->n->n, PNJA3);
	spwn_image(mlx, mlx->tex.pnj1->n->n->n, PNJA4);
}

void	init_pnj2(t_mlx *mlx)
{
	mlx->tex.pnj2 = malloc_sprite();
	if (!mlx->tex.pnj2)
		print_error("Image not properly created", mlx);
	spwn_image(mlx, mlx->tex.pnj2, PNJB1);
	spwn_image(mlx, mlx->tex.pnj2->n, PNJB2);
	spwn_image(mlx, mlx->tex.pnj2->n->n, PNJB3);
	spwn_image(mlx, mlx->tex.pnj2->n->n->n, PNJB4);
}

void	init_pnj3(t_mlx *mlx)
{
	mlx->tex.pnj3 = malloc_sprite();
	if (!mlx->tex.pnj3)
		print_error("Image not properly created", mlx);
	spwn_image(mlx, mlx->tex.pnj3, PNJC1);
	spwn_image(mlx, mlx->tex.pnj3->n, PNJC2);
	spwn_image(mlx, mlx->tex.pnj3->n->n, PNJC3);
	spwn_image(mlx, mlx->tex.pnj3->n->n->n, PNJC4);
}

void	init_exit(t_mlx *mlx)
{
	mlx->tex.exit = malloc_sprite();
	if (!mlx->tex.exit)
		print_error("Image not properly created", mlx);
	spwn_image(mlx, mlx->tex.exit, EXIT1);
	spwn_image(mlx, mlx->tex.exit->n, EXIT2);
	spwn_image(mlx, mlx->tex.exit->n->n, EXIT3);
	spwn_image(mlx, mlx->tex.exit->n->n->n, EXIT4);
}

void	init_player(t_mlx *mlx)
{
	mlx->tex.p1 = malloc_sprite();
	if (!mlx->tex.p1)
		print_error("Image not properly created", mlx);
	spwn_image(mlx, mlx->tex.p1, PLAYER1);
	spwn_image(mlx, mlx->tex.p1->n, PLAYER2);
	spwn_image(mlx, mlx->tex.p1->n->n, PLAYER3);
	spwn_image(mlx, mlx->tex.p1->n->n->n, PLAYER4);
}
