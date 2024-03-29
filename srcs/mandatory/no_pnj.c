/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_pnj.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 20:11:07 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/01/12 18:47:11 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	no_ennemies(t_mlx *mlx, int x, int y)
{
	(void) x;
	(void) y;
	print_error("No ennemies allowed in mandatory part.", mlx);
}

void	ft_draw_pnj1(t_mlx *mlx, int x, int y)
{
	no_ennemies(mlx, x, y);
}

void	ft_draw_pnj2(t_mlx *mlx, int x, int y)
{
	no_ennemies(mlx, x, y);
}

void	ft_draw_pnj3(t_mlx *mlx, int x, int y)
{
	no_ennemies(mlx, x, y);
}
