/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:31:03 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/01/09 17:07:44 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_time
{
	clock_t	nmy;
	clock_t	anims;
	clock_t	nmy_anim;
	clock_t	money;
	clock_t	start;
}	t_time;

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_img
{
	void			*img;
	char			*addr;
	int				w;
	int				h;
	int				bit_pix;
	int				size_line;
	int				endian;
	struct s_img	*n;
}	t_img;

typedef struct s_tex
{
	t_img		wall;
	t_img		vwall;
	t_img		empty;
	t_img		lose_msg;
	t_img		start1;
	t_img		start2;
	t_img		*exit;
	t_img		*p1;
	t_img		*coins;
	t_img		*pnj1;
	t_img		*pnj2;
	t_img		*pnj3;
	t_img		*bath;
	t_img		*love;
	t_img		*money;
}	t_tex;

typedef struct s_count
{
	int	coins;
	int	exit;
	int	player;
	int	nmy;
}	t_count;

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
	int		height;
	int		width;
	char	**map;
	int		coins;
	int		mv;
	t_time	time;
	t_img	start;
	t_img	bg;
	t_img	end;
	t_tex	tex;
	int		event;
	int		px;
	int		py;
	int		nmy_nb;
	t_count	n;
}	t_mlx;

#endif
