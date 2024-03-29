/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:50:44 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/01/12 18:51:02 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	print_hud(t_mlx *mlx)
{
	char	moves[4];

	moves[2] = mlx->mv % 10 + 48;
	moves[1] = mlx->mv / 10 % 10 + 48;
	moves[0] = mlx->mv / 100 % 10 + 48;
	mlx_string_put(mlx->ptr, mlx->win, 16, 24, 0x286473, moves);
	mlx_string_put(mlx->ptr, mlx->win, 36, 24, 0x286473, "moves");
	ft_printf("\033c%i moves | %i coins left.\n", (mlx->mv), mlx->coins);
}
