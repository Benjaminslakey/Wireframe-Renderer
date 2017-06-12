/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 23:58:37 by bslakey           #+#    #+#             */
/*   Updated: 2017/02/16 02:28:53 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libgfx.h"
#include <stdio.h>

void				find_zrange(t_view *v)
{
	int				i;
	int				j;
	float			min;
	float			max;

	i = -1;
	min = ((v->orig)[0][0])->z;
	max = ((v->orig)[0][0])->z;
	while (++i < v->pheight)
	{
		j = -1;
		while (++j < v->pwidth)
		{
			if (((v->orig)[i][j])->z < min)
				min = ((v->orig)[i][j])->z;
			if (((v->orig)[i][j])->z > max)
				max = ((v->orig)[i][j])->z;
		}
	}
	v->zmin = min;
	v->zmax = max;
}

void				set_scale(t_view *v)
{
	v->scale = (float)(v->win_size)[1] / (float)(v->pheight);
	if (v->pwidth > v->pheight && v->pwidth > v->zmax)
		v->scale = (float)(v->win_size)[0] / (float)(v->pwidth);
	else if (v->zmax > v->pheight && v->zmax > v->pwidth)
		v->scale = (float)(v->win_size)[0] / fabs((float)(v->zmax));
}

void				xy_offset(t_view *v)
{
	if (v->pheight > v->pwidth && v->pheight > v->zmax)
		v->y_offset = (float)(v->pheight);
	else if (v->pwidth > v->pheight && v->pwidth > v->zmax)
		v->x_offset = (float)(v->pwidth);
	else if (v->zmax > v->pheight && v->zmax > v->pwidth)
		v->y_offset = (float)(v->zmax);
}

t_view				*init_view(char *name, t_point ***ptable, int dim[2])
{
	t_view			*v;


	MEM_GUARD((ptable));
	MEM_GUARD((v = (t_view*)malloc(sizeof(t_view))));
	v->mlx = mlx_init();
	v->orig = ptable;
	v->pwidth = (dim) ? dim[0] : 0;
	v->pheight = (dim) ? dim[1] : 0;
	(v->win_size)[0] = 1000;
	(v->win_size)[1] = 1000;
	v->win = mlx_new_window(v->mlx,
			(v->win_size)[0], (v->win_size)[1], name);
	v->x_rot = 0.0f;
	v->y_rot = 0.0f;
	v->z_rot = 0.0f;
	align_points(v, "local");
	find_zrange(v);
	set_scale(v);
	xy_offset(v);
	v->projected = NULL;
	v->perspective = 0;
	return (v);
}
