/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 17:13:55 by bslakey           #+#    #+#             */
/*   Updated: 2017/01/31 06:44:12 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char		***file_to_array(int fd, int (*dimensions)[2])
{
	int				i;
	char			***char_map;
	char			**temp2;
	char			*temp;
	char			*file_buffer;

	i = -1;
	MEM_GUARD((file_buffer = ft_strnew(0)));
	while (get_next_line(fd, &temp) > 0)
	{
		temp = ft_strjoin(file_buffer, temp);
		free(file_buffer);
		file_buffer = ft_strjoin(temp, "\n");
		free(temp);
		((*dimensions)[1])++;
	}
	MEM_GUARD((char_map = (char***)malloc(sizeof(char**) * (*dimensions)[1])));
	MEM_GUARD((temp2 = ft_strsplit(file_buffer, '\n')));
	while (++i < (*dimensions)[1])
		char_map[i] = ft_strsplit(temp2[i], ' ');
	while (char_map[0][(*dimensions)[0]])
		((*dimensions)[0])++;
    (*dimensions)[0] += ((*dimensions)[0] == 0) ? 1 : 0;
	char_map[(*dimensions)[1]] = 0;
	return (char_map);
}

t_point		***strmap_to_pointmap(char ***char_map, int dim[2])
{
	int				y;
	int				x;
	t_point			***point_map;

	y = -1;
	MEM_GUARD((point_map = create_empty_ptable(dim[0], dim[1])));
	while (++y < dim[1])
	{
		x = -1;
		while (++x < dim[0])
			point_map[y][x] = create_point(x, y, ft_atoi(char_map[y][x]));
	}
	return (point_map);
}

t_point		***parse_points(const char *file_name, int (*dimensions)[2])
{
	int			fd;
    char        temp[10];
	t_point		***points;
	char		***char_map;

	(*dimensions)[0] = 0;
	(*dimensions)[1] = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("Error:\n\tinvalid file given as input\n");
        close(fd);
		return (NULL);
	}
    if (0 >= read(fd, temp, 1))
    {
        print_error(-5);
        close(fd);
        return (NULL);
    }
	MEM_GUARD((char_map = file_to_array(fd, dimensions)));
	ERR_GUARD((print_error(check_error(char_map, (*dimensions)))), NULL);
	MEM_GUARD((points = strmap_to_pointmap(char_map, *dimensions)));
	close(fd);
	return (points);
}
