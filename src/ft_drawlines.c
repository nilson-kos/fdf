/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshcherb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 18:47:28 by kshcherb          #+#    #+#             */
/*   Updated: 2017/02/17 18:45:48 by kshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

void		print_line(t_var *var)
{
	var->deltaX = abs(var->x2 - var->x1);
	var->deltaY = abs(var->y2 - var->y1);
	var->signX = var->x1 < var->x2 ? 1 : -1;
	var->signY = var->y1 < var->y2 ? 1 : -1;
	var->error = var->deltaX - var->deltaY;
	mlx_pixel_put(var->mlx, var->win, var->x2, var->y2, var->rgb);
	while ((var->x1 != var->x2) || (var->y1 != var->y2))
	{
		mlx_pixel_put(var->mlx, var->win, var->x1, var->y1, var->rgb);
		var->error2 = var->error * 2;
		if (var->error2 > -(var->deltaY))
		{
			var->error -= var->deltaY;
			var->x1 += var->signX;
		}
		if (var->error2 < var->deltaX)
		{
			var->error += var->deltaX;
			var->y1 += var->signY;
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

void		ft_drawlines(t_var *var)
{
	t_coord	*tmp;
	int		cc;

	cc = 0;
	tmp = var->coord;
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
	ft_drawvert(var);
	var->i = 0;
}
