/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshcherb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 21:09:45 by kshcherb          #+#    #+#             */
/*   Updated: 2017/02/19 17:34:25 by kshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_minus(t_var *var)
{
	int	res;

	var->zoomm += 0.08;
	var->infozoom = var->zoomm * 100;
	res = mlx_clear_window(var->mlx, var->win);
	ft_transform(var);
	ft_drawlines(var);
}

void	ft_plus(t_var *var)
{
	int	res;

	if (var->zoomm >= 0.08)
		var->zoomm -= 0.08;
	var->infozoom = var->zoomm * 100;
	res = mlx_clear_window(var->mlx, var->win);
	ft_transform(var);
	ft_drawlines(var);
}

void	ft_zoom(int kcode, t_var *var)
{
	if (kcode == 27)
		ft_plus(var);
	if (kcode == 24)
		ft_minus(var);
	ft_info(var);
}
