/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colour.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheredat <dheredat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 15:41:36 by dheredat          #+#    #+#             */
/*   Updated: 2019/12/23 16:57:40 by dheredat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

char	num(char c)
{
	if (47 < c && c < 58)
		return (c - 48);
	if (64 < c && c < 91)
		return (c - 55);
	if (96 < c && c < 123)
		return (c - 87);
	return (100);
}

int		sys(char c, int base)
{
	if (num(c) < base)
		return (1);
	else
		return (0);
}

int		ft_atoi_base(const char *s, int base)
{
	long int	nb;
	int			i;
	int			f;
	long int	pnb;

	i = 0;
	pnb = 0;
	f = 0;
	nb = 0;
	while ((s[i] >= '\t' && s[i] <= '\r') || s[i] == ' ')
		i++;
	if ((s[i] > 47 && s[i] < 58) || (s[i] > 64 && s[i] < 91) || (s[i] == '+'))
		f++;
	(s[i] > 96 && s[i] < 123) ? (f++) : (0);
	(s[i] == '-') ? (f--) : (0);
	((s[i] == '+') || (s[i] == '-')) ? (i++) : (0);
	while (sys(s[i], base) && s[i])
	{
		pnb = nb;
		nb = nb * base + num(s[i]);
		i++;
		if (pnb != nb / base)
			return ((f > 0) ? -1 : 0);
	}
	return (nb * f);
}
