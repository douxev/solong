/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:35:04 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/01/12 15:42:19 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft_int.h"

void	ft_ptr(void *ptr, size_t *z)
{
	if (!ptr)
	{
		write(1, "(nil)", 5);
		(*z) += 5;
		return ;
	}
	write(1, "0x", 2);
	(*z) += 2;
	ft_nbaseu((size_t) ptr, "0123456789abcdef", z);
}