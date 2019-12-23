/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheredat <dheredat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 14:43:14 by dheredat          #+#    #+#             */
/*   Updated: 2019/12/23 16:12:30 by dheredat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/fdf.h"

int		close_window(void *ptr)
{
	exit(0);
	ptr = NULL;
	return (0);
}

void	error_display(char *str)
{
	ft_printf("%s\n", str);
	exit(0);
}

int		ft_abs(int i)
{
	return ((i >= 0) ? i : -i);
}

void	brez_alg(void)
{
	while (t_p.x0 != t_p.x1 || t_p.y0 != t_p.y1)
	{
		if (t_p.x0 > 0 && t_p.x0 < WIDTH && t_p.y0 > 0 && t_p.y0 < LENGTH)
			t_win.data[t_p.x0 + t_p.y0 * WIDTH] = t_map.colour;
		if (t_p.d_x > t_p.d_y)
		{
			(t_p.x1 > t_p.x0) ? t_p.x0++ : t_p.x0--;
			t_p.er += t_p.d_y;
			if (t_p.er >= t_p.d_x)
			{
				(t_p.y1 > t_p.y0) ? t_p.y0++ : t_p.y0--;
				t_p.er -= t_p.d_x;
			}
		}
		else
		{
			(t_p.y1 > t_p.y0) ? t_p.y0++ : t_p.y0--;
			t_p.er += t_p.d_x;
			if (t_p.er >= t_p.d_y)
			{
				(t_p.x1 > t_p.x0) ? t_p.x0++ : t_p.x0--;
				t_p.er -= t_p.d_y;
			}
		}
	}
}

void	brez_alg2(int x0, int x1, int y0, int y1)
{
	t_p.d_x = ft_abs(x1 - x0);
	t_p.d_y = ft_abs(y1 - y0);
	t_p.er = 0;
	t_p.x0 = x0;
	t_p.x1 = x1;
	t_p.y0 = y0;
	t_p.y1 = y1;
	brez_alg();
}
