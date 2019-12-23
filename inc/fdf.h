/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheredat <dheredat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 17:52:30 by dheredat          #+#    #+#             */
/*   Updated: 2019/12/23 16:59:37 by dheredat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include "keys.h"
# include "../MinilibX/X11/mlx.h"
# include <fcntl.h>
# include "../ft_printf/inc/proto_vlst.h"

# define LEN 100
# define PI 3.14159265359
# define WIDTH 1600
# define LENGTH 1440

# define AQUA 0x00ffff
# define BLACK 0x000000
# define BLUE 0x0000ff
# define FUCHSIA 0xff00ff
# define GRAY 0x808080
# define GREEN 0x008000
# define LIME 0x00ff00
# define MAROON 0x800000
# define NAVY 0x000080
# define OLIVE 0x808000
# define PURPLE 0x800080
# define RED 0xff0000
# define SILVER 0xc0c0c0
# define TEAL 0x008080
# define WHITE 0xffffff
# define YELLOW 0xffff00

# define BUFFSIZE 5000000

typedef struct      s_point{
	double          x;
	double          y;
	double          z;
	int             colour;
}                   t_point;

struct              s_map
{
	t_point         **o_map;
	t_point			**c_map;
	int             max_x;
	int             max_y;
	int             max_z;
	double          mid_x;
	double          mid_y;
	double          mid_z;
	int				colour;
}                   t_map;

struct              s_win{
	void            *mlx_ptr;
	void            *win_ptr;
	int             mid_x;
	int             mid_y;
	void            *img;
	int				*data;
	int             bbp;
	int             szln;
	int             end;
	int				zoom;
	double			angle_x;
	double			angle_y;
	double			angle_z;
}                   t_win;

struct				s_p
{
	int				d_x;
	int				d_y;
	int				er;
	int				x0;
	int				x1;
	int				y0;
	int				y1;
}					t_p;


/*
** /////////////////////////// CHECK_N_GET_MAP ////////////////////////////
*/

/*
** CHECK_N_GET_MAP.C
*/

void 				fill_line(char *line, int i);
void				create_c_map(void);
void 				create_n_fill_map(char *buff);
void 				check_n_get_map(int fd);

/*
** CHECK_MAP.C
*/

void 				free_strsplit(char ***str);
void				check_hex(char *str);
void				word_check(char *str);
void 				check_line(char *line);
void 				check_map(char *buff);

/*
** COUNT_MAP.C
*/

void 				get_max_z(void);
void 				get_map_mid(void);
void 				recount_coordinates(void);
void				rotate_point(int i, int j);
void 				rotation(void);


/*
** /////////////////////////// PAINT_MAP_BLOCK ////////////////////////////
*/

/*
** KEY_EVENT.C
*/

void				set_static_position(int key);
void				rotate_direction2(int key);
void				rotate_direction(int key);
void				move_center(int key);
int					deal_key(int key, void *param);

/*
** PAINT.C
*/

void				paint_map(void);
void				paint_zz(void);
void				paint_mz(void);
void				paint_zm(void);
void				paint_mm(void);

/*
** TEST.C
*/

int					close_window(void *ptr);
void    			error_display(char *str);
void				brez_alg(void);
void				brez_alg2(int x0, int x1, int y0, int y1);

/*
** MAIN.C
*/

void				get_win(void);
void				global_zero(void);
char				num(char c);
int					sys(char c, int base);
int					ft_atoi_base(const char *s, int base);

#endif
