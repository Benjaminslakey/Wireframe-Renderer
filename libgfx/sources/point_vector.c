/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 18:11:10 by bslakey           #+#    #+#             */
/*   Updated: 2017/02/15 07:19:50 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libgfx.h"

void				align_points(t_view *v, const char *where)
{
	int				i;
	int				j;

	i = -1;
	while (++i < v->pheight)
	{
		j = -1;
		while (++j < v->pwidth)
		{
			if (!ft_strcmp(where, "local"))
			{
				((v->orig)[i][j])->x -= (v->pwidth / 2);
				((v->orig)[i][j])->y -= (v->pheight / 2);
			}
			else if (!ft_strcmp(where, "projected"))
			{
				((v->projected)[i][j])->x += ((v->pwidth / 2) * v->scale) +
					v->x_offset;
				((v->projected)[i][j])->y += ((v->pheight / 2) * v->scale) +
					v->y_offset;
			}
		}
	}
}

void				transform_allpoints(t_view *v)
{
	int				i;
	int				j;

	i = -1;
	while (++i < v->pheight)
	{
		j = -1;
		while (++j < v->pwidth)
		{
			(v->projected)[i][j] = transform_point((v->orig)[i][j],
					v->transformation);
			((v->projected)[i][j])->z = ((v->orig)[i][j])->z;
		}
	}
}

void				free_points(t_view *v)
{
	int				i;
	int				j;

	i = -1;
	while (++i < v->pheight)
	{
		j = -1;
		while (++j < v->pwidth)
			free((v->projected)[i][j]);
		free((v->projected)[i]);
	}
	free(v->projected);
	v->projected = NULL;
}
