/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshcherb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 15:56:25 by kshcherb          #+#    #+#             */
/*   Updated: 2017/02/19 17:47:12 by kshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord		*lst_new(int x, int y, int z, int rgb)
{
	t_coord	*head;

	head = (t_coord *)malloc(sizeof(t_coord));
	head->z = z;
	head->x = x;
	head->y = y;
	head->x0 = x;
	head->y0 = y;
	head->rgb = rgb;
	head->rgb0 = rgb;
	head->next = NULL;
	return (head);
}

t_coord		*push_end(t_coord *head, t_coord *lst)
{
	lst->next = head;
	return (lst);
}

t_var		*init_var(void)
{
	t_var	*var;

	var = (t_var *)malloc(sizeof(t_var));
	var->y = 0;
	var->x = 0;
	var->i = 0;
	var->xx = -1;
	var->yy = 0;
	var->upz = 1;
	var->zoomm = 1;
	var->zoomp = 0;
	var->coord = NULL;
	var->sdvigx = 0;
	var->sdvigy = 0;
	var->alfa = 50;
	var->beta = 20;
	var->gama = 1;
	var->shifttxt = 5;
	var->color = 666;
	var->infozoom = 100;
	var->infoalpha = var->alfa;
	var->infobeta = var->beta;
	return (var);
}

void		print_error(void)
{
	ft_putstr("can not open file\n");
	exit(0);
}

t_var		*ft_readfile(char *s)
{
	char	*line;
	char	**mass;
	t_var	*var;

	var = init_var();
	if ((var->fd = open(s, O_RDONLY)) == -1)
		print_error();
	while (get_next_line(var->fd, &line) > 0)
	{
		mass = ft_strsplit(line, ' ');
		(var->y == 0) ? var->max = ft_ch_big(mass) : ft_ch_smal(mass, var->max);
		while (var->x <= var->max)
		{
			var->coord = push_end(var->coord, lst_new(var->x,
						var->y, ft_atoi(mass[var->x]), (ft_strchr(mass[var->x]
						, 'x') != NULL) ? ft_atoi_base(ft_strchr(mass[var->x]
						, 'x') + 1, 16) : 0x00FFFFFF));
			var->x++;
		}
		var->x = 0;
		var->y++;
	}
	var->may = var->y - 1;
	return (var);
}
