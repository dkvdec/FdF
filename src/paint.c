/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheredat <dheredat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 17:39:45 by dheredat          #+#    #+#             */
/*   Updated: 2019/12/22 20:59:02 by dheredat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/fdf.h"

void	paint_zz(void)
{
	int i;
	int j;

	i = 0;
	while (i < t_map.max_y)
	{
		j = 0;
		while (j < t_map.max_x)
		{
			t_map.colour = t_map.c_map[i][j].colour;
			if (i + 1 < t_map.max_y)
				brez_alg2(t_map.c_map[i][j].x * t_win.zoom + t_win.mid_x,
				t_map.c_map[i + 1][j].x * t_win.zoom + t_win.mid_x,
				t_map.c_map[i][j].y * t_win.zoom + t_win.mid_y,
				t_map.c_map[i + 1][j].y * t_win.zoom + t_win.mid_y);
			if (j + 1 < t_map.max_x)
				brez_alg2(t_map.c_map[i][j].x * t_win.zoom + t_win.mid_x,
				t_map.c_map[i][j + 1].x * t_win.zoom + t_win.mid_x,
				t_map.c_map[i][j].y * t_win.zoom + t_win.mid_y,
				t_map.c_map[i][j + 1].y * t_win.zoom + t_win.mid_y);
			j++;
		}
		i++;
	}
}

void	paint_mm(void)
{
	int i;
	int j;

	i = t_map.max_y - 1;
	while (i >= 0)
	{
		j = t_map.max_x - 1;
		while (j >= 0)
		{
			if (i - 1 >= 0 && (t_map.colour = t_map.c_map[i - 1][j].colour))
				brez_alg2(t_map.c_map[i][j].x * t_win.zoom + t_win.mid_x,
				t_map.c_map[i - 1][j].x * t_win.zoom + t_win.mid_x,
				t_map.c_map[i][j].y * t_win.zoom + t_win.mid_y,
				t_map.c_map[i - 1][j].y * t_win.zoom + t_win.mid_y);
			if (j - 1 >= 0 && (t_map.colour = t_map.c_map[i][j - 1].colour))
				brez_alg2(t_map.c_map[i][j].x * t_win.zoom + t_win.mid_x,
				t_map.c_map[i][j - 1].x * t_win.zoom + t_win.mid_x,
				t_map.c_map[i][j].y * t_win.zoom + t_win.mid_y,
				t_map.c_map[i][j - 1].y * t_win.zoom + t_win.mid_y);
			j--;
		}
		i--;
	}
}

void	paint_zm(void)
{
	int i;
	int j;

	i = 0;
	while (i < t_map.max_y)
	{
		j = t_map.max_x - 1;
		while (j >= 0)
		{
			if (i + 1 < t_map.max_y
			&& (t_map.colour = t_map.c_map[i][j].colour))
				brez_alg2(t_map.c_map[i][j].x * t_win.zoom + t_win.mid_x,
				t_map.c_map[i + 1][j].x * t_win.zoom + t_win.mid_x,
				t_map.c_map[i][j].y * t_win.zoom + t_win.mid_y,
				t_map.c_map[i + 1][j].y * t_win.zoom + t_win.mid_y);
			if (j - 1 >= 0 && (t_map.colour = t_map.c_map[i][j - 1].colour))
				brez_alg2(t_map.c_map[i][j].x * t_win.zoom + t_win.mid_x,
				t_map.c_map[i][j - 1].x * t_win.zoom + t_win.mid_x,
				t_map.c_map[i][j].y * t_win.zoom + t_win.mid_y,
				t_map.c_map[i][j - 1].y * t_win.zoom + t_win.mid_y);
			j--;
		}
		i++;
	}
}

void	paint_mz(void)
{
	int i;
	int j;

	i = t_map.max_y - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < t_map.max_x)
		{
			if (i - 1 >= 0 && (t_map.colour = t_map.c_map[i - 1][j].colour))
				brez_alg2(t_map.c_map[i][j].x * t_win.zoom + t_win.mid_x,
				t_map.c_map[i - 1][j].x * t_win.zoom + t_win.mid_x,
				t_map.c_map[i][j].y * t_win.zoom + t_win.mid_y,
				t_map.c_map[i - 1][j].y * t_win.zoom + t_win.mid_y);
			if (j + 1 < t_map.max_x
			&& (t_map.colour = t_map.c_map[i][j].colour))
				brez_alg2(t_map.c_map[i][j].x * t_win.zoom + t_win.mid_x,
				t_map.c_map[i][j + 1].x * t_win.zoom + t_win.mid_x,
				t_map.c_map[i][j].y * t_win.zoom + t_win.mid_y,
				t_map.c_map[i][j + 1].y * t_win.zoom + t_win.mid_y);
			j++;
		}
		i--;
	}
}

void	paint_map(void)
{
	if (((t_win.angle_x <= -0.0 && t_win.angle_x >= -PI)
	&& (t_win.angle_y <= 0.0 && t_win.angle_y > -PI / 2))
	|| ((t_win.angle_x >= 0.0 && t_win.angle_x <= PI)
	&& (t_win.angle_y >= PI / 2 && t_win.angle_y <= PI)))
		paint_zz();
	else if (((t_win.angle_x >= 0.0 && t_win.angle_x <= PI)
	&& (t_win.angle_y >= 0.0 && t_win.angle_y < PI / 2))
	|| ((t_win.angle_x <= -0.0 && t_win.angle_x >= -PI)
	&& (t_win.angle_y <= -PI / 2 && t_win.angle_y >= -PI)))
		paint_mm();
	else if (((t_win.angle_x <= -0.0 && t_win.angle_x >= -PI)
	&& (t_win.angle_y >= 0.0 && t_win.angle_y < PI / 2))
	|| ((t_win.angle_x >= 0.0 && t_win.angle_x <= PI)
	&& (t_win.angle_y <= -PI / 2 && t_win.angle_y >= -PI)))
		paint_zm();
	else if (((t_win.angle_x >= 0.0 && t_win.angle_x <= PI)
	&& (t_win.angle_y <= 0.0 && t_win.angle_y > -PI / 2))
	|| ((t_win.angle_x <= -0.0 && t_win.angle_x >= -PI)
	&& (t_win.angle_y >= PI / 2 && t_win.angle_y <= PI)))
		paint_mz();
}
