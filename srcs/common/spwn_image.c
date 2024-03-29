/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spwn_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:49:44 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/01/12 17:49:15 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

t_img	*malloc_sprite(void)
{
	t_img	*f1;
	t_img	*f2;
	t_img	*f3;
	t_img	*f4;

	f1 = malloc (sizeof (t_img));
	if (!f1)
		return (NULL);
	f1->n = NULL;
	f2 = malloc(sizeof(t_img));
	if (!f2)
		return (free(f1), NULL);
	f1->n = f2;
	f2->n = NULL;
	f3 = malloc(sizeof(t_img));
	if (!f3)
		return (free(f1), free(f2), NULL);
	f2->n = f3;
	f3->n = NULL;
	f4 = malloc(sizeof(t_img));
	if (!f4)
		return (free(f1), free(f2), free(f3), NULL);
	f3->n = f4;
	f4->n = f1;
	return (f1);
}

void	spwn_image(t_mlx *mlx, t_img *f, char *path)
{
	f->img = mlx_xpm_file_to_image(mlx->ptr, path, &(f->w), &(f->h));
	if (!f->img)
		print_error("Image not properly created", mlx);
	f->addr = mlx_get_data_addr(f->img, \
	&(f->bit_pix), &(f->size_line), &(f->endian));
}
