/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshcherb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 15:56:25 by kshcherb          #+#    #+#             */
/*   Updated: 2017/02/08 21:11:13 by kshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_check_bigger(char **mass)
{
	int		x;
	int		max;
	
	x = 0;
	max = 0;
	while (mass[x] != NULL)
	{
		max++;
		x++;
	}
	max--;
	return (max);
}

int			ft_check_smaller(char **mass, int max)
{
	int		x;
	
	x = 0;
	while (mass[x] != NULL)
		x++;
	if (x <= max)
	{
		ft_putstr("lines must be equal\n");
		return (0);
	}
	return (1);
}

int			ft_readfile(char *s)
{
	char 	*line;
	char	**mass;
	t_var	*var;
	t_coord	*coord;

	var->y = 0;
	var->x = 0;
	if ((var->fd = open(s, O_RDONLY)) == -1)
	{
		ft_putstr("can not open file\n");
		return (0);
	}
	while (get_next_line(var->fd, &line) > 0)
	{
		mass = ft_strsplit(line, ' ');
		if (var->y == 0)
			var->max = ft_check_bigger(mass);
		if (var->y != 0)
			if ((ft_check_smaller(mass, var->max)) == 0)
				return (0);
		while (var->x <= var->max)
		{
			//coord->z = atoi(mass[x]);
			//coord->x = x;
			//coord->y = y;
			//coord->rgb = 0xffffff;
			printf("z = %d, x = %d, y = %d\n", atoi(mass[var->x]), var->x, var->y);
			var->x++;
		}
		var->x = 0;
		var->y++;
	}
	return (1);
}
