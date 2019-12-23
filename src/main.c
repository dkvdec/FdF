/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheredat <dheredat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 16:12:01 by dheredat          #+#    #+#             */
/*   Updated: 2019/12/23 16:57:59 by dheredat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	get_win(void)
{
	t_win.mlx_ptr = mlx_init();
	t_win.win_ptr = mlx_new_window(t_win.mlx_ptr, WIDTH, LENGTH, "mlx 42");
	t_win.mid_x = WIDTH / 2;
	t_win.mid_y = LENGTH / 2;
	if (!(t_win.img = mlx_new_image(t_win.mlx_ptr, WIDTH, LENGTH)))
		error_display("Error in mlx_new_image");
	if (!(t_win.data = (int *)mlx_get_data_addr(t_win.img, &(t_win.bbp),
	&(t_win.szln), &(t_win.end))))
		error_display("Error in mlx_get_data_addr");
}

void	global_zero(void)
{
	t_win.zoom = 0;
	t_win.angle_x = -PI / 6;
	t_win.angle_y = -PI / 3;
	t_win.angle_z = 0.0;
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*pnt;

	if (argc == 1)
		error_display("WE NEED MORE MAPS!!!");
	else if (argc == 2)
	{
		if (((fd = open(argv[1], O_RDONLY)) > 0) && (read(fd, pnt, 0) == 0))
		{
			global_zero();
			check_n_get_map(fd);
			close(fd);
			get_win();
			mlx_hook(t_win.win_ptr, 17, 0, close_window, (0));
			mlx_key_hook(t_win.win_ptr, deal_key, (void*)0);
			mlx_loop(t_win.mlx_ptr);
		}
		else
			error_display("WAKANDA SHIT IS THIS???");
	}
	else
		error_display("TLDR!!!");
	exit(0);
}
