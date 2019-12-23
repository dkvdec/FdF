/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LEGACY_DO_NO_PUSH.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheredat <dheredat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 21:31:55 by dheredat          #+#    #+#             */
/*   Updated: 2019/12/22 21:27:53 by dheredat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Bresenham's line algorithm
/* 
void    draw_line()
{}

void    map_make_line(char **line, int j)
{
	int i;
	t_point *curr;
	t_point *uppe;

	i = 0;
	if (t_map.head == NULL)
	{
		if (!(t_map.head = malloc(sizeof(t_point))))
			exit(0);
		t_map.head->right = NULL;
		t_map.head->bot = NULL;
		t_map.head->x = i;
		t_map.head->y = j;
		t_map.head->z = ft_atoi(line[i++]);
	}
	else
	{
		curr = t_map.head;
		while (curr->bot != NULL)
			curr = curr->bot;
		uppe = curr;
		if (!(curr->bot = malloc(sizeof(t_point))))
			exit(0);
		curr = curr->bot;
		curr->right = NULL;
		curr->bot = NULL;
		curr->x = i;
		curr->y = j;
		curr->z = ft_atoi(line[i++]);
	}
	while (line[i])
	{
		if (!(curr->right = malloc(sizeof(t_point))))
			exit(0);
		curr = curr->right;
		if (j > 0)
		{
			uppe = uppe->right;
			uppe->bot = curr;
		}
		curr->right = NULL;
		curr->bot = NULL;
		curr->x = i;
		curr->y = j;
		curr->z = ft_atoi(line[i++]);
	}
}

void draw_line(int x0, int x1, int y0, int y1, void *mlx_ptr, void *win_ptr)
{
	int dx = abs(x1 - x0);
	int dy = abs(y1 - y0);
	int er = 0;
	int der = dy;
	int y = y0;
	int diry = y1 - y0;
	if (diry > 0)
		diry = 1;
	if (diry < 0) 
		diry = -1;
	int x = x0;
	while (x != x1 && y != y1)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFF0000);
		er += der;
		if (er * 2 >= dx)
		{
			y += diry;
			er -= dx;
		}
		x++;
	}
}

void    map_make(char **lines)
{
	char **args;
	int i;
	int j;

	i = 0;
	while (lines[i])
	{
		args = ft_strsplit(lines[i],' ');
		map_make_line(args, i);
		j = 0;
		while(args[j])
			free(args[j++]);
		free(args);
		i++;
	}
	t_map.map_height = i;
}

void    get_map(int fd)
{
	char buff[BUFFSIZE + 1];
	char **lines;
	int data;

	data = read(fd, buff, BUFFSIZE);
	buff[data] = '\0';
	lines = ft_strsplit(buff, '\n');
	t_map.head = NULL;
	map_make(lines);
}

void    close_window(void *ptr)
{
	exit(0);
	ptr = NULL;
}

void    error_display(char *str)
{
	ft_printf("%s\n", str);
	exit(0);
}


void    get_win(void)
{
	t_win.mlx_ptr = mlx_init();
	t_win.win_ptr = mlx_new_window(t_win.mlx_ptr, WIDTH, LENGTH, "mlx 42");
	t_win.mid_x = WIDTH / 2;
	t_win.mid_y = LENGTH / 2;
	if (!(t_win.img = mlx_new_image(t_win.mlx_ptr, WIDTH, LENGTH)))
		error_display("Error in mlx_new_image");
	if (!(t_win.data = mlx_get_data_addr(t_win.img, &(t_win.bbp), &(t_win.szln), &(t_win.end))))
		error_display("Error in mlx_get_data_addr");
	mlx_hook(t_win.win_ptr, 17, 0, close_window, t_map.head);
	mlx_key_hook(t_win.win_ptr, deal_es)
}

int main(int argc, char **argv)
{
	int fd;
	char *pnt;

	if (argc == 1)
		ft_printf("WE NEED MORE MAPS!!!\n");
	else if (argc == 2)
	{
		if (((fd = open(argv[1], O_RDONLY)) > 0) && (read(fd, pnt, 0) == 0))
		{
			get_map(fd);
			close(fd);
			get_win();
		}
		else
			ft_printf("WAKANDA SHIT IS THIS???\n");
		
	}
	else
		ft_printf("TLDR!!!\n");    
	exit(0);
}
 */

/*

void	line_draw_test(void)
{
	void    *mlx_ptr;
	void    *win_ptr;
	int x,y;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "mlx 42");
	y = 0;
	while (y <= 500)
	{
		brez_alg(0, 500, 0, y, mlx_ptr, win_ptr);
		y += 10;
	}
	x = 500;
	while (x >= 0)
	{
		brez_alg(0, x, 0, 500, mlx_ptr, win_ptr);
		x -= 10;
	}
	//////////////////////////////////////////////
	x = 500;
	while (x <= 1000)
	{
		brez_alg(1000 , x, 1000, 500, mlx_ptr, win_ptr);
		x += 10;
	}
	y = 500;
	while (y <= 1000)
	{
		brez_alg(1000 , 500, 1000, y, mlx_ptr, win_ptr);
		y += 10;
	}
	////////////////////////////////////////////
	x = 0;
	while (x <= 500)
	{
		brez_alg(0 , x, 1000, 500, mlx_ptr, win_ptr);
		x += 10;
	}
	y = 500;
	while (y <= 1000)
	{
		brez_alg(0 , 500, 1000, y, mlx_ptr, win_ptr);
		y += 10;
	}
	////////////////////////////////////////////
	x = 1000;
	while (x >= 500)
	{
		brez_alg(1000 , x, 0, 500, mlx_ptr, win_ptr);
		x -= 10;
	}
	y = 0;
	while (y <= 500)
	{
		brez_alg(1000 , 500, 0, y, mlx_ptr, win_ptr);
		y += 10;
	}
	mlx_key_hook(win_ptr, deal_key, (void *) 0);
	mlx_loop(mlx_ptr);
}


/* if (t_win.angle_x <= 0 || t_win.angle_x > PI)
		paint_zz();
	else
		paint_mm(); */
	/* if (t_win.angle_y <= 0 || t_win.angle_y > PI)
		paint_zz();
	else
		paint_mm(); */
	/* if ((t_map.c_map[0][0].z == t_map.c_map[t_map.max_x - 1][t_map.max_y - 1].z 
	&& t_map.c_map[0][0].z < t_map.c_map[t_map.max_x - 1][0].z)
	|| (t_map.c_map[0][0].z == t_map.c_map[t_map.max_x - 1][0].z && t_map.c_map[0][0].z < t_map.c_map[t_map.max_x - 1][t_map.max_y - 1].z))
	{
		printf("additional zz\n");
		paint_zz();
	}
	else if ((t_map.c_map[t_map.max_x - 1][t_map.max_y - 1].z == t_map.c_map[0][t_map.max_y - 1].z && t_map.c_map[t_map.max_x - 1][t_map.max_y - 1].z < t_map.c_map[0][0].z)
	|| (t_map.c_map[t_map.max_x - 1][t_map.max_y - 1].z == t_map.c_map[t_map.max_x - 1][0].z && t_map.c_map[t_map.max_x - 1][t_map.max_y - 1].z < t_map.c_map[0][0].z))
	{
		printf("additional mm\n");
		paint_mm();
	}
	else if (t_map.c_map[0][0].z < t_map.c_map[t_map.max_x - 1][t_map.max_y - 1].z
	&& t_map.c_map[0][0].z < t_map.c_map[0][t_map.max_y - 1].z
	&& t_map.c_map[0][0].z < t_map.c_map[t_map.max_x - 1][0].z)
	{
		printf("regular zz\n");
		paint_zz();
	}
	else if (t_map.c_map[t_map.max_x - 1][t_map.max_y - 1].z < t_map.c_map[0][0].z
	&& t_map.c_map[t_map.max_x - 1][t_map.max_y - 1].z < t_map.c_map[0][t_map.max_y - 1].z
	&& t_map.c_map[t_map.max_x - 1][t_map.max_y - 1].z < t_map.c_map[t_map.max_x - 1][0].z)
	{
		printf("regular mm\n");
		paint_mm();
	}
	else if (t_map.c_map[0][t_map.max_y - 1].z < t_map.c_map[0][0].z
	&& t_map.c_map[0][t_map.max_y - 1].z < t_map.c_map[t_map.max_x - 1][0].z
	&& t_map.c_map[0][t_map.max_y - 1].z < t_map.c_map[t_map.max_x - 1][t_map.max_y - 1].z)
	{
		printf("regular zm\n");
		paint_zm();
	}
	else if (t_map.c_map[t_map.max_x - 1][0].z < t_map.c_map[0][0].z
	&& t_map.c_map[t_map.max_x - 1][0].z < t_map.c_map[0][t_map.max_y - 1].z
	&& t_map.c_map[t_map.max_x - 1][0].z < t_map.c_map[t_map.max_x - 1][t_map.max_y - 1].z)
	{
		printf("regular mz\n");
		paint_mz();
	}
	else
	{
		printf("additional zz\n");
		paint_zz();
	} */
	/* if ((((t_win.angle_x <= 0 && t_win.angle_x >= -PI) || (t_win.angle_x > PI && t_win.angle_x <= PI*2)) && (t_win.angle_y <= 0 && t_win.angle_y > -PI/2))
	|| ((t_win.angle_x <= 0 && t_win.angle_x >= -PI) && ((t_win.angle_y > PI*3/2 && t_win.angle_y <= PI*2))))
		paint_zz();
	else if ((((t_win.angle_x > 0 && t_win.angle_x < PI) || (t_win.angle_x < -PI && t_win.angle_x >= -PI*2)) && (t_win.angle_y > 0 && t_win.angle_y < PI/2))
	|| ((t_win.angle_x <= 0 && t_win.angle_x >= -PI) && ((t_win.angle_y <= -PI/2 && t_win.angle_y > -PI))))
		paint_mm();
	else if ((((t_win.angle_x < 0 && t_win.angle_x > -PI) || (t_win.angle_x > PI && t_win.angle_x <= PI*2)) && (t_win.angle_y > 0 && t_win.angle_y < PI/2))
	|| ((t_win.angle_x <= 0 && t_win.angle_x >= -PI) && ((t_win.angle_y < -PI*3/2 && t_win.angle_y >= -PI * 2) )))
		paint_zm();
	else if ((((t_win.angle_x > 0 && t_win.angle_x <= PI) || (t_win.angle_x < -PI && t_win.angle_x >= -PI*2)) && (t_win.angle_y <= 0 && t_win.angle_y > -PI/2))
	|| ((t_win.angle_x <= 0 && t_win.angle_x >= -PI) && ((t_win.angle_y <= PI && t_win.angle_y >= -PI*3/2) || (t_win.angle_y > PI && t_win.angle_y <= PI*3/2))))
		paint_mz();


void	test_map(void)
{
	int i;
	int j;

	i = 0;
	while (i < t_map.max_y)
	{
		j = 0;
		while (j < t_map.max_x)
		{
			if (i + 1 < t_map.max_y)
			brez_alg((t_map.c_map[i][j].x) * t_win.zoom + t_win.mid_x,
			(t_map.c_map[i + 1][j].x) * t_win.zoom + t_win.mid_x,
			(t_map.c_map[i][j].y) * t_win.zoom + t_win.mid_y, 
			(t_map.c_map[i + 1][j].y) * t_win.zoom + t_win.mid_y);
			if (j + 1 < t_map.max_x)
			brez_alg((t_map.c_map[i][j].x ) * t_win.zoom + t_win.mid_x,
			(t_map.c_map[i][j + 1].x ) * t_win.zoom + t_win.mid_x,
			(t_map.c_map[i][j].y) * t_win.zoom + t_win.mid_y, 
			(t_map.c_map[i][j + 1].y) * t_win.zoom + t_win.mid_y);
			j++;
		}
		i++;
	}
}

void	brez_alg(int x0, int x1, int y0, int y1)
{
	int d_x = abs(x1 - x0);
	int d_y = abs(y1 - y0);
	int er = 0;
	
	while (x0 != x1 || y0 != y1)
	{
		mlx_pixel_put(t_win.mlx_ptr, t_win.win_ptr, x0, y0, 0x00FF00);
		(d_x > d_y) ? ((x1 > x0) ? x0++ : x0--) : ((y1 > y0) ? y0++ : y0--);
		er += (d_x > d_y) ? d_y : d_x;
		if (er >= ((d_x > d_y) ? d_x : d_y))
		{
			(d_x > d_y) ? ((y1 > y0) ? y0++ : y0--) : ((x1 > x0) ? x0++ : x0--);
			er -= (d_x > d_y) ? d_x : d_y;
		}
	}    
}

void	brez_alg3(int x0, int x1, int y0, int y1)
{
	int d_x = abs(x1 - x0);
	int d_y = abs(y1 - y0);
	int er = 0;
	
	while (x0 != x1 || y0 != y1)
	{
		if (x0 > 0 && x0 < WIDTH && y0 > 0 && y0 < LENGTH)
			t_win.data[x0 + y0 * WIDTH] = t_map.colour;
		(d_x > d_y) ? ((x1 > x0) ? x0++ : x0--) : ((y1 > y0) ? y0++ : y0--);
		er += (d_x > d_y) ? d_y : d_x;
		if (er >= ((d_x > d_y) ? d_x : d_y))
		{
			(d_x > d_y) ? ((y1 > y0) ? y0++ : y0--) : ((x1 > x0) ? x0++ : x0--);
			er -= (d_x > d_y) ? d_x : d_y;
		}
	}
}

*/

