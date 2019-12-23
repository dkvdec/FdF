/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheredat <dheredat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 15:36:13 by dheredat          #+#    #+#             */
/*   Updated: 2019/12/23 15:42:58 by dheredat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/fdf.h"

void	free_strsplit(char ***str)
{
	int i;

	i = 0;
	while ((*str)[i])
	{
		free((*str)[i]);
		(*str)[i] = NULL;
		i++;
	}
	free(*str);
	*str = NULL;
}

void	check_hex(char *str)
{
	int i;

	i = 1;
	if (str[0] != '0' || str[1] != 'x')
		error_display("Bad colour");
	while (str[++i])
		if (!((str[i] >= 48 && str[i] <= 57)
		|| (str[i] >= 65 && str[i] <= 70)
		|| (str[i] >= 97 && str[i] <= 102)))
			error_display("Bad colour");
}

void	word_check(char *str)
{
	char	**point;
	int		i;

	if (!(point = ft_strsplit(str, ',')))
		error_display("Split malloc error");
	i = -1;
	while (point[0][++i])
		if (!(ft_isdigit(point[0][i])))
			error_display("Bad map content error");
	if (point[1] == NULL)
	{
		free_strsplit(&point);
		return ;
	}
	else
		check_hex(point[1]);
	if (point[2] != NULL)
	{
		free_strsplit(&point);
		error_display("Bad map content error");
	}
	free_strsplit(&point);
}

void	check_line(char *line)
{
	int		i;
	char	**words;

	if (!(words = ft_strsplit(line, ' ')))
		error_display("Split malloc error");
	i = 0;
	while (words[i])
	{
		word_check(words[i]);
		i++;
	}
	if (t_map.max_x == 0)
		t_map.max_x = i;
	else if (t_map.max_x != i)
		error_display("Wrong map size");
	free_strsplit(&words);
}

void	check_map(char *buff)
{
	char	**lines;
	int		i;

	if (!(lines = ft_strsplit(buff, '\n')))
		error_display("Split malloc error");
	i = 0;
	while (lines[i])
	{
		check_line(lines[i]);
		i++;
	}
	t_map.max_y = i;
	free_strsplit(&lines);
}
