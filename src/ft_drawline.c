/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshcherb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 18:47:28 by kshcherb          #+#    #+#             */
/*   Updated: 2017/02/12 20:07:46 by kshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

void		print_line(t_var *var, t_coord *tmp2)
{
		t_coord	*tmp;

		tmp = tmp2;
		printf("tmp->x = %d, tmp->next->x = %d, tmp->y = %d, tmp->next->y = %d\n", tmp->x , tmp->next->x, tmp->y , tmp->next->y);
		mlx_pixel_put(var->mlx, var->win, tmp->next->x * var->shiftX
	+ var->shiftX / 2, tmp->next->y * var->shiftY + var->shiftY / 2, 0x33FFFF);
		while ((tmp->x != tmp->next->x) || (tmp->y != tmp->next->y))
		{	
		printf("tmp->x = %d, tmp->next->x = %d, tmp->y = %d, tmp->next->y = %d\n", tmp->x, tmp->next->x, tmp->y, tmp->next->y);
			mlx_pixel_put(var->mlx, var->win, tmp->x * var->shiftX
		+ var->shiftX / 2, tmp->y * var->shiftY + var->shiftY / 2, 0x33FFFF);
			var->error2 = var->error * 2;
			if (var->error2 > -(var->deltaY))
			{
				var->error -= var->deltaY;
				tmp->x += var->signX;
			}
			if (var->error2 < var->deltaX)
			{
				var->error += var->deltaX;
				tmp->y += var->signY;
			}
		}
}

void		ft_drawline(t_var *var)
{
	t_coord	*tmp;

	tmp = var->coord;
	var->shiftX = 1200 / (var->max + 1);
	var->shiftY = 1200 / (var->may + 1);
	while (tmp->next != NULL)
	{
		var->deltaX = abs(tmp->next->x - tmp->x);
	   	var->deltaY = abs(tmp->next->y - tmp->y);
		var->signX = (tmp->x) < (tmp->next->x) ? 1 : -1;
		var->signY = (tmp->y) < (tmp->next->y) ? 1 : -1;
		var->error = var->deltaX - var->deltaY;	
		print_line(var, tmp);
		tmp = tmp->next;
	}
}	
