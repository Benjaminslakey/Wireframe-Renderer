/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 15:56:15 by bslakey           #+#    #+#             */
/*   Updated: 2017/02/15 07:10:13 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libgfx.h"

t_point				*create_point(int x, int y, int z)
{
	t_point			*point;

	point = (t_point*)malloc(sizeof(t_point));
	point->x = (float)(x);
	point->y = (float)(y);
	point->z = (float)(z);
	point->w = 1;
	return (point);
}

t_point				***create_empty_ptable(int width, int height)
{
	int				i;
	t_point			***empty_table;

	i = -1;
	empty_table = (t_point***)malloc(sizeof(t_point**) * height);
	while (++i < height)
		empty_table[i] = (t_point**)malloc(sizeof(t_point*) * width);
	return (empty_table);
}
