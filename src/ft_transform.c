/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshcherb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 16:01:09 by kshcherb          #+#    #+#             */
/*   Updated: 2017/02/17 21:21:07 by kshcherb         ###   ########.fr       */
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
	var->alfa = 45;
	var->beta = 15;
	var->gama = 0;
	var->shiftX = 1000 / (var->max + 1);
	var->shiftY = 1000 / (var->may + 1);
	while (tmp != NULL)
	{
		x1 = tmp->x * var->shiftX + var->shiftX / 2 - var->zoomM;
		y1 = tmp->y * var->shiftY + var->shiftY / 2 - var->zoomM;
		z1 = -tmp->z * var->upz;
		tmp->x = (x1 * cos(B) + (-y1 * sin(A) + z1 * cos(A)) * sin(B)) * cos(G)
		+ (y1 * cos(A) + z1 * sin(A)) * sin(G) + var->zoomP;
		tmp->y = -(x1 * cos(B) + (-y1 * sin(A) + z1 * cos(A)) * sin(B)) * sin(G)
		+ (y1 * cos(A) + z1 * sin(A)) * cos(G) + var->zoomP;
		tmp = tmp->next;
	}
	return (var);
}
