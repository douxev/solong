/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transparency.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 21:12:02 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/01/12 17:49:22 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static unsigned int	get_pixel(t_img img, int x, int y)
{
	return (*(unsigned int *)(\
	(img.addr + (y * img.size_line) + (x * img.bit_pix / 8))));
}

// copie le pixel sur l'image, en skippant les transparents
static void	put_pixel(t_img img, int x, int y, int color)
{
	char	*dst;

	if (color == (int)0xFF000000)
		return ;
	if (x >= 0 && y >= 0 && x < img.w && y < img.h)
	{
		dst = img.addr + (y * img.size_line + x * (img.bit_pix / 8));
		*(unsigned int *)dst = color;
	}
}

// copie une image sur une autre
void	ft_itoi(t_img dst, t_img src, int x, int y)
{
	int	j;
	int	i;

	i = 0;
	while (i < src.w)
	{
		j = 0;
		while (j < src.h)
		{
			put_pixel(dst, x + i, y + j, get_pixel(src, i, j));
			j++;
		}
		i++;
	}
}
