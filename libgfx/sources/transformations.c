/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 03:00:03 by bslakey           #+#    #+#             */
/*   Updated: 2017/02/15 07:18:36 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libgfx.h"

void				scale_view(t_view *view)
{
	float		scale_matrix[4][4];

	bzero_matrix(&scale_matrix);
	scale_matrix[0][0] = view->scale;
	scale_matrix[1][1] = view->scale;
	scale_matrix[2][2] = view->scale;
	scale_matrix[3][3] = 1;
	matrix_mult(view->transformation, scale_matrix, &(view->transformation));
}

void				rotate_x(float (*rotation_matrix)[4][4], t_view *view)
{
	bzero_matrix(rotation_matrix);
	(*rotation_matrix)[0][0] = 1;
	(*rotation_matrix)[1][1] = cos(view->x_rot);
	(*rotation_matrix)[1][2] = -sin(view->x_rot);
	(*rotation_matrix)[2][1] = sin(view->x_rot);
	(*rotation_matrix)[2][2] = cos(view->x_rot);
	(*rotation_matrix)[3][3] = 1;
}

void				rotate_y(float (*rotation_matrix)[4][4], t_view *view)
{
	bzero_matrix(rotation_matrix);
	(*rotation_matrix)[0][0] = cos(view->y_rot);
	(*rotation_matrix)[0][2] = sin(view->y_rot);
	(*rotation_matrix)[1][1] = 1;
	(*rotation_matrix)[2][0] = -sin(view->y_rot);
	(*rotation_matrix)[2][2] = cos(view->y_rot);
	(*rotation_matrix)[3][3] = 1;
}

void				rotate_z(float (*rotation_matrix)[4][4], t_view *view)
{
	bzero_matrix(rotation_matrix);
	(*rotation_matrix)[0][0] = cos(view->z_rot);
	(*rotation_matrix)[0][1] = -sin(view->z_rot);
	(*rotation_matrix)[1][0] = sin(view->z_rot);
	(*rotation_matrix)[1][1] = cos(view->z_rot);
	(*rotation_matrix)[2][2] = 1;
	(*rotation_matrix)[3][3] = 1;
}

void				rotate_all(t_view *view)
{
	float			rotx[4][4];
	float			roty[4][4];
	float			rotz[4][4];
	float			temp1[4][4];
	float			temp2[4][4];

	bzero_matrix(&temp1);
	bzero_matrix(&temp2);
	rotate_x(&rotx, view);
	rotate_y(&roty, view);
	rotate_z(&rotz, view);
	matrix_mult(view->transformation, rotx, &temp1);
	matrix_mult(temp1, roty, &temp2);
	matrix_mult(temp2, rotz, &view->transformation);
}
