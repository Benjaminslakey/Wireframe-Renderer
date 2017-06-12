/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 15:56:15 by bslakey           #+#    #+#             */
/*   Updated: 2017/02/15 07:18:11 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libgfx.h"

void				init_img_data(t_view *view)
{
	view->img = mlx_new_image(view->mlx, (view->win_size)[0],
			(view->win_size)[1]);
	view->byte_map = mlx_get_data_addr(view->img, &(view->bpp),
			&(view->line_size), &(view->endian));
}

void				draw_pixel(t_view *view, int x, int y, int rgb)
{
	int				i;

	i = 0;
	if ((x < (view->win_size)[0] && x > 0) &&
			(y < (view->win_size)[1] && y > 0))
	{
		i = ((x * 4) + (y * view->line_size));
		(view->byte_map)[i] = rgb;
		(view->byte_map)[++i] = rgb >> 8;
		(view->byte_map)[++i] = rgb >> 16;
	}
}

void				render_image(t_view *v)
{
	v->projected = create_empty_ptable(v->pwidth, v->pheight);
	orthographic_projection(&(v->transformation));
	if (v->perspective)
		perspective_projection(v);
	rotate_all(v);
	scale_view(v);
	transform_allpoints(v);
	align_points(v, "projected");
	draw_wireframe(v);
	free_points(v);
}

void				refresh_render(t_view *view)
{
	init_img_data(view);
	render_image(view);
	mlx_put_image_to_window(view->mlx, view->win, view->img, 0, 0);
	mlx_destroy_image(view->mlx, view->img);
}
