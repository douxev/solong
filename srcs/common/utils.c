/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:13:47 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/01/25 18:08:50 by jdoukhan         ###   ########.fr       */
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
	ft_printf("\033[1;93;41mError\n%s\033[0m \033[0K\n", str);
	on_destroy(mlx);
}

static void	ft_stat_bzero(void *s, size_t n)
{
	unsigned int	i;
	char			*zero;

	i = 0;
	zero = (char *) s;
	while (i < n)
		zero[i++] = 0;
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*tab;
	int		i;
	size_t	mult_size;

	i = 0;
	mult_size = nmemb * size;
	if (size && mult_size / size != nmemb)
		return (NULL);
	tab = malloc (mult_size);
	if (!tab)
		return (NULL);
	ft_stat_bzero((void *) tab, mult_size);
	return ((void *) tab);
}
