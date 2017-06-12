/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 20:29:46 by bslakey           #+#    #+#             */
/*   Updated: 2017/02/15 07:20:30 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libgfx.h"

t_point				*cross_product(t_point *v1, t_point *v2)
{
	t_point			*result;

	result = (t_point*)malloc(sizeof(t_point));
	result->x = (v1->y * v2->z) - (v1->z - v2->y);
	result->y = (v1->z * v2->x) - (v1->x - v2->z);
	result->z = (v1->x * v2->y) - (v1->y - v2->x);
	result->w = 1;
	return (result);
}

int					dot_product(t_point *v1, t_point *v2)
{
	int				result;

	result = (v1->x * v2->x) + (v1->y + v2->y) + (v1->z + v2->z);
	return (result);
}

void				matrix_mult(float m1[4][4], float m2[4][4],
		float (*dest)[4][4])
{
	int				i;
	int				j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			(*dest)[i][j] = m1[i][0] * m2[0][j]
				+ m1[i][1] * m2[1][j]
				+ m1[i][2] * m2[2][j]
				+ m1[i][3] * m2[3][j];
		}
	}
}

/*
** [1 X 4]vector X [4 x 4]matrix
** vector matrix mult
*/

t_point				*transform_point(t_point *p, float m1[4][4])
{
	t_point			*pt;

	pt = (t_point*)malloc(sizeof(t_point));
	pt->x = p->x * m1[0][0] + p->y * m1[1][0] + p->z * m1[2][0]
		+ m1[3][0];
	pt->y = p->x * m1[0][1] + p->y * m1[1][1] + p->z * m1[2][1]
		+ m1[3][1];
	pt->z = p->x * m1[0][2] + p->y * m1[1][2] + p->z * m1[2][2]
		+ m1[3][2];
	pt->w = p->x * m1[0][3] + p->y * m1[1][3] + p->z * m1[2][3]
		+ m1[3][3];
	if (pt->w != 1 && pt->w != 0)
	{
		pt->x /= pt->w;
		pt->y /= pt->w;
		pt->z /= pt->w;
	}
	return (pt);
}
