/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:25:12 by bslakey           #+#    #+#             */
/*   Updated: 2017/01/31 06:44:04 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int					check_error(char ***char_map, int dim[2])
{
	int			i;
	int			j;

	i = -1;
	if (char_map == NULL)
		return (0);
	while (char_map[++i])
	{
		j = -1;
		while (char_map[i][++j])
		{
			if (!ft_str_isnum(char_map[i][j]))
			{
				ERR_GUARD((!(ft_atoi(char_map[i][j]) < 0)), -3);
			}
		}
		ERR_GUARD((j + 1 == dim[0]), -2);
	}
	ERR_GUARD((i + 1 == dim[1]), -2);
	return (0);
}

int					print_error(int err)
{
	if (err == -2)
		ft_putstr("Error:\n\tinvalid map_dimensions\n");
	else if (err == -3)
		ft_putstr("Error:\n\tinvalid file content format\n");
	else if (err == -4)
		ft_putstr("Error:\n\ttoo many inputs\n");
    else if (err == -5)
        ft_putstr("Error:\n\tfile given was empty\n");
	else
		return (0);
    ft_putstr(RED("\n\nWARNING!\n"));
    ft_putstr(RED("a single point does not constitute, a line or an object\n"));
    ft_putstr(RED(" that is representable as a wireframe, "));
    ft_putstr(RED("use pixel_put instead\n\n"));
	print_usage();
	return (1);
}

void				print_usage(void)
{
	ft_putstr("Usage: \n");
    ft_putstr("./FdF [filename]\n");
    ft_putstr("\x1b[32m");
    ft_putstr("\n\n\nprogram key commands\n");
    ft_putstr("ESC: escape key exits the program\n");
    ft_putstr("R: r resets the image projection back to the original\n");
    ft_putstr("◀ : left arrow key rotates around x clockwise\n");
    ft_putstr("▶ : right arrow key roates around x counter clockwise\n");
    ft_putstr("▲ : up uarrow key rotates around y clockwise\n");
    ft_putstr("▼ : down arrow key rotates aound y counter clockwise\n");
    ft_putstr("Z: Z key rotates around Z clockwise\n");
    ft_putstr("X: X key rotates around Z counter clockwise\n");
    ft_putstr("+: + key zooms in\n");
    ft_putstr("-: - key zooms out\n");
    ft_putstr("W: w key translates the object up\n");
    ft_putstr("A: A key translates the object left\n");
    ft_putstr("S: w key translates the object down\n");
    ft_putstr("D: w key translates the object right\n");
    ft_putstr(COLOR_RESET);
}
