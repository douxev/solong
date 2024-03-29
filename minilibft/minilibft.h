/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibft.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:27:13 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/01/12 15:46:08 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIBFT_H
# define MINILIBFT_H
# include <stdio.h>

int		ft_printf(const char *str, ...);
char	*get_next_line(int fd);
size_t	ft_strlen(char *str);

#endif