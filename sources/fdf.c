/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 15:56:15 by bslakey           #+#    #+#             */
/*   Updated: 2017/02/15 07:23:44 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int					main(int argc, char **argv)
{
	int				dim[2];
	t_view			*view;

	view = NULL;
	if (argc == 1)
		print_usage();
	else if (argc >= 2 && argc < 5)
	{
		view = init_view("FdF", parse_points(argv[1], &dim), dim);
        print_usage();
		ERR_GUARD((view == NULL), -1);
		mlx_expose_hook(view->win, expose, view);
		mlx_hook(view->win, 2, 3, key_events, view);
		mlx_loop(view->mlx);
	}
	else
		print_error(-4);
	return (0);
}
