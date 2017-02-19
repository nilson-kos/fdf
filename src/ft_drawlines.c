/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshcherb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 18:47:28 by kshcherb          #+#    #+#             */
/*   Updated: 2017/02/19 18:32:48 by kshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

void		print_line(t_var *var)
{
	var->deltax = abs(var->x2 - var->x1);
	var->deltay = abs(var->y2 - var->y1);
	var->signx = var->x1 < var->x2 ? 1 : -1;
	var->signy = var->y1 < var->y2 ? 1 : -1;
	var->error = var->deltax - var->deltay;
	mlx_pixel_put(var->mlx, var->win, var->x2, var->y2, var->rgb);
	while ((var->x1 != var->x2) || (var->y1 != var->y2))
	{
		mlx_pixel_put(var->mlx, var->win, var->x1, var->y1, var->rgb);
		var->error2 = var->error * 2;
		if (var->error2 > -(var->deltay))
		{
			var->error -= var->deltay;
			var->x1 += var->signx;
		}
		if (var->error2 < var->deltax)
		{
			var->error += var->deltax;
			var->y1 += var->signy;
		}
	}
}

void		ft_drawvert(t_var *var)
{
	t_coord	*tmp;
	t_coord	*fnex;

	tmp = var->coord;
	while (tmp->next != NULL && var->i <= var->max)
	{
		fnex = tmp->next;
		while (var->yy < var->may)
		{
			var->y1 = tmp->y;
			var->x1 = tmp->x;
			var->rgb = tmp->rgb;
			while (++var->xx <= var->max)
				tmp = tmp->next;
			var->y2 = tmp->y;
			var->x2 = tmp->x;
			var->yy++;
			var->xx = -1;
			print_line(var);
		}
		var->yy = 0;
		tmp = fnex;
		var->i++;
	}
}

void		ft_one(t_var *var)
{
	mlx_pixel_put(var->mlx, var->win, var->coord->x, var->coord->y,
	var->coord->rgb);
}

void		ft_drawlines(t_var *var)
{
	t_coord	*tmp;
	int		cc;

	cc = 0;
	tmp = var->coord;
	if (var->may == 0 && var->max == 0)
		ft_one(var);
	while (tmp->next != NULL)
	{
		if (cc == var->max)
		{
			cc = 0;
			tmp = tmp->next;
		}
		var->y1 = tmp->y;
		var->x1 = tmp->x;
		var->rgb = tmp->rgb;
		var->y2 = tmp->next->y;
		var->x2 = tmp->next->x;
		print_line(var);
		tmp = tmp->next;
		cc++;
	}
	(var->max < 499) ? ft_drawvert(var) : (var->i = 0);
	var->i = 0;
}
