/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libgfx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 09:22:24 by bslakey           #+#    #+#             */
/*   Updated: 2017/02/16 03:19:12 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIBGFX_H
# define _LIBGFX_H

# include <stdlib.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"

/*
** pos x rotation: down arrow key
** neg x rotation: up arrow key
** pos y rotation: left arrow key
** neg y rotation: righ arrow key
** pos z rotation: Z
** neg z rotation: X
** translate left: A
** translate right: D
** translate up: W
** translate down: S
** reset projection: R
** exit FDF: ESC
*/

# define POS_XROT(keycode) (keycode == 125)
# define NEG_XROT(keycode) (keycode == 126)
# define POS_YROT(keycode) (keycode == 123)
# define NEG_YROT(keycode) (keycode == 124)
# define POS_ZROT(keycode) (keycode == 6)
# define NEG_ZROT(keycode) (keycode == 7)
# define ZOOM_IN(keycode) (keycode == 24)
# define ZOOM_OUT(keycode) (keycode == 27)
# define TRANS_LEFT(keycode) (keycode == 0)
# define TRANS_RIGHT(keycode) (keycode == 2)
# define TRANS_UP(keycode) (keycode == 13)
# define TRANS_DOWN(keycode) (keycode == 1)
# define PROJECTION(keycode) (keycode == 35)
# define RESET(keycode) (keycode == 15)
# define EXIT(keycode) (keycode == 53)

typedef struct			s_point
{
	float				x;
	float				y;
	float				z;
	float				w;
}						t_point;

typedef struct			s_view
{
	void				*mlx;
	void				*win;
	int					win_size[2];
	void				*img;
	char				*byte_map;
	int					bpp;
	int					line_size;
	int					endian;
	float				x_rot;
	float				y_rot;
	float				z_rot;
	float				scale;
	float				x_offset;
	float				y_offset;
	float				transformation[4][4];
	int					pheight;
	int					pwidth;
	t_point				***orig;
	t_point				***projected;
	int					perspective;
	float				zmin;
	float				zmax;
}						t_view;

t_point					***create_empty_ptable(int width, int height);
t_point					**create_point_row(char **line, int y);
t_point					*create_point(int x, int y, int z);
void					free_points(t_view *view);
t_view					*init_view(char *name, t_point ***points, int dim[2]);
void					set_scale(t_view *view);
void					find_zrange(t_view *view);
int						get_color(t_view *view, t_point p1);
void					bresenham_line(t_view *view, t_point p1, t_point p2);
void					draw_pixel(t_view *view, int x, int y, int rgb);
void					init_img_data(t_view *view);
void					draw_wireframe(t_view *view);
void					render_image(t_view *view);
void					refresh_render(t_view *view);
void					bzero_matrix(float (*matrix)[4][4]);
void					print_matrix(float m[4][4]);
void					matrix_mult(float m1[4][4], float m2[4][4],
								float (*dest)[4][4]);
void					rotate_x(float (*m)[4][4], t_view *world);
void					rotate_y(float (*m)[4][4], t_view *world);
void					rotate_z(float (*m)[4][4], t_view *world);
void					rotate_all(t_view *view);
void					scale_view(t_view *world);
t_point					*cross_product(t_point *v1, t_point *v2);
void					orthographic_projection(float
								(*projection_matrix)[4][4]);
void					perspective_projection(t_view *world);
t_point					*transform_point(t_point *p, float m1[4][4]);
void					align_points(t_view *v, const char *name);
void					transform_allpoints(t_view *world);
int						expose(t_view *view);
void					reset_view(t_view *view);
int						key_events(int keycode, t_view *view);
#endif
