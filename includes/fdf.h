/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 16:35:30 by bslakey           #+#    #+#             */
/*   Updated: 2017/02/15 07:07:34 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FDF_H
# define _FDF_H

# include "get_next_line.h"
# include "libgfx.h"

int				key_events(int keycode, t_view *view);
int				expose(t_view *view);
t_point			***parse_points(const char *file_name, int (*point_dim)[2]);
void			print_usage(void);
int				print_error(int err);
int				check_error(char ***char_map, int dim[2]);
#endif
