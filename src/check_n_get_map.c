/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_n_get_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheredat <dheredat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 21:37:46 by dheredat          #+#    #+#             */
/*   Updated: 2019/12/23 15:42:11 by dheredat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/fdf.h"

void	fill_line(char *line, int i)
{
	int		j;
	char	**words;
	char	**params;

	if (!(words = ft_strsplit(line, ' ')))
		error_display("Split malloc error");
	j = 0;
	while (j < t_map.max_x && words[j])
	{
		t_map.o_map[i][j].x = j;
		t_map.o_map[i][j].y = i;
		if (!(params = ft_strsplit(words[j], ',')))
			error_display("Split malloc error");
		t_map.o_map[i][j].z = ft_atoi(params[0]);
		if (params[1] != NULL)
			t_map.o_map[i][j].colour = ft_atoi_base(params[1] + 2, 16);
		else
			t_map.o_map[i][j].colour = LIME;
		free_strsplit(&params);
		j++;
	}
	free_strsplit(&words);
}

void	create_c_map(void)
{
	int i;

	if (!(t_map.c_map = (t_point**)malloc(sizeof(t_point*) * t_map.max_y)))
		error_display("Map malloc error");
	i = 0;
	while (i < t_map.max_y)
	{
		if (!(t_map.c_map[i] = (t_point*)malloc(sizeof(t_point) * t_map.max_x)))
			error_display("Map malloc error");
		i++;
	}
}

void	create_n_fill_map(char *buff)
{
	char	**lines;
	int		i;

	if (!(t_map.o_map = (t_point**)malloc(sizeof(t_point*) * t_map.max_y)))
		error_display("Map malloc error");
	i = 0;
	if (!(lines = ft_strsplit(buff, '\n')))
		error_display("Split malloc error");
	while (i < t_map.max_y)
	{
		if (!(t_map.o_map[i] = (t_point*)malloc(sizeof(t_point) * t_map.max_x)))
			error_display("Map malloc error");
		fill_line(lines[i], i);
		i++;
	}
	free_strsplit(&lines);
	get_max_z();
	get_map_mid();
	recount_coordinates();
	create_c_map();
	rotation();
}

void	check_n_get_map(int fd)
{
	int		data;
	char	buff[BUFFSIZE + 1];

	data = read(fd, buff, BUFFSIZE);
	buff[data] = '\0';
	check_map(buff);
	create_n_fill_map(buff);
}
