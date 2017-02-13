/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshcherb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 15:56:25 by kshcherb          #+#    #+#             */
/*   Updated: 2017/02/12 19:40:37 by kshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_ch_big(char **mass)
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

void		ft_ch_smal(char **mass, int max)
{
	int		x;

	x = 0;
	while (mass[x] != NULL)
		x++;
	if (x <= max)
	{
		ft_putstr("lines must be equal\n");
		exit(0);
	}
}

t_coord		*lst_new(int x, int y, int z)
{
	t_coord	*head;

	head = (t_coord *)malloc(sizeof(t_coord));
	head->z = z;
	head->x = x;
	head->y = y;
	head->rgb = 0xffffff;
	head->next = NULL;
	return (head);
}

t_coord		*push_end(t_coord *head, t_coord *lst)
{
	t_coord	*tmp;

	tmp = head;
	if (!head)
		return (lst);
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = lst;
	return (head);
}

t_var		*init_var(void)
{
	t_var	*var;

	var = (t_var *)malloc(sizeof(t_var));
	var->y = 0;
	var->x = 0;
	var->coord = NULL;
	return (var);
}

t_var		*ft_readfile(char *s)
{
	char	*line;
	char	**mass;
	t_var	*var;

	var = init_var();
	if ((var->fd = open(s, O_RDONLY)) == -1)
	{
		ft_putstr("can not open file\n");
		return (0);
	}
	while (get_next_line(var->fd, &line) > 0)
	{
		mass = ft_strsplit(line, ' ');
		(var->y == 0) ? var->max = ft_ch_big(mass) : ft_ch_smal(mass, var->max);
		while (var->x <= var->max)
		{
			var->coord = push_end(var->coord, lst_new(var->x,
						var->y, ft_atoi(mass[var->x])));
			//printf("z = %d, x = %d, y = %d\n", atoi(mass[var->x]), var->x, var->y);
			var->x++;
		}
		var->x = 0;
		var->y++;
	}
	var->may = var->y - 1;
	return (var);
}
