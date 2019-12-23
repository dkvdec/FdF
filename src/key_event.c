/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheredat <dheredat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 15:44:19 by dheredat          #+#    #+#             */
/*   Updated: 2019/12/23 17:15:54 by dheredat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	set_static_position(int key)
{
	if (key == kVK_ANSI_A)
	{
		t_win.angle_x = -PI / 6;
		t_win.angle_y = -PI / 3;
		t_win.angle_z = 0.0;
	}
	else if (key == kVK_ANSI_S)
	{
		t_win.angle_x = -PI / 3;
		t_win.angle_y = -PI / 3;
		t_win.angle_z = -PI / 4;
	}
	else if (key == kVK_ANSI_D)
	{
		t_win.angle_x = 0;
		t_win.angle_y = 0;
		t_win.angle_z = 0;
	}
	rotation();
}

void	rotate_direction2(int key)
{
	if (key == kVK_ANSI_Keypad6)
	{
		t_win.angle_y -= PI / 36;
		if (t_win.angle_y < -PI)
			t_win.angle_y += PI * 2;
	}
	else if (key == kVK_ANSI_Keypad7 || key == kVK_ANSI_Keypad9)
	{
		t_win.angle_z += PI / 36;
		if (t_win.angle_z > PI)
			t_win.angle_z += PI * 2;
	}
	else if (key == kVK_ANSI_Keypad1 || key == kVK_ANSI_Keypad3)
	{
		t_win.angle_z -= PI / 36;
		if (t_win.angle_z < -PI)
			t_win.angle_z += PI * 2;
	}
}

void	rotate_direction(int key)
{
	if (key == kVK_ANSI_Keypad8)
	{
		t_win.angle_x += PI / 36;
		if (t_win.angle_x > PI)
			t_win.angle_x -= PI * 2;
	}
	else if (key == kVK_ANSI_Keypad2)
	{
		t_win.angle_x -= PI / 36;
		if (t_win.angle_x < -PI)
			t_win.angle_x += PI * 2;
	}
	else if (key == kVK_ANSI_Keypad4)
	{
		t_win.angle_y += PI / 36;
		if (t_win.angle_y > PI)
			t_win.angle_y -= PI * 2;
	}
	else
		rotate_direction2(key);
	rotation();
}

void	move_center(int key)
{
	if (key == kVK_LeftArrow)
		t_win.mid_x += WIDTH / 32;
	else if (key == kVK_RightArrow)
		t_win.mid_x -= WIDTH / 32;
	else if (key == kVK_DownArrow)
		t_win.mid_y -= LENGTH / 36;
	else if (key == kVK_UpArrow)
		t_win.mid_y += LENGTH / 36;
	else if (key == kVK_ANSI_Keypad5)
	{
		t_win.mid_x = WIDTH / 2;
		t_win.mid_y = LENGTH / 2;
	}
}

int		deal_key(int key)
{
	if (key == kVK_Escape)
		exit(0);
	if ((key == kVK_ANSI_Equal || key == kVK_ANSI_KeypadPlus)
	&& t_win.zoom < 130)
		t_win.zoom += 1;
	if ((key == kVK_ANSI_Minus || key == kVK_ANSI_KeypadMinus)
	&& t_win.zoom > 1)
		t_win.zoom -= 1;
	if (key == kVK_ANSI_A || key == kVK_ANSI_S || key == kVK_ANSI_D)
		set_static_position(key);
	if (key == kVK_ANSI_Keypad1 || key == kVK_ANSI_Keypad2
	|| key == kVK_ANSI_Keypad3 || key == kVK_ANSI_Keypad4
	|| key == kVK_ANSI_Keypad6 || key == kVK_ANSI_Keypad7
	|| key == kVK_ANSI_Keypad8 || key == kVK_ANSI_Keypad9)
		rotate_direction(key);
	if (key == kVK_LeftArrow || key == kVK_RightArrow
	|| key == kVK_DownArrow || key == kVK_UpArrow
	|| key == kVK_ANSI_Keypad5)
		move_center(key);
	ft_bzero(t_win.data, WIDTH * LENGTH * sizeof(int));
	paint_map();
	mlx_put_image_to_window(t_win.mlx_ptr, t_win.win_ptr, t_win.img, 0, 0);
	return (0);
}
