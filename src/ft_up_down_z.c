/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_up_down_z.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshcherb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 18:11:57 by kshcherb          #+#    #+#             */
/*   Updated: 2017/02/19 17:12:48 by kshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_big_z(t_var *var)
{
	int	res;

	var->upz += 1;
	res = mlx_clear_window(var->mlx, var->win);
	ft_transform(var);
	ft_drawlines(var);
}

void	ft_small_z(t_var *var)
{
	int	res;

	var->upz -= 1;
	res = mlx_clear_window(var->mlx, var->win);
	ft_transform(var);
	ft_drawlines(var);
}

void	ft_iso(t_var *var)
{
	int res;

	var->alfa = 45;
	var->beta = 35;
	var->infobeta = var->beta;
	var->infoalpha = var->alfa;
	res = mlx_clear_window(var->mlx, var->win);
	ft_transform(var);
	ft_drawlines(var);
}

void	ft_up_down_z(int kcode, t_var *var)
{
	if (kcode == 43)
		ft_small_z(var);
	if (kcode == 47)
		ft_big_z(var);
	if (kcode == 34)
		ft_iso(var);
	ft_info(var);
}
