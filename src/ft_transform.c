/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshcherb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 16:01:09 by kshcherb          #+#    #+#             */
/*   Updated: 2017/02/19 17:33:51 by kshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_var		*ft_transform(t_var *var)
{
	t_coord	*tmp;
	int		x1;
	int		y1;
	int		z1;

	tmp = var->coord;
	var->shiftx = 1000 / (var->max + 1);
	var->shifty = 1000 / (var->may + 1);
	while (tmp != NULL)
	{
		x1 = (tmp->x0 * var->shiftx + var->shiftx / 2 - 600) * var->zoomm;
		y1 = (tmp->y0 * var->shifty + var->shifty / 2 - 600) * var->zoomm;
		z1 = (-tmp->z * var->upz) * var->zoomm;
		tmp->x = (((x1 * cos(B) + (-y1 * sin(A) + z1 * cos(A)) * sin(B))
		* cos(G) + (y1 * cos(A) + z1 * sin(A)) * sin(G) + 700) + var->sdvigx);
		tmp->y = ((-(x1 * cos(B) + (-y1 * sin(A) + z1 * cos(A)) * sin(B))
		* sin(G) + (y1 * cos(A) + z1 * sin(A)) * cos(G) + 700) + var->sdvigy);
		tmp = tmp->next;
	}
	return (var);
}
