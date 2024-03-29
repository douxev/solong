/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:13:47 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/01/12 17:49:26 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	print_map(t_mlx *mlx)
{
	int		i;

	i = 0;
	ft_printf("\n");
	while (mlx->map[i])
		ft_printf("%s", mlx->map[i++]);
	ft_printf("\n");
}

void	print_error(char *str, t_mlx *mlx)
{
	ft_printf("\033c\033[1;93;41mError\n%s\033[0m \033[0K\n", str);
	on_destroy(mlx);
}
