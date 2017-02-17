/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshcherb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 21:09:45 by kshcherb          #+#    #+#             */
/*   Updated: 2017/02/17 21:31:43 by kshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_minus(t_var *var)
{
	int		res;
	t_coord	*tmp;

	tmp = var->coord;
	var->zoomM -= 100;
	var->zoomM -= 100;
	res = mlx_clear_window(var->mlx, var->win);
	ft_drawlines(var);
}

void		ft_plus(t_var *var)
{
	int		res;
	t_coord	*tmp;

	tmp = var->coord;
	var->zoomP += 100;
	var->zoomP += 100;
	res = mlx_clear_window(var->mlx, var->win);
	ft_drawlines(var);
}

void		ft_zoom(int kcode, t_var *var)
{
	if (kcode == 27)
		ft_minus(var);
	if (kcode == 24)
		ft_plus(var);
}
