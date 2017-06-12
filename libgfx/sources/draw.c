/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 15:56:15 by bslakey           #+#    #+#             */
/*   Updated: 2017/02/15 07:38:37 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libgfx.h"

void			draw_wireframe(t_view *view)
{
	int			r;
	int			c;
	t_point		*p1;
	t_point		*p2;

	r = -1;
	while (++r < view->pheight)
	{
		c = -1;
		while (++c < view->pwidth)
		{
			p1 = (view->projected)[r][c];
			if (c + 1 < view->pwidth)
			{
				p2 = (view->projected)[r][c + 1];
				bresenham_line(view, *p1, *p2);
			}
			if (r + 1 < view->pheight)
			{
				p2 = (view->projected)[r + 1][c];
				bresenham_line(view, *p1, *p2);
			}
		}
	}
}

int				get_color(t_view *view, t_point p1)
{
	int			color;
	float		range;
	float		grade;
	float		zdiff;

	zdiff = 0.0f;
	range = 0.0f;
	color = 0x00FFFFFF;
	while (p1.z + zdiff < view->zmax)
		zdiff += 0.1f;
	while (view->zmin + range < view->zmax)
		range += 0.1f;
	grade = (zdiff + 1.0f) / range;
	color = lround((float)color * (grade + 1.0));
	return (color);
}

/*
** the function driving_dir compares the x delta and y delta of the two
**  points which are meant to be the endpoints of a line. to be able to
**  draw lines properly, the algorith changes which axis is used as the
**  "driving axis"  and that axis is used to iterate foward to draw the
**  next point on the line. this is done effectively by swaping the
**  x and y of the point that is being moving foward, p1, if the primary
**  axis of change is not the x axis
*/

static int		driving_dir(t_point *p1, t_point *p2)
{
	float		temp;

	if (fabs(p2->x - p1->x) > fabs(p2->y - p1->y))
		return (0);
	temp = p1->y;
	p1->y = p1->x;
	p1->x = temp;
	temp = p2->y;
	p2->y = p2->x;
	p2->x = temp;
	return (1);
}

void			bresenham_line(t_view *view, t_point p1, t_point p2)
{
	float		delta[2];
	float		err[2];
	int			color;
	int			axis;

	delta[0] = fabs(p2.x - p1.x);
	delta[1] = fabs(p2.y - p1.y);
	err[1] = fabs(delta[1] / delta[0]);
	err[0] = -1.0;
	axis = driving_dir(&p1, &p2);
	while ((int)p1.x != (int)p2.x)
	{
		color = get_color(view, axis ? p1 : p2);
		draw_pixel(view, axis ? p1.y : p1.x, axis ? p1.x : p1.y, color);
		err[0] += err[1];
		if (err[0] >= 0.0)
		{
			p1.y += (p1.y > p2.y) ? -1 : 1;
			err[0] -= 1.0;
		}
		p1.x += (p1.x > p2.x) ? -1 : 1;
	}
}
