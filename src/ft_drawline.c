/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshcherb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 18:47:28 by kshcherb          #+#    #+#             */
/*   Updated: 2017/02/14 21:15:57 by kshcherb         ###   ########.fr       */
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
	mlx_pixel_put(var->mlx, var->win, var->x2, var->y2, 0x33FFFF);
	while ((var->x1 != var->x2) || (var->y1 != var->y2))
	{
		mlx_pixel_put(var->mlx, var->win, var->x1, var->y1, 0x33FFFF);
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
	int		yy;
	int		xx;
	
	yy = 0;
	xx = 0;
	tmp = var->coord;
	while (tmp->next != NULL && var->i <= var->max)
	{
		fnex = tmp->next;
		while (yy <= var->may)
		{
			var->x1 = tmp->x * var->shiftX + var->shiftX / 2;
			var->y1 = tmp->y * var->shiftY + var->shiftY / 2;
			while (xx < var->max)
			{
				xx++;
				tmp = tmp->next;
			}
			ft_putstr("Aa");
			yy++;
			xx = 0;
			var->y2 = tmp->next->y * var->shiftY + var->shiftY / 2;
			var->x2 = tmp->next->x * var->shiftX + var->shiftX / 2;
			print_line(var);
		}
		yy = 0;
		tmp = fnex;
		var->i++;
	}
}

void		ft_drawlines(t_var *var)
{
	t_coord	*tmp;

	tmp = var->coord;
	var->shiftX = 1200 / (var->max + 1);
	var->shiftY = 1200 / (var->may + 1);
	while (tmp->next != NULL)
	{
		if (tmp->x == var->max)
			tmp = tmp->next;
		var->x1 = tmp->x * var->shiftX + var->shiftX / 2;
		var->x2 = tmp->next->x * var->shiftX + var->shiftX / 2;
		var->y1 = tmp->y * var->shiftY + var->shiftY / 2;
		var->y2 = tmp->next->y * var->shiftY + var->shiftY / 2;
		print_line(var);
		tmp = tmp->next;
	}
	ft_drawvert(var);
}
