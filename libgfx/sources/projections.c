/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_basic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 15:56:15 by bslakey           #+#    #+#             */
/*   Updated: 2017/02/15 06:54:54 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libgfx.h"
#include <stdio.h>

void			bzero_matrix(float (*matrix)[4][4])
{
	int			i;
	int			j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			(*matrix)[i][j] = 0;
	}
}

void			identity_matrix(float (*matrix)[4][4])
{
	bzero_matrix(matrix);
	(*matrix)[0][0] = 1;
	(*matrix)[1][1] = 1;
	(*matrix)[2][2] = 1;
	(*matrix)[3][3] = 1;
}

void			orthographic_projection(float (*projection_matrix)[4][4])
{
	bzero_matrix(projection_matrix);
	(*projection_matrix)[0][0] = 1;
	(*projection_matrix)[1][1] = 1;
	(*projection_matrix)[2][2] = 1;
	(*projection_matrix)[3][3] = 1;
}

void			perspective_projection(t_view *world)
{
	int			i;
	int			j;
	t_point		*temp;

	i = -1;
	while (++i < world->pheight)
	{
		j = -1;
		while (++j < world->pwidth)
		{
			temp = (world->orig)[i][j];
			temp->x = (temp->x) / (temp->z);
			temp->y = (temp->y) / (temp->z);
		}
	}
}
