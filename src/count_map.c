/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheredat <dheredat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 15:38:04 by dheredat          #+#    #+#             */
/*   Updated: 2019/12/23 15:38:55 by dheredat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/fdf.h"

void	get_max_z(void)
{
	int		i;
	int		j;
	float	max;

	i = 0;
	max = 0.0;
	while (i < t_map.max_y)
	{
		j = 0;
		while (j < t_map.max_x)
		{
			if (t_map.o_map[i][j].z > max)
				max = t_map.o_map[i][j].z;
			j++;
		}
		i++;
	}
	t_map.max_z = max;
}

void	get_map_mid(void)
{
	t_map.mid_x = t_map.max_x / 2.0;
	t_map.mid_y = t_map.max_y / 2.0;
	t_map.mid_z = t_map.max_z / 2.0;
}

void	recount_coordinates(void)
{
	int i;
	int j;

	i = 0;
	while (i < t_map.max_y)
	{
		j = 0;
		while (j < t_map.max_x)
		{
			t_map.o_map[i][j].x -= t_map.mid_x;
			t_map.o_map[i][j].y -= t_map.mid_y;
			t_map.o_map[i][j].z -= t_map.mid_z;
			j++;
		}
		i++;
	}
}

void	rotate_point(int i, int j)
{
	t_map.c_map[i][j].x = t_map.o_map[i][j].x;
	t_map.c_map[i][j].y = t_map.o_map[i][j].y *
	cos(t_win.angle_x) + t_map.o_map[i][j].z * sin(t_win.angle_x);
	t_map.c_map[i][j].z = t_map.o_map[i][j].z *
	cos(t_win.angle_x) - t_map.o_map[i][j].y * sin(t_win.angle_x);
	t_map.c_map[i][j].x = t_map.c_map[i][j].x *
	cos(t_win.angle_z) - t_map.c_map[i][j].y * sin(t_win.angle_z);
	t_map.c_map[i][j].y = t_map.c_map[i][j].y *
	cos(t_win.angle_z) - t_map.c_map[i][j].x * sin(t_win.angle_z);
	t_map.c_map[i][j].z = t_map.c_map[i][j].z;
	t_map.c_map[i][j].x = t_map.c_map[i][j].x *
	cos(t_win.angle_y) + t_map.c_map[i][j].z * sin(t_win.angle_y);
	t_map.c_map[i][j].y = t_map.c_map[i][j].y;
	t_map.c_map[i][j].z = t_map.c_map[i][j].z *
	cos(t_win.angle_y) - t_map.c_map[i][j].x * sin(t_win.angle_y);
	t_map.c_map[i][j].colour = t_map.o_map[i][j].colour;
}

void	rotation(void)
{
	int i;
	int j;

	i = 0;
	while (i < t_map.max_y)
	{
		j = 0;
		while (j < t_map.max_x)
		{
			rotate_point(i, j);
			j++;
		}
		i++;
	}
}
